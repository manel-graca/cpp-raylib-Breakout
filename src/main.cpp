#include "game.hpp"
#include <raylib.h>
const Color DARK_BLUE = {0, 0, 128, 255};

int main(int, char **)
{
    SetTargetFPS(60);
    InitWindow(680, 450, "Breakout");

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

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        // paddle.Update();
        // ball.Update();
        game.Update();
        BeginDrawing();
        ClearBackground(DARK_BLUE);
        // paddle.Draw();
        // ball.Draw();
        game.Draw();
        EndDrawing();
    }

    return 0;
}
