#pragma once

class Padle {
public:
    Padle(float width) : witdh_(width){}

    void moveRight(float fElapsedTime);
    void moveLeft(float fElapsedTime);
    int getPos() const;
    int getWidth() const;

private:
	float position_ = 20.0f;
	float witdh_ = 40.0f;
};
