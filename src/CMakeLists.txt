add_library(skyblock-generator-lib STATIC Island.cpp)
target_include_directories(skyblock-generator-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(skyblock-generator main.cpp)
target_compile_options(skyblock-generator PRIVATE -Wall -Werror)
target_link_libraries(skyblock-generator PRIVATE mcpp skyblock-generator-lib)
# target_link_options(skyblock-generator PRIVATE -static-libgcc -static-libstdc++)

install(TARGETS skyblock-generator DESTINATION bin)
