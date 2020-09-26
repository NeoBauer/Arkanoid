#pragma once
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Padle.hpp"
#include "Brick.hpp"
#include "Ball.hpp"

class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "TUTORIAL - BreakOut Clone";
	}

	bool OnUserCreate()
	{
		padle = new Padle(40.0f);
		ball = new Ball({ScreenWidth() / 2, ScreenHeight() - 20}, 5);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime)
	{
		if (GetKey(olc::Key::LEFT).bHeld)
			padle->moveLeft(fElapsedTime);
		if (GetKey(olc::Key::RIGHT).bHeld)
			padle->moveRight(fElapsedTime);

		ball->move(fElapsedTime);
		

		drawAll();

		return true;
	}

	void drawAll()
	{
		Clear(olc::DARK_BLUE);
		drawBoard();
		drawPadle();
		drawBall();
	}

	void drawBoard()
	{
		DrawRect(1, 1, ScreenWidth() - 2, ScreenHeight());
	}

	void drawPadle()
	{
		FillRect(padle->getPos(), ScreenHeight() - 20, padle->getWidth(), 10, olc::GREEN);
	}

	void drawBall()
	{
		FillCircle(ball->getPos(), ball->getRadius(), olc::RED);
	}

private:
	Padle *padle;
	Ball *ball;
};