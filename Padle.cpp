#include "Padle.hpp"
#include "olcPixelGameEngine.h"

    Padle::Padle( olc::PixelGameEngine* pge) : pge_(pge){}

    void Padle::moveRight(float fElapsedTime) {
        if((position_+(0.5*width_))<(0.5*pge_->ScreenWidth()))
        position_ += 100.0 * fElapsedTime;
    }

    void Padle::moveLeft(float fElapsedTime) {
        position_ -= 100.0 * fElapsedTime;
    }

    int Padle::getPos() const {
        return static_cast<int>(position_);
    }

    int Padle::getWidth() const {
        return static_cast<int>(width_);
    }
