#pragma once
#include "olcPixelGameEngine.h"
#include <vector>

class Ball {
public:
    Ball( olc::PixelGameEngine* pge, olc::vd2d startPos, int radius);
    
    void move(float fElapsedTime);
    olc::vf2d getPos() const;
    olc::vf2d getDirection() const;
    int getRadius() const;
    std::pair<int, int> GetTestPoints(float angle) const;
    void setDirection(olc::vf2d&);
    olc::vf2d direction_ = {-1.5,3}; // write getter
    olc::vf2d position_ = {0,0};
    int radius_ = 8;
private:
    
    
    
    float speed_ = 100.0;
    olc::PixelGameEngine* pge_;
    
};