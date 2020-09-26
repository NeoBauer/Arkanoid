#pragma once
#include "Padle.hpp"
#include "Ball.hpp"

class Game : public olc::PixelGameEngine{   
public: 
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void drawAll();
	void drawBoard();
	void drawPadle();
	void drawBall();
    void divideScreenOnBlocks();
    bool CheckIfHitBorder(Ball* ball, std::vector<std::pair<int, int>>& testPoints, float time);
    std::pair<int, int> GetTemporaryTestPoints(float angle, Ball* ball) const;
    

private:
	Padle * padle;
	Ball * ball;
    std::unique_ptr<int[]> blocks;
    int spriteSize = 16;
    olc::vi2d vBlockSize = { spriteSize, spriteSize };
    std::unique_ptr<olc::Sprite> BordersprTile;
    std::unique_ptr<olc::Sprite> PadlesprTile;
    std::unique_ptr<olc::Sprite> victimsprTile;
    std::vector<std::pair<int, int>> testPointsVector;
};