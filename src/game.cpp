#include "game.hpp"
#include "colors.hpp"
#include <cmath>
#include <iostream>
#include <vector>

Game::Game() : paddle(GetScreenWidth() / 2.0f - 50.0f / 2, GetScreenHeight() - 15 - 30, 50, 10, 5, {255, 174, 0, 255}),
               ball({(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, {1, -0.5}, 4, 8, {255, 217, 0, 255})
{
    score = 0;
    InitBlocks();
}

void Game::InitBlocks()
{
    int w = 25;
    int h = 5;
    for (int i = 0; i < rows; i++)
    {
        int colorIndex = i / 2;
        Color color = blockColors[colorIndex];
        int id = i / 2;

        for (int j = 0; j < cols; j++)
        {
            float x = (GetScreenWidth() - (cols * (w + xOffset) - xOffset)) / 2.0f + j * (w + xOffset);
            float y = topOffset + yOffset + i * (h + yOffset); // Add topOffset once

            blocks.push_back(Block(id, x, y, w, h, color));
        }
    }
}

void Game::Draw()
{
    paddle.Draw();
    ball.Draw();
    for (int i = 0; i < blocks.size(); i++)
    {
        blocks[i].Draw();
    }
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
    CheckBlocksCollision();
    CheckPaddleCollision();
    CheckBoundaryCollision();
}

void Game::GiveScore(int &i)
{
    switch (blocks[i].GetId())
    {
    case 0:
        score += 1;
        break;
    case 1:
        score += 2;
        break;
    case 2:
        score += 5;
        break;
    case 3:
        score += 10;
        break;
    }
}
void Game::CheckBlocksCollision()
{
    Rectangle ballBoundingBox = {
        ball.GetPosition().x - ball.GetRadius(),
        ball.GetPosition().y - ball.GetRadius(),
        (float)ball.GetRadius() * 2,
        (float)ball.GetRadius() * 2};

    for (int i = blocks.size() - 1; i >= 0; i--) // Iterate backwards to avoid skipping blocks
    {
        Rectangle blockRec = blocks[i].GetRec();
        if (CheckCollisionRecs(ballBoundingBox, blockRec))
        {
            std::cout << "Checking block " << i << std::endl;

            if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), blocks[i].GetRec()))
            {
                GiveScore(i);
                std::cout << "Hitting block " << blocks[i].GetId() << " Score: " << score << std::endl;
                blocks[i].Hit();

                // Get ball & block positions
                Vector2 ballPos = ball.GetPosition();
                Rectangle blockRec = blocks[i].GetRec();

                // Check collision side (LEFT, RIGHT, TOP, BOTTOM)
                float ballLeft = ballPos.x - ball.GetRadius();
                float ballRight = ballPos.x + ball.GetRadius();
                float ballTop = ballPos.y - ball.GetRadius();
                float ballBottom = ballPos.y + ball.GetRadius();

                float blockLeft = blockRec.x;
                float blockRight = blockRec.x + blockRec.width;
                float blockTop = blockRec.y;
                float blockBottom = blockRec.y + blockRec.height;

                // Find the closest collision side
                float overlapLeft = fabs(ballRight - blockLeft);
                float overlapRight = fabs(ballLeft - blockRight);
                float overlapTop = fabs(ballBottom - blockTop);
                float overlapBottom = fabs(ballTop - blockBottom);

                // Determine which side has the **smallest overlap** (closest collision)
                if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom)
                {
                    // Hit the left side -> Reflect X direction
                    ball.MoveDirection(-fabs(ball.GetDirection().x), ball.GetDirection().y);
                }
                else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom)
                {
                    // Hit the right side -> Reflect X direction
                    ball.MoveDirection(fabs(ball.GetDirection().x), ball.GetDirection().y);
                }
                else if (overlapTop < overlapBottom)
                {
                    // Hit the top -> Reflect Y direction
                    ball.MoveDirection(ball.GetDirection().x, -fabs(ball.GetDirection().y));
                }
                else
                {
                    // Hit the bottom -> Reflect Y direction
                    ball.MoveDirection(ball.GetDirection().x, fabs(ball.GetDirection().y));
                }

                // Remove the block after handling collision
                blocks.erase(blocks.begin() + i);
            }
        }
    }
}

void Game::CheckPaddleCollision()
{
    if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddle.GetRec()))
    {
        // Get paddle's center X position
        float paddleCenterX = paddle.GetRec().x + paddle.GetRec().width / 2;

        // Get ball's current X position
        float ballX = ball.GetPosition().x;

        // Reflect Y direction
        ball.MoveDirection(ball.GetDirection().x, -ball.GetDirection().y);

        // Change X direction based on where the ball hit
        if (ballX < paddleCenterX)
        {
            ball.MoveDirection(-fabs(ball.GetDirection().x), ball.GetDirection().y); // Move left
        }
        else
        {
            ball.MoveDirection(fabs(ball.GetDirection().x), ball.GetDirection().y); // Move right
        }
    }
}

void Game::Reset()
{
    paddle.Reset();
    ball.Reset();
    score = 0;
    blocks.clear();
    InitBlocks();
}

void Game::CheckBoundaryCollision()
{
    // Check collision with bottom edge
    if (ball.GetPosition().y + ball.GetRadius() >= GetScreenHeight())
    {
        Reset();
        return;
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