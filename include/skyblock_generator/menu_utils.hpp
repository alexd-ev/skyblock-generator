#pragma once

#include <print>
#include <iostream>
#include <limits>

// Console menu utilities used by the small CLI that interacts with the
// `mcpp` connection.

namespace skyblock_generator {
    // Print the welcome banner shown at program start.
    inline void printStartMessage() {
        std::println("\nWelcome to the Minecraft Skyblock Generator!");
        std::println("-------------------------------------------");
    }

    // Display the main menu options and prompt for user input.
    inline void printMainMenu() {
        std::println("\n---------------- MAIN MENU ----------------");
        std::println("1) Create Island");
        std::println("2) Remove Island");
        std::println("3) Exit");
        std::print("\nEnter Menu Item (1-3) to continue: ");
    }

    // Read a single character from stdin and discard the rest of the line.
    // Returns the raw character as entered by the user (e.g. '1').
    inline char getUserMenuItem() {
        char userMenuItem{};
        std::cin.get(userMenuItem);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return userMenuItem;
    }

    // Print exit confirmation message.
    inline void printExitMessage() {
        std::println("\nThe End!");
    }

    // Error shown when attempting to remove an island that does not exist.
    inline void printCannotRemoveMessage() {
        std::println(stderr, "\nCannot remove island without creating an island...");
    }

    // Error shown when the user enters invalid input in the menu.
    inline void printInputErrorMessage() {
        std::println(stderr, "\nInput Error: Enter a Menu Item between 1 and 3...");
    }
}
