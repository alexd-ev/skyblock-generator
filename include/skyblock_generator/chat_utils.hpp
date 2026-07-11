#pragma once

#include <mcpp/mcpp.h>
#include <thread>

namespace skyblock_generator {
    void postTeleportMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Teleporting player to the skyblock island location...");
    }

    void postIslandCreationMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island ready for creation...");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Creating island...");
    }

    void postIslandCreationSuccessMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island created successfully!");
    }

    void postIslandRecreationMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Island already created. Attempting to recreate...");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mc.postToChat("Removing existing island...");
    }
}
