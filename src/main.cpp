#include <skyblock_generator/chat_utils.hpp>
#include <skyblock_generator/Island.hpp>
#include <print>

int main() {
    try {
        mcpp::MinecraftConnection mc{};
        skyblock_generator::Island island{ 6, 6, 3, { 0, 60, 0 }, mc };
        island.teleportToIsland();
        island.createIsland();
        island.destroyIsland();
    }
    catch (const std::exception& e) {
        std::println(stderr, "{}", e.what());
        return EXIT_FAILURE;
    }
}
