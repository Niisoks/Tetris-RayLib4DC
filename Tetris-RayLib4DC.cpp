// Code ported from https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2/blob/main/src/main.cpp without permission

#include <raylib.h>
#include <kos.h>
#include "ball.h"

KOS_INIT_FLAGS(INIT_DEFAULT);

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 640;
    const int screenHeight = 480;

    Ball ball = Ball();

    InitWindow(screenWidth, screenHeight, "Ball Template in KOS!");
    SetTargetFPS(60);

    while (1)
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        ball.Update();
        ball.Draw();
        EndDrawing();
    }


    return 0;
}