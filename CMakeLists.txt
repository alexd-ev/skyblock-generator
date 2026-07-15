cmake_minimum_required(VERSION 3.20)
project(skyblock-generator VERSION 1.0.0 LANGUAGES CXX)

# Put generated binaries into the top-level build directory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Use FetchContent to bring in the external mcpp dependency.
include(FetchContent)
FetchContent_Declare(mcpp GIT_REPOSITORY https://github.com/rozukke/mcpp.git GIT_TAG main EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(mcpp)

# Build the library and executable in the src subtree.
add_subdirectory(src)

# Configure packaging metadata for CPack.
set(CPACK_PACKAGE_NAME "skyblock-generator")
set(CPACK_PACKAGE_VENDOR "alexd-ev")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "My Minecraft skyblock island generator project")
set(CPACK_PACKAGE_VERSION "1.0.0")
include(CPack)
