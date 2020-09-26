#include "Game.hpp"
#include <iostream>

bool Game::OnUserCreate()
{
    padle = new Padle(this, spriteSize);
    ball = new Ball(this, {ScreenWidth() / 2.0, ScreenHeight() - 20.0}, 5);
    divideScreenOnBlocks();
    BordersprTile = std::make_unique<olc::Sprite>("../BorderPX.png");
    PadlesprTile = std::make_unique<olc::Sprite>("../PadlePX.png");
    victimsprTile = std::make_unique<olc::Sprite>("../victimPX.png");
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{ //readSprites();
    if (GetKey(olc::Key::LEFT).bHeld)
        padle->moveLeft(fElapsedTime);
    if (GetKey(olc::Key::RIGHT).bHeld)
        padle->moveRight(fElapsedTime);
    if (GetMouseWheel() > 0)
        padle->increaseWidth();
    if (GetMouseWheel() < 0)
        padle->decreaseWidth();

    ball->move(fElapsedTime);

    drawAll();

    return true;
}

void Game::drawAll()
{
    Clear(olc::DARK_BLUE);
    drawBoard();
    drawPadle();
    drawBall();
}

void Game::drawBoard()
{
    SetPixelMode(olc::Pixel::MASK);
    for (int y = 0; y < (ScreenHeight() / spriteSize); y++)
    {
        for (int x = 0; x < (ScreenWidth() / spriteSize); x++)
        {
            switch (blocks[y * (ScreenWidth() / spriteSize) + x])
            {
            case 0: // Do nothing
                break;
            case 10: // Draw Boundary
                DrawSprite(olc::vi2d(x, y) * vBlockSize, BordersprTile.get());
                break;
            case 1: 
                DrawSprite(olc::vi2d(x, y) * vBlockSize, victimsprTile.get());
                break;
            }
        }
    }
    SetPixelMode(olc::Pixel::NORMAL);   
}

void Game::drawPadle()
{
    for (int i = 0; i < padle->getWidth(); i++)
    {
        DrawSprite(olc::vf2d(padle->getPos() + i * (spriteSize), (ScreenHeight() - (spriteSize * 3))), PadlesprTile.get());
        std::cout << (padle->getPos() + i * (spriteSize)) << std::endl;
    }
}

void Game::drawBall()
{
    FillCircle(ball->getPos(), ball->getRadius(), olc::RED);
}

void Game::divideScreenOnBlocks()
{

    blocks = std::make_unique<int[]>((ScreenWidth() / spriteSize) * (ScreenHeight() / spriteSize));
    for (int y = 0; y < ScreenHeight() / spriteSize; y++)
    {
        for (int x = 0; x < ScreenWidth() / spriteSize; x++)
        {
            if (x == 0 || y == 0 || x == (ScreenWidth() / spriteSize) - 1)
                blocks[y * (ScreenWidth() / spriteSize) + x] = 10;
            else
                blocks[y * (ScreenWidth() / spriteSize) + x] = 0;

            if (x > 2 && x <= (ScreenWidth() / spriteSize) - 4 && y > 3 && y <= 7)
                blocks[y * (ScreenWidth() / spriteSize) + x] = 1;
        }
    }
}