#include <skyblock_generator/chat_utils.hpp>
#include <skyblock_generator/Island.hpp>
#include <print>
#include <iostream>

int main() {
    try {
        mcpp::MinecraftConnection mc{};
        skyblock_generator::Island skyblockIsland{ 6, 6, 3, { 0, 60, 0 }, mc };
        mc.doCommand("time set day");
        std::println("\nWelcome to the Minecraft Skyblock Generator!");
        std::println("-------------------------------------------");
        char userMenuItem{};
        std::uint8_t userMenuNum{};
        do {
            std::println("\n---------------- MAIN MENU ----------------");
            std::println("1) Create Island");
            std::println("2) Remove Island");
            std::println("3) Exit");
            std::print("\nEnter Menu Item (1-3) to continue: ");
            std::cin.get(userMenuItem);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                        std::println(stderr, "\nCannot remove island without creating an island...");
                    }
                    break;
                case 3:
                    std::println("\nThe End!");
                    break;
                default:
                    std::println(stderr, "\nInput Error: Enter a Menu Item between 1 and 3...");
                    break;
            }
        } while (userMenuNum != 3 && !std::cin.eof());
    }
    catch (const std::exception& e) {
        std::println(stderr, "{}", e.what());
        return EXIT_FAILURE;
    }
}
