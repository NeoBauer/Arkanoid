#pragma once
#include "olcPixelGameEngine.h"
class Padle {
public:
    Padle(olc::PixelGameEngine* pge);
    void moveRight(float fElapsedTime);
    void moveLeft(float fElapsedTime);
    int getPos() const;
    int getWidth() const;

    bool onPadle(olc::vd2d position);
private:
    olc::PixelGameEngine* pge_;
	float position_ = 100.0f;
	float width_ = 40.0f;
    float height_ = 20.0f;
};
