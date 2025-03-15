#pragma once
#include <raylib.h>
class Paddle
{
  public:
    Paddle(float x, float y, float width, float height, float speed, Color color);
    void Draw();
    void Update();
    void Move(bool left);
    Rectangle GetRec() { return {x, y, w, h}; }

  private:
    float x, y, w, h, speed;
    Color color;
};