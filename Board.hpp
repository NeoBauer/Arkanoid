#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Padle.hpp"
#include "Brick.hpp"
#include "Ball.hpp"

constexpr int wallThickness = 5;

// Override base class with your custom functionality
class Board : public olc::PixelGameEngine
{
public:
	Board() {
		// Name you application
		sAppName = "Board";
	}

public:
	bool OnUserCreate() override {
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(0, 0, 0));
        FillRect(0, 0, ScreenWidth(), wallThickness, olc::GREY);
        FillRect(0, 0, wallThickness, ScreenHeight(), olc::GREY);
        FillRect(ScreenWidth() - wallThickness, 0, wallThickness, ScreenHeight(), olc::GREY);
		return true;
	}
};
