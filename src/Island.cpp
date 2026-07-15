#include <skyblock_generator/Island.hpp>
#include <mcpp/mcpp.h>
#include <cstdint>
#include <vector>
#include <array>
#include <utility>
#include <string>
#include <thread>
#include <chrono>
#include <format>

// Implementation of the `Island` helper that issues commands to the
// `mcpp::MinecraftConnection` in order to create and remove a simple
// skyblock-style island.

namespace skyblock_generator {
    // Initialise island metadata and reserve an estimated vector capacity
    // to avoid frequent reallocations when tracking placed blocks.
    Island::Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc)
        : width{ width }, length{ length }, height{ height }, basepoint{ basepoint }, mc{ mc } {
        islandBlockCoords.reserve(width * length * height - width / 2 * length / 2 * height);
    }

    // Teleport the player near the island basepoint so they can observe
    // the creation process. Offset values are deliberately small constants.
    void Island::teleportToIsland() const {
        mc.setPlayerPosition({ basepoint.x + 10, basepoint.y + 10, basepoint.z + 10 });
    }

    // Build the island row-by-row. The island is composed of L-shaped
    // cross-sections; the second half uses a narrower width to vary shape.
    void Island::createIsland() {
        for (std::uint8_t z = 0; z < length; ++z) {
            if (z < length / 2) {
                createLShapeIsland(z, width);
            }
            else {
                createLShapeIsland(z, width / 2);
            }
        }
        // Default chest contents placed in a chest on the island.
        std::array<std::pair<std::string, std::string>, 7> chestContents{
            std::make_pair("ice", "2"),
            std::make_pair("lava_bucket", "1"),
            std::make_pair("obsidian", "10"),
            std::make_pair("sugar_cane", "1"),
            std::make_pair("melon_slice", "1"),
            std::make_pair("pumpkin_seeds", "1"),
            std::make_pair("birch_sapling", "1"),
        };
        placeChestWithContents({ width - 1, height, length / 4 }, chestContents);
        placeTree({ 0, height, length - 1 });
    }

    // Construct an L-shaped cross-section at depth `z`.
    // Lower layers use `DIRT` while the top layer uses `GRASS`.
    void Island::createLShapeIsland(std::uint8_t z, std::uint8_t width) {
        mcpp::BlockType dirtBlock{ mcpp::Blocks::DIRT };
        mcpp::BlockType grassBlock{ mcpp::Blocks::GRASS };
        for (std::uint8_t x = 0; x < width; ++x) {
            for (std::uint8_t y = 0; y < height; ++y) {
                mcpp::Coordinate islandBlockCoord{ x, y, z };
                if (y < height - 1) {
                    islandBlockCoords.push_back(islandBlockCoord);
                    setIslandBlock(islandBlockCoord, dirtBlock);
                }
                else {
                    islandBlockCoords.push_back(islandBlockCoord);
                    setIslandBlock(islandBlockCoord, grassBlock);
                }
            }
        }
    }

    // Remove the island by replacing each tracked block with AIR and
    // clearing the tracked coordinates vector.
    void Island::removeIsland() {
        for (const auto& coord : islandBlockCoords) {
            setIslandBlock(coord, mcpp::Blocks::AIR);
        }
        islandBlockCoords.clear();
    }

    // Check whether an island has been created (based on the tracked coords).
    bool Island::islandExists() const {
        return !islandBlockCoords.empty();
    }

    // Place a block at `basepoint + coord`.
    void Island::setIslandBlock(mcpp::Coordinate coord, mcpp::BlockType block) const {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mc.setBlock(basepoint + coord, block);
    }

    // Place a chest at the given coordinate and populate slots using
    // `item replace` commands.
    void Island::placeChestWithContents(mcpp::Coordinate chestCoord, const std::array<std::pair<std::string, std::string>, 7>& chestContents) {
        mc.doCommand(std::format("setblock {} {} {} chest[facing=west]", basepoint.x + chestCoord.x, basepoint.y + chestCoord.y, basepoint.z + chestCoord.z));
        std::uint8_t chestSlotIndex{ 0 };
        for (const auto& [item, count] : chestContents) {
            mc.doCommand(std::format("item replace block {} {} {} container.{} with {} {}", basepoint.x + chestCoord.x, basepoint.y + chestCoord.y, basepoint.z + chestCoord.z, chestSlotIndex++, item, count));
        }
        islandBlockCoords.push_back(chestCoord);
    }

    // Plant a sapling and temporarily tweak tick/despawn rules so the tree
    // grows quickly. After a short wait the game rules are restored and
    // helper blocks removed.
    void Island::placeTree(mcpp::Coordinate treeCoord) {
        setTreeHelperBlocks(treeCoord, mcpp::Blocks::STONE);
        setIslandBlock(treeCoord, mcpp::Blocks::OAK_SAPLING);
        setRandomTickSpeed("20000");
        setItemDespawnTime("1");
        std::this_thread::sleep_for(std::chrono::seconds(10));
        setRandomTickSpeed("3");
        setItemDespawnTime("6000");
        setTreeHelperBlocks(treeCoord, mcpp::Blocks::AIR);
        for (std::uint8_t y = 0; y < 5; ++y) {
            islandBlockCoords.push_back({ treeCoord.x, treeCoord.y + y, treeCoord.z });
        }
    }

    // Place or remove helper blocks around the sapling to guide growth.
    void Island::setTreeHelperBlocks(mcpp::Coordinate treeCoord, mcpp::BlockType block) const {
        setIslandBlock({ treeCoord.x - 1, treeCoord.y + 1, treeCoord.z }, block);
        setIslandBlock({ treeCoord.x - 1, treeCoord.y + 2, treeCoord.z }, block);
        setIslandBlock({ treeCoord.x, treeCoord.y + 2, treeCoord.z - 1 }, block);
        setIslandBlock({ treeCoord.x + 1, treeCoord.y + 2, treeCoord.z }, block);
        setIslandBlock({ treeCoord.x, treeCoord.y + 2, treeCoord.z + 1 }, block);
        setIslandBlock({ treeCoord.x, treeCoord.y + 8, treeCoord.z }, block);
    }

    // Set the server `random_tick_speed` gamerule. Value should be a numeric
    // string (e.g. "3").
    void Island::setRandomTickSpeed(const std::string& speed) const {
        mc.doCommand("gamerule random_tick_speed " + speed);
    }

    // Adjust the `Age` data field on item entities to control despawn timing.
    void Island::setItemDespawnTime(const std::string& seconds) const {
        mc.doCommand("execute as @e[type=item] run data merge entity @s {Age:" + seconds + "}");
    }
}
