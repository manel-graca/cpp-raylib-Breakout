#include "paddle.hpp"

Paddle::Paddle(int x, int y, int width, int height, float speed)
{
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;
    this->speed = speed;
}

void Paddle::Draw()
{
    DrawRectangle(x, y, w, h, WHITE);
}

void Paddle::Update()
{
    if (IsKeyDown(KEY_LEFT || KEY_A))
        Move(true);
    if (IsKeyDown(KEY_RIGHT || KEY_D))
        Move(false);
}

void Paddle::Move(bool left)
{
    int paddlePos = x;
    int maxPaddlePosL = 0 + w / 2;
    int maxPaddlePosR = GetScreenWidth() - w / 2;
    if (left && paddlePos > maxPaddlePosL)
    {
        x -= speed;
    }
    else if (paddlePos < maxPaddlePosR)
    {
        x += speed;
    }
}