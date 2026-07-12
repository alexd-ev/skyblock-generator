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
    }

    void Island::createLShapeIsland(std::uint8_t z, std::uint8_t width) {
        mcpp::BlockType dirtBlock = mcpp::Blocks::DIRT;
        mcpp::BlockType grassBlock = mcpp::Blocks::GRASS;
        for (std::uint8_t x = 0; x < width; ++x) {
            for (std::uint8_t y = 0; y < height; ++y) {
                if (y < height - 1) {
                    islandBlocks.push_back({ { x, y, z }, dirtBlock });
                    setIslandBlock(x, y, z, dirtBlock);
                }
                else {
                    islandBlocks.push_back({ { x, y, z }, grassBlock });
                    setIslandBlock(x, y, z, grassBlock);
                }
            }
        }
    }

    void Island::destroyIsland() {
        for (const auto& [coord, block] : islandBlocks) {
            setIslandBlock(coord.x, coord.y, coord.z, mcpp::Blocks::AIR);
        }
    }

    void Island::setIslandBlock(std::uint8_t x, std::uint8_t y, std::uint8_t z, mcpp::BlockType block) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mc.setBlock({ basepoint.x + x, basepoint.y + y, basepoint.z + z }, block);
    }
}
