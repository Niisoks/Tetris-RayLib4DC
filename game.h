#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <kos.h>

class Game{
    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        Grid grid;
        bool gameOver;

    private:
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        uint16_t prev_buttons;
        maple_device_t *cont;
        cont_state_t *state;
};