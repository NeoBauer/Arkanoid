#pragma once
#include "olcPixelGameEngine.h"
#include "Padle.hpp"

class Ball {
public:
    Ball(olc::PixelGameEngine* pge, Padle * padle, olc::vd2d startPos, int radius) :
    pge_(pge), padle_(padle), position_(startPos), radius_(radius){};
    
    void move(float fElapsedTime);
    olc::vd2d getPos() const ;
    int getRadius() const;

    void reset(){
        position_ = {0,0};
        direction_ = {-1,-1};
    }

private:
    olc::vd2d position_ = {0,0};
    olc::vd2d direction_ = {-1,-1};
    int radius_ = 10;
    float speed_ = 100.0;

    olc::PixelGameEngine* pge_;
    Padle * padle_;
};