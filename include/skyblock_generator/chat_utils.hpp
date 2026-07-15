#pragma once

#include <mcpp/mcpp.h>
#include <thread>
#include <chrono>

namespace skyblock_generator {
    // Pause briefly and post a teleport notice to chat.
    // Note: these helpers intentionally block the calling thread to space messages
    // for readability in-game.
    inline void postTeleportMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Teleporting player to the skyblock island location...");
    }

    // Inform players that island creation is starting; includes a short delay
    // between lines so that messages are easier to read in the chat window.
    inline void postIslandCreationMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island ready for creation...");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Creating island...");
    }

    // Announce when the island has been created successfully.
    inline void postIslandCreationSuccessMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island created successfully!");
    }

    // Notify players that island removal is in progress.
    inline void postIslandRemovalMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Removing island...");
    }

    // Confirm island removal.
    inline void postIslandRemovalSuccessMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island removed successfully!");
    }

    // Inform the player that the island will be recreated (old island removed).
    inline void postIslandRecreationMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island already created. Attempting to recreate...");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Removing old island...");
    }
}
