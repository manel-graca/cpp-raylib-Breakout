#include <raylib.h>
class Paddle
{
  public:
    Paddle(int x, int y, int width, int height, float speed);
    void Draw();
    void Update();
    void Move(bool left);

  private:
    int x, y, w, h;
    float speed;
};