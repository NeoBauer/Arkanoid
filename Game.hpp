#include "olcPixelGameEngine.h"
#include "Board.hpp"
#include "Padle.hpp"
class Game : public olc::PixelGameEngine
{   
    public:

    Padle padle_;

    public: 
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;

};