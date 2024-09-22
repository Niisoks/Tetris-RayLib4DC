// Code ported from https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2/blob/main/src/main.cpp without permission

#include <raylib.h>
#include <kos.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

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
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    printf("Finishing - Cleaning up\n");

    return 0;
}