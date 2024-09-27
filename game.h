#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <kos.h>

class Game{
    public:
        Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        void DrawNext(int offsetX, int offsetY);
        bool gameOver;
        int score;

    private:
        double lastHeldMoveTime;
        double floorContactTime = 0;
        double timeSinceLastRotation;
        bool IsBlockOutside();
        void RotateBlock(bool clockwise);
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        void MoveBlockLeft();
        void MoveBlockRight();
        void HardDrop();
        std::vector<Block> GetAllBlocks();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Block GetRandomBlock();
        Grid grid;
        uint16_t prev_buttons;
        maple_device_t *cont;
        cont_state_t *state;
        const double moveThreshold = 0.1;
        const double timerGraceBig = 2;
        const double timerGraceSmall = 0.4;
        static const int moves[15][2];
        sfxhnd_t sndClear;
        sfxhnd_t sndRotate;
};