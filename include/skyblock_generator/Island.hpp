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
        std::uint8_t width;
        std::uint8_t length;
        std::uint8_t height;
        mcpp::Coordinate basepoint;
        mcpp::MinecraftConnection& mc;
    };
}
