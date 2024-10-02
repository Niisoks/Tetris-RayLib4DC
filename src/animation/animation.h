#pragma once

#include <kos.h>
#include <dc/syscalls.h>
#include <sys/types.h>
#include <raylib.h>

class SpriteAnimation{
private:
    Texture2D atlas;
    int framesPerSecond;

    Rectangle* rectangles;
    int rectanglesLength;
public:
    SpriteAnimation() : atlas{}, framesPerSecond{0}, rectangles{nullptr}, rectanglesLength{0} {}
    SpriteAnimation(Texture2D atlas, int framesPerSecond, Rectangle rectangles[], int length);
    ~SpriteAnimation();
    void DrawSpriteAnimationPro(Rectangle dest, Vector2 origin, float rotation, Color tint);
};