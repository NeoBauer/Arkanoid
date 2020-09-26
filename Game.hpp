#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Padle.hpp"
#include "Brick.hpp"
#include "Ball.hpp"

class Game : public olc::PixelGameEngine{   
public: 
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void drawAll();
	void drawBoard();
	void drawPadle();
	void drawBall();

private:
	Padle * padle;
	Ball * ball;
};