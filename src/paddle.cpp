#include "paddle.hpp"

Paddle::Paddle(float x, float y, float width, float height, float speed, Color color)
    : x(x), y(y), w(width), h(height), speed(speed), color(color) { }

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

void Paddle::Reset()
{
    x = GetScreenWidth() / 2.0f - w / 2;
    y = GetScreenHeight() - 15 - 30;
}
