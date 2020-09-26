#include "Ball.hpp"

    Ball::Ball( olc::PixelGameEngine* pge, olc::vd2d startPos, int radius) : position_(startPos) , radius_(radius),  pge_(pge){}

    void Ball::move(float fElapsedTime){
        position_.y -= 100.0 * fElapsedTime;
    }

    olc::vd2d Ball::getPos() const {
        return position_;
    }

    int Ball::getRadius() const{
        return radius_;
    }
