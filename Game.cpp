#include "Game.hpp"

bool Game::OnUserCreate() {
  return true;
}

bool Game::OnUserUpdate(float fElapsedTime){
  if (GetKey(olc::Key::LEFT).bHeld) padle->moveLeft(fElapsedTime);
  if (GetKey(olc::Key::RIGHT).bHeld) padle->moveRight(fElapsedTime);

  ball->move(fElapsedTime);

  drawAll();

  return true;
}

void Game::drawAll(){
  Clear(olc::DARK_BLUE);
  drawBoard();
  drawPadle();
  drawBall();
}

void Game::drawBoard(){
  DrawRect(1,1, ScreenWidth() - 2, ScreenHeight() );
}

void Game::drawPadle(){
  FillRect(padle->getPos(), ScreenHeight() - 20, padle->getWidth(), 10, olc::GREEN);
}

void Game::drawBall(){
  FillCircle(ball->getPos(), ball->getRadius(), olc::RED);	
}
