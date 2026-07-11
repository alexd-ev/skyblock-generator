#pragma once

#include <mcpp/mcpp.h>

namespace skyblock_generator {
    class Island {
    public:
        Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc);
        void teleportToIsland();
        void setIsland(bool create = true);

    private:
        void createLShapeIsland(std::uint8_t x, std::uint8_t length, bool create = true);
        void setBlock(std::uint8_t x, std::uint8_t y, std::uint8_t z, mcpp::BlockType block, bool create = true);

        std::uint8_t width{};
        std::uint8_t length{};
        std::uint8_t height{};
        mcpp::Coordinate basepoint{};
        mcpp::MinecraftConnection& mc;
    };
}
