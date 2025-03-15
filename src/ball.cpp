#include "ball.hpp"
#include <raylib.h>

Ball::Ball(Vector2 position, Vector2 direction, int radius, float speed, Color color)
{
    this->position = position;
    this->direction = direction;
    this->r = radius;
    this->speed = speed;
    this->color = color;
}

void Ball::Draw()
{
    DrawCircleV(position, r, color);
}

void Ball::Update()
{
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Ball::MoveDirection(float x, float y)
{
    direction.x = x;
    direction.y = y;
}
