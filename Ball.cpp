#include "Ball.hpp"
    void Ball::move(float fElapsedTime){
        position_ += direction_ * speed_ * fElapsedTime;
    }

    olc::vd2d Ball::getPos() const {
        return position_;
    }

    int Ball::getRadius() const{
        return radius_;
    }
