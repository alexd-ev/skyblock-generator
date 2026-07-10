#include <mcpp/mcpp.h>
#include <thread>

namespace skyblock_generator {
    void postTeleportMessage(mcpp::MinecraftConnection& mc) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mc.postToChat("Teleporting player to the skyblock island location...");
    }
}
