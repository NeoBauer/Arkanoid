#pragma once
#include <utility>

class Padle {
public:
/*     int getPosition() const { return positionX_; };
    int getPadleLenght() const { return padleLenght_;};
    int getpadleHight() const { return padleHight_;}; */
    void setPosition(int newPosition) {
        positionX_ = newPosition;
    }
    void moveLeft(float elapsedTime){
        positionX_ += 20 * elapsedTime;
    }
    void moveRight(float elapsedTime){
        positionX_ -= 20 * elapsedTime;
    }
public:
    int positionX_ = 0;
    const int padleLenght_ = 50;
    const int padleHight_ = 10;
};