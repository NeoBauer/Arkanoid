#include "Padle.hpp"
#include "olcPixelGameEngine.h"

    Padle::Padle( olc::PixelGameEngine* pge) : pge_(pge){}

    void Padle::moveRight(float fElapsedTime) {
        position_ += 100.0 * fElapsedTime;
        if((position_ + width_) > (pge_->ScreenWidth()))
            position_ = pge_->ScreenWidth() - width_;

    }

    void Padle::moveLeft(float fElapsedTime) {
        position_ -= 100.0 * fElapsedTime;
        if(position_ <= 0)
            position_ = 0;
    }

    int Padle::getPos() const {
        return static_cast<int>(position_);
    }

    int Padle::getWidth() const {
        return static_cast<int>(width_);
    }
