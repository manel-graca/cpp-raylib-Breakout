#include "paddle.hpp"
Paddle::Paddle(float x, float y, float width, float height, float speed, Color color)
{
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;
    this->speed = speed;
    this->color = color;
}

void Paddle::Draw()
{
    DrawRectangle(x, y, w, h, color);
}

void Paddle::Update()
{
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        Move(true);
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        Move(false);
}

void Paddle::Move(bool left)
{
    int paddlePos = x;
    int maxPaddlePosL = 0;
    int maxPaddlePosR = GetScreenWidth() - w;

    if (left && paddlePos > maxPaddlePosL)
    {
        x -= speed;
    }
    else if (!left && paddlePos < maxPaddlePosR)
    {
        x += speed;
    }
}
