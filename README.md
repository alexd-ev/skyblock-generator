# Minecraft Skyblock Generator
## Overview
My Minecraft skyblock island generator project uses the [mcpp](https://github.com/rozukke/mcpp) interfacing library with Minecraft Java Edition. The project showcases creating, removing and recreating the classic skyblock island in a Minecraft world. It runs a console menu with user input to perform the functions above.

### Creating
[Create Island Video](https://github.com/user-attachments/assets/21a33a08-0c89-48e0-a2a0-4661b4db872a)

### Removing
[Remove Island Video](https://github.com/user-attachments/assets/f7ad6979-6d55-434b-933b-2ff597969e86)

### Recreating
[Recreate Island Video](https://github.com/user-attachments/assets/cf43538c-ccae-49f8-8c73-82693d64128e)

## Technical Specification
Spigot Server 1.21.3+ is required. Once the ELCI plugin is installed on a Spigot server and is running, join the server with `localhost` as the Server Address.

### Linux/WSL x86_64
Download the released `skyblock-generator-1.0.0-Linux.tar.gz` archive found here: https://github.com/alexd-ev/skyblock-generator/releases/latest. Extract the files then run the application in a terminal:
```bash
tar -xvf skyblock-generator-1.0.0-Linux.tar.gz
./skyblock-generator-1.0.0-Linux/bin/skyblock-generator
```

### macOS
See [Packaging the Code](#packaging-the-code). Then locate the package in `build/`.

To build and run the code, [CMake 3.20+](https://cmake.org/download/) is required. Alongside a C++ compiler that supports C++23+ such as [g++15](https://ftp.gnu.org/gnu/gcc/gcc-15.2.0/) as well as a build engine such as [make](https://ftp.gnu.org/gnu/make/). If on Linux/WSL run this command to update the system's shared library cache:
```bash
sudo ldconfig
```
If using most IDE CMake plugins, set the build variant to `Release`. The [mcpp](https://github.com/rozukke/mcpp) library should automatically download; build files should also automatically generate and can build and run from IDE. Otherwise, can  download, generate, build and run from terminal (see [Building and Running the code](#building-and-running-the-code)).

## Libraries
* `mcpp`
    * `mcpp.h` (Minecraft interfacer)
* `skyblock_generator`
    * `Island.hpp` (Island class declaration)
    * `chat_utils.hpp` (Minecraft chat posting utility functions)
    * `menu_utils.hpp` (Menu logging and input utility functions)

## Source Files
```
main.cpp                                    - Main application entrypoint
Island.cpp                                  - Island class definition
```

## Project Structure
```
skyblock-generator/
├── build/                                  - Generated build directory
├── include/skyblock_generator/
│   └── *.hpp                               - Header files
├── src/
│   ├── CMakeLists.txt                      - Configure build for library and executable
│   └── *.cpp                               - C++ source files
├── .gitignore                              - Ignore C++ and CMake files
├── CMakeLists.txt                          - Configure build
├── LICENSE                                 - GPL-3.0 licence
└── README.md                               - Documentation
```

# Building and Running the Code
Generate build files, build and run the application:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
./build/skyblock-generator
```

# Packaging the Code
First [build](#building-and-running-the-code), then package:
```bash
cd build
cpack -C Release
```

# Author
`alexd-ev` (Alex Davidson)

Copyright Alex Davidson (c) 2026
