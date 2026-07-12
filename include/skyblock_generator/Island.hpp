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
        void setIslandBlock(std::uint8_t x, std::uint8_t y, std::uint8_t z, mcpp::BlockType block);

        std::uint8_t width{};
        std::uint8_t length{};
        std::uint8_t height{};
        mcpp::Coordinate basepoint{};
        mcpp::MinecraftConnection& mc;
        std::vector<std::pair<mcpp::Coordinate, mcpp::BlockType>> islandBlocks{};
    };
}
