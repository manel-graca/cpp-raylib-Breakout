#pragma once

#include <raylib.h>

class Block
{
  public:
    Block(int id, float x, float y, float width, float height, Color color);
    void Draw();
    Rectangle GetRec() { return {x, y, w, h}; }
    void Hit();
    Color GetColor() { return color; }
    int GetId() { return id; }

  private:
    int id;
    float x, y, w, h;
    Color color;
    bool isDead;
};