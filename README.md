# Minecraft++
 Minecraft in cpp with OpenGL

## Supported operating systems:
- Linux (Debian)

## How to setup Minecraft++

### Dependecies
  - freeglut (`sudo apt install freeglut3-dev`)
  - gl       (`sudo apt install libgl-dev`)
  - glew     (`sudo apt install libglew-dev`)

### Setup
On the first launch, you will neeed to get the assets for the game by executing `getAssets.sh`. This will downlaod all assets from Mojang wich may take up to 15 minutes or more depending on you connection speed.

## Running Minecraft++
Once Minecraft++ is finished / usable, you can run it by compiling it with `make` and then running it with `./bin/main` or compiling and running by using `make run`.

// Note: Minecraft Server Communication Documentation: https://wiki.vg/Main_Page