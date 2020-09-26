#include "Board.hpp"

int main()
{
	Board demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
