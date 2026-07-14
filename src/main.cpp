#include <skyblock_generator/menu_utils.hpp>
#include <skyblock_generator/chat_utils.hpp>
#include <skyblock_generator/Island.hpp>

int main() {
    try {
        mcpp::MinecraftConnection mc{};
        mc.doCommand("time set day");
        skyblock_generator::Island skyblockIsland{ 6, 6, 3, { 0, 60, 0 }, mc };
        std::uint8_t userMenuNum{};
        skyblock_generator::printStartMessage();
        do {
            skyblock_generator::printMainMenu();
            char userMenuItem{ skyblock_generator::getUserMenuItem() };
            userMenuNum = userMenuItem - '0';
            switch (userMenuNum) {
                case 1:
                    if (skyblockIsland.islandExists()) {
                        skyblock_generator::postIslandRecreationMessage(mc);
                        skyblockIsland.removeIsland();
                        skyblock_generator::postIslandCreationMessage(mc);
                        skyblockIsland.createIsland();
                        skyblock_generator::postIslandCreationSuccessMessage(mc);
                    }
                    else {
                        skyblock_generator::postTeleportMessage(mc);
                        skyblockIsland.teleportToIsland();
                        skyblock_generator::postIslandCreationMessage(mc);
                        skyblockIsland.createIsland();
                        skyblock_generator::postIslandCreationSuccessMessage(mc);
                    }
                    break;
                case 2:
                    if (skyblockIsland.islandExists()) {
                        skyblock_generator::postIslandRemovalMessage(mc);
                        skyblockIsland.removeIsland();
                        skyblock_generator::postIslandRemovalSuccessMessage(mc);
                    }
                    else {
                        skyblock_generator::printCannotRemoveMessage();
                    }
                    break;
                case 3:
                    skyblock_generator::printExitMessage();
                    break;
                default:
                    skyblock_generator::printInputErrorMessage();
                    break;
            }
        } while (userMenuNum != 3 && !std::cin.eof());
    }
    catch (const std::exception& e) {
        std::println(stderr, "{}", e.what());
        return EXIT_FAILURE;
    }
}
