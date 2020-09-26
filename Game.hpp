#pragma once
#include "Padle.hpp"
#include "Ball.hpp"

class Game : public olc::PixelGameEngine{   
public: 
    Game(){
          padle = new Padle(this);
          ball = new Ball(this, {ScreenWidth() / 2, ScreenHeight() - 20}, 5);
    }
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