#pragma once
#include "ball.hpp"
#include "block.hpp"
#include "paddle.hpp"
#include <raylib.h>
#include <vector>

// use the GameState enum
class Game
{
  public:
    Game();
    void Update();
    void Draw();
    void MoveDirection(float x, float y);
    void MovePaddle(bool left);
    void CheckCollision();
    void InitBlocks();
    int GetScore() { return score; }
    void GiveScore(int &i);
    void CheckBlocksCollision();
    void CheckPaddleCollision();
    void CheckBoundaryCollision();

  private:
    void Reset();
    int rows = 8;
    int cols = 47;
    std::vector<Vector2> positions;
    int xOffset = 5;
    int yOffset = 5;
    int topOffset = 60;
    Ball ball;
    Paddle paddle;
    std::vector<Block> blocks;
    int score;
};