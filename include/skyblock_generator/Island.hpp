#pragma once

#include <mcpp/mcpp.h>
#include <cstdint>
#include <array>
#include <utility>
#include <string>
#include <vector>

namespace skyblock_generator {
    class Island {
    public:
        // Construct an Island helper.
        // width/length/height: island dimensions in blocks relative to `basepoint`.
        // basepoint: world origin coordinate for island placement.
        // mc: reference to an active Minecraft connection used for commands.
        Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc);
        void teleportToIsland() const;
        // Create the island in the world (issues block-placement commands).
        void createIsland();
        // Remove the island by replacing stored block positions with air.
        void removeIsland();
        // Returns true if the islandBlockCoords vector contains blocks
        // (i.e. island has been created and tracked in memory).
        bool islandExists() const;

    private:
        // Helper that builds an L-shaped island row at depth `z` with given width.
        void createLShapeIsland(std::uint8_t z, std::uint8_t width);
        // Set a single block at `basepoint + coord` to `block`.
        void setIslandBlock(mcpp::Coordinate coord, mcpp::BlockType block) const;
        // Place a chest and populate it via Minecraft `item replace` commands.
        void placeChestWithContents(mcpp::Coordinate chestCoord, const std::array<std::pair<std::string, std::string>, 7>& contents);
        // Plant a sapling and assist its growth (temporary helper blocks).
        void placeTree(mcpp::Coordinate treeCoord);
        // Internal helper to place temporary blocks that help tree generation.
        void setTreeHelperBlocks(mcpp::Coordinate treeCoord, mcpp::BlockType block) const;
        // Wrapper for setting `random_tick_speed` gamerule.
        void setRandomTickSpeed(const std::string& speed) const;
        // Wrapper for setting item despawn age with a data merge command.
        void setItemDespawnTime(const std::string& seconds) const;

        std::uint8_t width{};
        std::uint8_t length{};
        std::uint8_t height{};
        mcpp::Coordinate basepoint{};
        mcpp::MinecraftConnection& mc;
        std::vector<mcpp::Coordinate> islandBlockCoords{};
    };
}
