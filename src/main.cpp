#include "game.hpp"
#include <iostream>
#include <raylib.h>
const Color DARK_BLUE = {0, 0, 128, 255};

int main(int, char **)
{
    InitWindow(450, 650, "Breakout");
    SetTargetFPS(60);
    Font font = LoadFontEx("assets/fonts/arcadeclassic.regular.ttf", 64, 0, 250);
    if (font.texture.id == 0) // If font failed to load
    {
        std::cout << "Failed to load font!" << std::endl;
    }
    else
    {
        std::cout << "Font loaded successfully!" << std::endl;
    }
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.Update();

        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();

        std::string uiText;
        Vector2 uiPosition;
        uiText = TextFormat("SCORE: %03d", game.GetScore());
        uiPosition.x = 10;
        uiPosition.y = 10;
        if (!uiText.empty())
        {
            float textWidth = MeasureTextEx(font, uiText.c_str(), 40, 2).x;
            uiPosition.x = (float)(GetScreenWidth() / 2.0f - textWidth / 2);
            DrawTextEx(font, uiText.c_str(), uiPosition, 40, 2, WHITE);
        }

        EndDrawing();
    }

    UnloadFont(font);

    return 0;
}
