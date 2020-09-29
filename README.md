# Arkanoid


Authors:
#KrzysiekS
#majkel84
#NeoBauer

Coders School Hackaton motivated us to create a widely known game Arkanoid, as a way to train our C++ skills. 

We used recently released graphical engine olc::PixelGameEngine 2.0, created by Javidx9.

Javidx9 Repository: https://github.com/OneLoneCoder/olcPixelGameEngine.

To compile game, please get into Arkanoid repository folder and use commands in terminal:
(Works only on Linux, for a way to compile game on Windows, please visit Javidx9 Wiki on GitHub)

1.sudo apt update
2.sudo apt install build-essential libglu1-mesa-dev libpng-dev
3. mkdir build
4. cd build/
5. cmake ..
6. make
7. ./Arkanoid

And have fun :) 

What is still missing:

1. Colission detecion with block (now we detect only collision with arena boundary)
2. Menu
3. Game Over rules and screen
4. Next levels generator