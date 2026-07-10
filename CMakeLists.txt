cmake_minimum_required(VERSION 3.20)
project(skyblock-generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(skyblock-generator main.cpp)
target_link_libraries(skyblock-generator mcpp)
