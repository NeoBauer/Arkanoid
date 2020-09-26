 #include "Padle.hpp"
 
    void Padle::moveRight(float fElapsedTime) {
        position_ += 100.0 * fElapsedTime;
    }

    void Padle::moveLeft(float fElapsedTime) {
        position_ -= 100.0 * fElapsedTime;
    }

    int Padle::getPos() const {
        return static_cast<int>(position_);
    }

    int Padle::getWidth() const {
        return static_cast<int>(witdh_);
    }