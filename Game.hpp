#pragma once
#include "Padle.hpp"
#include "Ball.hpp"

#include "olcPixelGameEngine.h"

class Game : public olc::PixelGameEngine{   
public: 
    Game(){
		sAppName = "TUTORIAL - BreakOut Clone";
	    }
		
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void drawAll();

	void drawBoard();
	void drawPadle();
	void drawBall();

private:
	Padle *padle;
	Ball *ball;
};