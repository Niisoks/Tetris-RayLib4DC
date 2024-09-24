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
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        void MoveBlockLeft();
        void MoveBlockRight();
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
};