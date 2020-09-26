#include "Ball.hpp"



void Ball::move(float fElapsedTime)
{
    position_ += direction_ * speed_ * fElapsedTime;

    if(position_.x >= pge_->ScreenWidth() - 1 ) direction_.x *= -1;
    if(position_.x <= 1                   ) direction_.x *= -1;
    if(position_.y <= 1                   ) direction_.y *= -1;
    
    if(padle_->onPadle(position_)         ) direction_.y *= -1; //<<REFACTOR!

    if(position_.y >= pge_->ScreenHeight()) reset(); //POINT LOSE

    
}

olc::vd2d Ball::getPos() const
{
    return position_;
}

int Ball::getRadius() const
{
    return radius_;
}
