# Build the reusable island implementation as a static library.
add_library(skyblock-generator-lib STATIC Island.cpp)
# Expose the public headers to consumers of the library.
target_include_directories(skyblock-generator-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set_target_properties(skyblock-generator-lib PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

# Build the CLI executable that links the library and the external mcpp dependency.
add_executable(skyblock-generator main.cpp)
target_compile_options(skyblock-generator PRIVATE -Wall -Werror)
target_link_libraries(skyblock-generator PRIVATE mcpp skyblock-generator-lib)
set_target_properties(skyblock-generator PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)
# Enable this for a statically linked GCC runtime for distribution
# target_link_options(skyblock-generator PRIVATE -static-libgcc -static-libstdc++)

# Install the executable into the package `bin/` directory.
install(TARGETS skyblock-generator DESTINATION bin)
