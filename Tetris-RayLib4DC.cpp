// Code ported from https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2/blob/main/src/main.cpp without permission

#include <raylib.h>
#include <kos.h>
#include "game.h"
#include "constants.h"
#include "colors.h"

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

int main(){
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Tetris in KOS!");
    SetTargetFPS(60);

    // TODO: Come back to this and learn to load a font and use DrawTextEx
    // Font font = LoadFontEx("/rd/font.ttf", 64, 0, 0);

    Game game = Game();

    int TextUIDistance = Constants::gridWidthWithOffset + UIPadding::large;
    int scorePaddingHeight = UIPadding::medium;
    int scoreBoxPaddingHeight = scorePaddingHeight + 15 + UIPadding::small;
    int nextPaddingHeight = scoreBoxPaddingHeight + 60 + UIPadding::large;
    int nextBoxPaddingHeight = nextPaddingHeight + UIFont::medium + UIPadding::small;
    int gameOverPaddingHeight = nextBoxPaddingHeight + 180 + UIPadding::large;

    while(1){
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        DrawText("Score", TextUIDistance, scorePaddingHeight, UIFont::medium, WHITE);
        DrawRectangleRounded({Constants::gridWidthWithOffset + UIPadding::medium, (float)scoreBoxPaddingHeight, 170, 60}, 0.3, 6, lightBlue);
        DrawText("Next", TextUIDistance,  nextPaddingHeight, UIFont::medium, WHITE);
        DrawRectangleRounded({Constants::gridWidthWithOffset + UIPadding::medium, (float)nextBoxPaddingHeight, 170, 180}, 0.3, 6, lightBlue);
        if(game.gameOver){
            DrawText("GAME OVER\nPress start!", TextUIDistance, gameOverPaddingHeight, UIFont::medium, WHITE);
        }
        EndDrawing();
    }

    printf("Finishing - Cleaning up\n");

    return 0;
}