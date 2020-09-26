#include "Game.hpp"
#include <iostream>

bool Game::OnUserCreate()
{
    padle = new Padle(this, spriteSize);
    ball = new Ball(this, {ScreenWidth() / 2.0, ScreenHeight() - 40.0}, 8);
    divideScreenOnBlocks();
    BordersprTile = std::make_unique<olc::Sprite>("../BorderPX.png");
    PadlesprTile = std::make_unique<olc::Sprite>("../PadlePX.png");
    victimsprTile = std::make_unique<olc::Sprite>("../victimPX.png");
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{   std::cout << fElapsedTime << std::endl;
    if (GetKey(olc::Key::LEFT).bHeld)
        padle->moveLeft(fElapsedTime);
    if (GetKey(olc::Key::RIGHT).bHeld)
        padle->moveRight(fElapsedTime);
    if (GetMouseWheel() > 0)
        padle->increaseWidth();
    if (GetMouseWheel() < 0)
        padle->decreaseWidth();

    CheckIfHitBorder(ball, testPointsVector, fElapsedTime);
    //ball->move(fElapsedTime);
    
    
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
            case 0:
                break;
            case 10:
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

bool Game::CheckIfHitBorder(Ball *ball, std::vector<std::pair<int, int>> &testPoints, float time)
{
    float TempBallPosY;
    float TempBallPosX;
         TempBallPosY = ball->position_.y - ball->direction_.y * 100.0 * time;
         TempBallPosX = ball->position_.x - ball->direction_.x * 100.0 * time;

        testPointsVector.clear();
        
    for (float angRad = 0, i = 0; angRad < 2 * M_PI; angRad += 0.5 * M_PI, i++)
    {
        testPointsVector.push_back(GetTemporaryTestPoints(angRad, ball));
        std::cout << "BallTestPoint For" << angRad << ": X Pos: " << testPointsVector.at(i).first << "  Y Pos: " << testPointsVector.at(i).second << std::endl;
    }
    std::cout << "X ball Pos: " << ball->getPos().x << "  Y Pos: " << ball->getPos().y << std::endl;
    std::cout << "X ball Dir: " << ball->getDirection().x << "  Y Dir: " << ball->getDirection().y << std::endl;

    for (auto &pair : testPoints)
    {

        if (pair.first <= spriteSize)
        {
            std::cout << "Zmieniam kierunek \n";
            olc::vf2d vector{-1, 1};
            ball->setDirection(vector);
            ball->move(time);
            //ball->move(time);
            return true;
        } 

        else if (pair.second < spriteSize)
        {
            std::cout << "Zmieniam kierunek \n";
            olc::vf2d vector{1, -1};
            ball->setDirection(vector);
            ball->move(time);
            //ball->move(time);
            return true;
        }

        else if (pair.first > ScreenWidth() - spriteSize)
        {
            std::cout << "Zmieniam kierunek \n";
            olc::vf2d vector{-1, 1};
            ball->setDirection(vector);
            ball->move(time);
            //ball->move(time);
            return true;
        }

/*         else if (pair.second > ScreenHeight() - spriteSize)
        {
            std::cout << "Zmieniam kierunek\n";
            olc::vf2d vector{1, -1};
            ball->setDirection(vector);
            ball->move(time);
            ball->move(time);
            return true;
        } */
        else if (pair.second > ScreenHeight()-3*spriteSize && pair.first > padle->getPos() && pair.first < (padle->getPos() + padle->getWidth()*spriteSize))
        {
            std::cout << "Zmieniam kierunek z paletki\n";
            olc::vf2d vector{1, -1};
            ball->setDirection(vector);
            ball->move(time);
            //ball->move(time);
            return true;
        } 

        else{
            
        }
        
                      
    }

            ball->position_.x = TempBallPosX;      //write setter, make private
            ball->position_.y = TempBallPosY; 
            return false;
}


    std::pair<int, int> Game::GetTemporaryTestPoints(float angle, Ball* ball) const{

    std::pair<int, int> testPointsPair;
    int x = ball->position_.x + ball->radius_ * cos(angle); 
    int y = ball->position_.y + ball->radius_ * sin(angle);
    testPointsPair = std::make_pair(x, y);

    return testPointsPair;
    }