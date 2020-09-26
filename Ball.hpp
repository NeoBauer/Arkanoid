#pragma once
#include "olcPixelGameEngine.h"

class Ball {
public:
    Ball( olc::PixelGameEngine* pge, olc::vd2d startPos, int radius);
    void move(float fElapsedTime);

    olc::vf2d getPos() const;
    olc::vf2d getDirection() const;
    int getRadius() const;

private:
    olc::vf2d position_ = {0,0};
    olc::vf2d direction_ = {0,0};
    int radius_ = 10;
    float speed_ = 100.0;
     olc::PixelGameEngine* pge_;
};