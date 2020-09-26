#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Padle.hpp"
#include "Brick.hpp"
#include "Ball.hpp"

// class Drawer{
// public:
// 	Drawer(Padle * padle, Ball * ball) : padle_(padle), ball_(ball){};

// 	void print();

// private:
// 	Padle * padle_;
// 	Ball * ball_;
// };

class Game : public olc::PixelGameEngine
{
public:
	Game() {
		// Name you application
		sAppName = "Board";
	}

public:
	bool OnUserCreate() override {
		padle = new Padle(40.0f);
		ball = new Ball({ScreenWidth() / 2, ScreenHeight() - 20}, 5);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		if (GetKey(olc::Key::LEFT).bHeld) padle->moveLeft(fElapsedTime);
		if (GetKey(olc::Key::RIGHT).bHeld) padle->moveRight(fElapsedTime);


		ball->move(fElapsedTime);

		drawAll();

		return true;
	}

	void drawAll(){
		Clear(olc::DARK_BLUE);
		DrawRect(1,1, ScreenWidth() - 2, ScreenHeight() );
		FillRect(padle->getPos(), ScreenHeight() - 20, padle->getWidth(), 10, olc::GREEN);
		FillCircle(ball->getPos(), ball->getRadius(), olc::RED);	
	}

private:
	Padle * padle;
	Ball * ball;
};