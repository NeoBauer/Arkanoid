//#define OLC_PGE_APPLICATION
#include "./Game.hpp"
int main()
{
	Game Arkanoid;
	if (Arkanoid.Construct(400, 480, 2, 2)) // values must have %16 = 0!
		Arkanoid.Start();
	return 0;
}