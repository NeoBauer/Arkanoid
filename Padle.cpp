#include "Padle.hpp"
#include "olcPixelGameEngine.h"

    Padle::Padle( olc::PixelGameEngine* pge, int spriteSize) :
     pge_(pge),
     spriteSize_(spriteSize)
     {}

    void Padle::moveRight(float fElapsedTime) {
        if(position_ < (pge_->ScreenWidth()-width_*spriteSize_-spriteSize_))
        position_ += 100.0 * fElapsedTime;
    }

    void Padle::moveLeft(float fElapsedTime) {
        if(position_ > spriteSize_)
        position_ -= 100.0 * fElapsedTime;
    }

    float Padle::getPos() const {
        return position_;
    }

    int Padle::getWidth() const {
        return width_;
    }

    void Padle::increaseWidth() {
        if(width_ < pge_->ScreenWidth())
        width_+=1;
    }
    void Padle::decreaseWidth() {
        if(width_ > 0)
        width_-=1;
    }