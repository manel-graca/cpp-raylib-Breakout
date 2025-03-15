#include "game.hpp"

Game::Game() : paddle(GetScreenWidth() / 2, GetScreenHeight() - 15 - 30, 140, 12, 4, {255, 174, 0, 255}), ball({(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, {1, -0.5}, 10, 3, {128, 128, 128, 255})
{
    /* int px = GetScreenWidth() / 2;
    int py = GetScreenHeight() - 15 - 30;
    int pw = 140;
    int ph = 12;
    float pspeed = 4;
    Color pcolor = {255, 174, 0, 255};
    Paddle paddle = Paddle(px, py, pw, ph, pspeed, pcolor);

    int bx = GetScreenWidth() / 2;
    int by = GetScreenHeight() / 2 - 50;
    int br = 10;
    float bspeed = 1.5;
    Color bcolor = {128, 128, 128, 255};
    Ball ball = Ball({(float)bx, (float)by}, {1, -0.5}, br, bspeed, bcolor); */
}

void Game::Draw()
{
    paddle.Draw();
    ball.Draw();
}

void Game::Update()
{
    paddle.Update();
    ball.Update();
    CheckCollision();
}

void Game::MoveDirection(float x, float y)
{
    ball.MoveDirection(x, y);
}

void Game::MovePaddle(bool left)
{
    paddle.Move(left);
}

void Game::CheckCollision()
{
    // Check collision with paddle
    if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddle.GetRec()))
    {
        ball.MoveDirection(ball.GetDirection().x, -ball.GetDirection().y);
    }
    // Check collision with bottom edge
    else if (ball.GetPosition().y + ball.GetRadius() >= GetScreenHeight())
    {
        ball.MoveDirection(ball.GetDirection().x, -ball.GetDirection().y);
    }
    // Check collision with top edge
    else if (ball.GetPosition().y - ball.GetRadius() <= 0)
    {
        ball.MoveDirection(ball.GetDirection().x, -ball.GetDirection().y);
    }
    // Check collision with right edge
    else if (ball.GetPosition().x + ball.GetRadius() >= GetScreenWidth())
    {
        ball.MoveDirection(-ball.GetDirection().x, ball.GetDirection().y);
    }
    // Check collision with left edge
    else if (ball.GetPosition().x - ball.GetRadius() <= 0)
    {
        ball.MoveDirection(-ball.GetDirection().x, ball.GetDirection().y);
    }
}
