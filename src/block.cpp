#include "block.hpp"

Block::Block(int id, float x, float y, float width, float height, Color color)
    : id(id), x(x), y(y), w(width), h(height), color(color)
{
    isDead = false;
}

void Block::Draw()
{
    if (isDead)
        return;
    DrawRectangle(x, y, w, h, color);
}

void Block::Hit()
{
    isDead = true;
}