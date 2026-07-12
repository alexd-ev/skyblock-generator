#include <skyblock_generator/Island.hpp>
#include <thread>

namespace skyblock_generator {
    Island::Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc)
        : width{ width }, length{ length }, height{ height }, basepoint{ basepoint }, mc{ mc } {
        islandBlocks.reserve(width * length * height - width / 2 * length / 2 * height);
    }

    void Island::teleportToIsland() {
        mc.setPlayerPosition({ basepoint.x, basepoint.y + 10, basepoint.z });
    }

    void Island::createIsland() {
        for (std::uint8_t z = 0; z < length; ++z) {
            if (z < length / 2) {
                createLShapeIsland(z, width);
            }
            else {
                createLShapeIsland(z, width / 2);
            }
        }
        std::array<std::pair<std::string, int>, 7> chestContents{
            std::make_pair("ice", 2),
            std::make_pair("lava_bucket", 1),
            std::make_pair("obsidian", 10),
            std::make_pair("sugar_cane", 1),
            std::make_pair("melon_slice", 1),
            std::make_pair("pumpkin_seeds", 1),
            std::make_pair("birch_sapling", 1),
        };
        addChestWithContents({ width - 1, height, length / 4 }, chestContents);
    }

    void Island::createLShapeIsland(std::uint8_t z, std::uint8_t width) {
        mcpp::BlockType dirtBlock{ mcpp::Blocks::DIRT };
        mcpp::BlockType grassBlock{ mcpp::Blocks::GRASS };
        for (std::uint8_t x = 0; x < width; ++x) {
            for (std::uint8_t y = 0; y < height; ++y) {
                mcpp::Coordinate islandBlockCoord{ x, y, z };
                if (y < height - 1) {
                    islandBlocks.push_back({ islandBlockCoord, dirtBlock });
                    setIslandBlock(islandBlockCoord, dirtBlock);
                }
                else {
                    islandBlocks.push_back({ islandBlockCoord, grassBlock });
                    setIslandBlock(islandBlockCoord, grassBlock);
                }
            }
        }
    }

    void Island::destroyIsland() {
        for (const auto& [coord, block] : islandBlocks) {
            setIslandBlock(coord, mcpp::Blocks::AIR);
        }
    }

    void Island::setIslandBlock(mcpp::Coordinate coord, mcpp::BlockType block) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mc.setBlock(basepoint + coord, block);
    }

    void Island::addChestWithContents(mcpp::Coordinate chestCoord, const std::array<std::pair<std::string, int>, 7>& contents) {
        mc.doCommand("setblock " + std::to_string(basepoint.x + chestCoord.x) + " " + std::to_string(basepoint.y + chestCoord.y) + " " + std::to_string(basepoint.z + chestCoord.z) + " chest[facing=west]");
        std::uint8_t chestSlotIndex{ 0 };
        for (const auto& [item, count] : contents) {
            mc.doCommand("item replace block " + std::to_string(basepoint.x + chestCoord.x) + " " + std::to_string(basepoint.y + chestCoord.y) + " " + std::to_string(basepoint.z + chestCoord.z) + " container." + std::to_string(chestSlotIndex++) + " with " + item + " " + std::to_string(count));
        }
    }
}
