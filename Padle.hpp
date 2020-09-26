#pragma once
#include "olcPixelGameEngine.h"
class Padle {
public:
    Padle(olc::PixelGameEngine* pge, int spriteSize);
    void moveRight(float fElapsedTime);
    void moveLeft(float fElapsedTime);
    float getPos() const;
    int getWidth() const;
    void increaseWidth();
    void decreaseWidth();

private:
    olc::PixelGameEngine* pge_;
    int spriteSize_;
	float position_ = 16;
	int width_ = 5;
};
