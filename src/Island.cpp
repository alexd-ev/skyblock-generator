#include <skyblock_generator/Island.hpp>
#include <thread>

namespace skyblock_generator {
    Island::Island(std::uint8_t width, std::uint8_t length, std::uint8_t height, mcpp::Coordinate basepoint, mcpp::MinecraftConnection& mc)
        : width{ width }, length{ length }, height{ height }, basepoint{ basepoint }, mc{ mc } {}

    void Island::teleportToIsland() {
        mc.setPlayerPosition({ basepoint.x, basepoint.y + 10, basepoint.z });
    }

    void Island::setIsland(bool create) {
        for (std::uint8_t x = 0; x < width; ++x) {
            if (x < width / 2) {
                createLShapeIsland(x, length, create);
            }
            else {
                createLShapeIsland(x, length / 2, create);
            }
        }
    }

    void Island::createLShapeIsland(std::uint8_t x, std::uint8_t length, bool create) {
        for (std::uint8_t z = 0; z < length; ++z) {
            for (std::uint8_t y = 0; y < height; ++y) {
                if (y < height - 1) {
                    setBlock(x, y, z, mcpp::Blocks::DIRT, create);
                }
                else {
                    setBlock(x, y, z, mcpp::Blocks::GRASS, create);
                }
            }
        }
    }

    void Island::setBlock(std::uint8_t x, std::uint8_t y, std::uint8_t z, mcpp::BlockType block, bool create) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mc.setBlock({ basepoint.x + x, basepoint.y + y, basepoint.z + z }, create ? block : mcpp::Blocks::AIR);
    }
}
