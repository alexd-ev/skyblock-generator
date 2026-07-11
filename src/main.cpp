#include <skyblock_generator/chat_utils.hpp>
#include <mcpp/mcpp.h>
#include <print>

int main() {
    try {
        mcpp::MinecraftConnection mc;
        skyblock_generator::postTeleportMessage(mc);
        skyblock_generator::postIslandCreationMessage(mc);
        skyblock_generator::postIslandCreationSuccessMessage(mc);
        skyblock_generator::postIslandRecreationMessage(mc);
    }
    catch (const std::exception& e) {
        std::println(stderr, "{}", e.what());
        return EXIT_FAILURE;
    }
}
