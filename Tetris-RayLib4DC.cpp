// Code ported from https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2/blob/main/src/main.cpp without permission

#include <raylib.h>
#include <kos.h>
#include "grid.h"

KOS_INIT_FLAGS(INIT_DEFAULT);

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 640;
    const int screenHeight = 480;

    Grid grid = Grid();
    grid.Print();

    InitWindow(screenWidth, screenHeight, "Tetris in KOS!");
    SetTargetFPS(60);

    while(1){
        BeginDrawing();
        ClearBackground(darkBlue);

        EndDrawing();
    }

    printf("Finishing - Cleaning up\n");

    return 0;
}