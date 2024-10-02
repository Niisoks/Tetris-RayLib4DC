#include "animation.h"
#include <stdlib.h>

void SpriteAnimation::DrawSpriteAnimationPro(Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    int index = (int)(GetTime() * framesPerSecond) % rectanglesLength;

    Rectangle source = rectangles[index];
    DrawTexturePro(atlas, source, dest, origin, rotation, tint);
}

SpriteAnimation::SpriteAnimation(Texture2D atlas, int framesPerSecond, Rectangle rectangles[], int length)
{
    this->atlas = atlas;
    this->framesPerSecond = framesPerSecond;
    this->rectanglesLength = length;

    Rectangle* mem = (Rectangle*)malloc(sizeof(Rectangle) * length);

    if(mem == NULL){
        printf("FATAL! No memory for CreateSpriteAnimation!");
        this->rectanglesLength = 0;
    }

    this->rectangles = mem;

    for (int i = 0; i < length; i++){
        this->rectangles[i] = rectangles[i];
    }
}

SpriteAnimation::~SpriteAnimation()
{
    delete[] rectangles;
}
