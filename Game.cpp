#include "Game.hpp"

bool Game::OnUserCreate(){
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime){

  if(GetKey(olc::Key::LEFT).bHeld)
  padle_.moveLeft(fElapsedTime);
  else if(GetKey(olc::Key::RIGHT).bHeld)
  padle_.moveRight(fElapsedTime); 
    
return true;
}