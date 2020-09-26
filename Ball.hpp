#pragma once

class Ball {
public:
    Ball(olc::vd2d startPos, int radius) : position_(startPos) , radius_(radius){}

    void move(float fElapsedTime){
        position_.y -= 100.0 * fElapsedTime;
    }

    olc::vd2d getPos() const {
        return position_;
    }

    int getRadius() const{
        return radius_;
    }

private:
    olc::vd2d position_ = {0,0};
    int radius_ = 10;

    float speed_ = 100.0;
    float direction_ = 0;
};