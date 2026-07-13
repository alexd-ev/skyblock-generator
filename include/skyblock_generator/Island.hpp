#pragma once

#include <mcpp/mcpp.h>

namespace skyblock_generator {
    class Island {
    public:
        Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc);
        void teleportToIsland() const;
        void createIsland();
        void removeIsland();
        bool islandExists() const;

    private:
        void createLShapeIsland(std::uint8_t x, std::uint8_t length);
        void setIslandBlock(mcpp::Coordinate coord, mcpp::BlockType block) const;
        void placeChestWithContents(mcpp::Coordinate chestCoord, const std::array<std::pair<std::string, std::string>, 7>& contents);
        void placeTree(mcpp::Coordinate treeCoord);
        void setTreeHelperBlocks(mcpp::Coordinate treeCoord, mcpp::BlockType block) const;
        void setRandomTickSpeed(const std::string& speed) const;
        void setItemDespawnTime(const std::string& seconds) const;

        std::uint8_t width{};
        std::uint8_t length{};
        std::uint8_t height{};
        mcpp::Coordinate basepoint{};
        mcpp::MinecraftConnection& mc;
        std::vector<mcpp::Coordinate> islandBlockCoords{};
    };
}
