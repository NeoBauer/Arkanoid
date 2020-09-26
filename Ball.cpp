#include "Ball.hpp"

    Ball::Ball( olc::PixelGameEngine* pge, olc::vd2d startPos, int radius) : position_(startPos) , radius_(radius),  pge_(pge){}

    void Ball::move(float fElapsedTime){
        position_.y -= direction_.y * 1000.0 * fElapsedTime;
        position_.x -= direction_.x * 1000.0 * fElapsedTime;
    }

    olc::vf2d Ball::getPos() const {
        return position_;
    }

    olc::vf2d Ball::getDirection() const {
         return direction_; 
    }

    int Ball::getRadius() const{   
        return radius_;
    }

    std::pair<int, int> Ball::GetTestPoints(float angle) const{

    std::pair<int, int> testPointsPair;
    int x = position_.x + radius_ * cos(angle); 
    int y = position_.y + radius_ * sin(angle);
    testPointsPair = std::make_pair(x, y);

    return testPointsPair;
    }

    void Ball::setDirection(olc::vf2d& direction) {
    direction_ = direction_ * direction;
    }
