add_library(skyblock-generator-lib INTERFACE)
target_include_directories(skyblock-generator-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(skyblock-generator main.cpp Island.cpp)
target_compile_options(skyblock-generator PRIVATE -Wall -Werror)
target_link_libraries(skyblock-generator PRIVATE mcpp skyblock-generator-lib)
