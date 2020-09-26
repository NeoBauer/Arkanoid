#pragma once
#include "olcPixelGameEngine.h"
class Padle {
public:
    Padle(olc::PixelGameEngine* pge);
    void moveRight(float fElapsedTime);
    void moveLeft(float fElapsedTime);
    int getPos() const;
    int getWidth() const;

private:
    olc::PixelGameEngine* pge_;
	float position_ = 20.0f;
	float width_ = 40.0f;
};
