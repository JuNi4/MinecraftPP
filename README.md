# Minecraft++
 Minecraft in cpp with OpenGL

Note: Minecraft++ is currently in developement and may not be functional at all. Currently only 2 persons are working on this wich means that developement may take a while.

## Supported operating systems:
- Linux (only tested on Debian)

## How to setup Minecraft++

### Dependecies
  - freeglut (`sudo apt install freeglut3-dev`)
  - gl       (`sudo apt install libgl-dev`)
  - glew     (`sudo apt install libglew-dev`)
  - libzip   (`sudo apt install libzip-dev` or https://libzip.org/download/)
  - curl     (`sudo apt install libcurl-dev` or https://curl.se/download.html)

(Included)
  - nlohmann/json (https://github.com/nlohmann/json)
  - elnormous/HTTPRequest (https://github.com/elnormous/HTTPRequest)
  - GLGE (https://github.com/dm8at/glge)

### Setup
On the first launch, Minecraft++ will automatily download all resources required to start the game. This may take up to 10 minutes or more, depending on your connection speed.
In addition to that, if Minecraft++ detects on options.txt from your default minecraft install, it will ask you if it should be copied to Minecraft++. If you choose 'yes' it will require a restart for changes to take affect.

## Running/compiling Minecraft++
Once Minecraft++ is finished / usable, you can run it by compiling it with `make` and then running it with `./bin/main` or compiling and running by using `make run`.
