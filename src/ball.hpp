#pragma once

#include <raylib.h>

class Ball
{
  public:
    Ball(Vector2 position, Vector2 direction, int radius, float speed, Color color);
    void Draw();
    void Update();
    void MoveDirection(float x, float y);
    Vector2 GetPosition() { return position; }
    int GetRadius() { return r + 0.01; }
    Vector2 GetDirection() { return direction; }
    void Reset();

  private:
    Vector2 position;
    Vector2 direction;
    int r;
    float speed;
    Color color;
};
