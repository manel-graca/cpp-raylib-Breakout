#pragma once
#include "ball.hpp"
#include "paddle.hpp"
#include <raylib.h>

class Game
{
  public:
    Game();
    void Update();
    void Draw();
    void MoveDirection(float x, float y);
    void MovePaddle(bool left);
    void CheckCollision();

  private:
    Ball ball;
    Paddle paddle;
};