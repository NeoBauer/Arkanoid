#include "olcPixelGameEngine.h"
#include "Game.hpp"

int main(){
	Game demo;
	if (demo.Construct(256, 256, 4, 4))
		demo.Start();
	return 0;
}
