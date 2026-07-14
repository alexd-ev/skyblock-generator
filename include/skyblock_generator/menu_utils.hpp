#pragma once

#include <print>
#include <iostream>

namespace skyblock_generator {
    void printStartMessage() {
        std::println("\nWelcome to the Minecraft Skyblock Generator!");
        std::println("-------------------------------------------");
    }

    void printMainMenu() {
        std::println("\n---------------- MAIN MENU ----------------");
        std::println("1) Create Island");
        std::println("2) Remove Island");
        std::println("3) Exit");
        std::print("\nEnter Menu Item (1-3) to continue: ");
    }

    char getUserMenuItem() {
        char userMenuItem{};
        std::cin.get(userMenuItem);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return userMenuItem;
    }

    void printExitMessage() {
        std::println("\nThe End!");
    }

    void printCannotRemoveMessage() {
        std::println(stderr, "\nCannot remove island without creating an island...");
    }

    void printInputErrorMessage() {
        std::println(stderr, "\nInput Error: Enter a Menu Item between 1 and 3...");
    }
}
