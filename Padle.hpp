#pragma once

#include <utility>

class Padle {
public:
    std::pair<int, int> getPosition() { return position_; }
    void setPosition(std::pair<int, int> newPosition) {
        position_.first = newPosition.first;
        position_.second = newPosition.second;
    }
private:
    std::pair<int, int> position_;
    const int padleLenght_;
    const int padleHight_;
}