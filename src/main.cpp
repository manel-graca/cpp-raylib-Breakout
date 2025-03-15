#include "paddle.hpp"
#include <raylib.h>
const Color DARK_BLUE = {0, 0, 128, 255};

int main(int, char **)
{
    SetTargetFPS(60);
    InitWindow(800, 450, "Breakout");

    Paddle paddle = Paddle(GetScreenWidth() / 2, GetScreenHeight() - 15 - 30, 160, 15, 4);

    while (WindowShouldClose() == false)
    {
        paddle.Update();
        BeginDrawing();
        ClearBackground(DARK_BLUE);
        paddle.Draw();
        EndDrawing();
    }

    return 0;
}
