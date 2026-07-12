#pragma once

#include <mcpp/mcpp.h>

namespace skyblock_generator {
    class Island {
    public:
        Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc);
        void teleportToIsland();
        void createIsland();
        void destroyIsland();

    private:
        void createLShapeIsland(std::uint8_t x, std::uint8_t length);
        void setIslandBlock(mcpp::Coordinate coord, mcpp::BlockType block);
        void placeChestWithContents(mcpp::Coordinate chestCoord, const std::array<std::pair<std::string, std::string>, 7>& contents);
        void placeTree(mcpp::Coordinate treeCoord);
        void setTreeHelperBlocks(mcpp::Coordinate treeCoord, mcpp::BlockType block);
        void setRandomTickSpeed(const std::string& speed);

        std::uint8_t width{};
        std::uint8_t length{};
        std::uint8_t height{};
        mcpp::Coordinate basepoint{};
        mcpp::MinecraftConnection& mc;
        std::vector<mcpp::Coordinate> islandBlockCoords{};
    };
}
