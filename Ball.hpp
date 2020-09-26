#pragma once

#include "olcPixelGameEngine.h"

class Ball {
public:
    Ball(olc::vd2d startPos, int radius) : position_(startPos) , radius_(radius){}

    void move(float fElapsedTime);
    olc::vd2d getPos() const ;
    int getRadius() const;

private:
    olc::vd2d position_ = {0,0};
    int radius_ = 10;

    float speed_ = 100.0;
    olc::vd2d direction_ = {-1,-1};
};