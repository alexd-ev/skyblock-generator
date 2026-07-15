# Minecraft Skyblock Generator
## Overview
My Minecraft skyblock island generator project uses the [mcpp](https://github.com/rozukke/mcpp) interfacing library with Minecraft Java Edition. The project showcases creating, removing and recreating the classic skyblock island in a Minecraft world. It runs a console menu with user input to perform the functions above.

### Creating


### Removing


### Recreating


## Technical Specification
Once the ELCI plugin is installed on a Spigot server and is running, join the server with `localhost` as the Server Address. Download the released executable WIP. Then run the application in a terminal:
#### Linux/WSL
```bash
./
```

#### macOS
```bash
./
```

To build and run the code locally, install [mcpp](https://github.com/rozukke/mcpp#installation). If on Linux/WSL run this command to update the system's shared library cache:
```bash
sudo ldconfig
```
If using most IDE CMake plugins, set the build variant to `Release`. The build files should automatically generate and can build and run from IDE. Otherwise, can generate, build and run from terminal (see [Building and Running the code](#building-and-running-the-code)).

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
├── .gitignore                              - Ignore C++ files
├── CMakeLists.txt                          - Configure build
├── LICENSE                                 - GPL-3.0 licence
└── README.md                               - Documentation
```

# Building and Running the Code
Generate build files, build and run the application:
```bash
cmake -DCMAKE_BUILD_TYPE=Release -B build
cmake --build build
./build/skyblock-generator
```

# Author
`alexd-ev` (Alex Davidson)

Copyright Alex Davidson (c) 2026
