// Code ported from https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2/blob/main/src/main.cpp without permission

#include <raylib.h>
#include <kos.h>
#include "game.h"

KOS_INIT_FLAGS(INIT_DEFAULT);

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Tetris in KOS!");
    SetTargetFPS(60);

    Game game = Game();

    while(1){
        BeginDrawing();
        game.Draw();
        EndDrawing();
    }

    printf("Finishing - Cleaning up\n");

    return 0;
}