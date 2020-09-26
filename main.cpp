#include "Board.hpp"

int main()
{
	Board demo;
	if (demo.Construct(640, 480, 1, 1))
		demo.Start();
	return 0;
}
