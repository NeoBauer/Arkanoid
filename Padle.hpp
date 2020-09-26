#pragma once

class Padle {
public:
    Padle(float width) : witdh_(width){}

    void moveRight(float fElapsedTime) {
        position_ += 100.0 * fElapsedTime;
    }

    void moveLeft(float fElapsedTime) {
        position_ -= 100.0 * fElapsedTime;
    }

    int getPos() const {
        return static_cast<int>(position_);
    }

    int getWidth() const {
        return static_cast<int>(witdh_);
    }

private:
	float position_ = 20.0f;
	float witdh_ = 40.0f;
};
