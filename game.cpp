#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    prev_buttons = 0;
    
}

Block Game::GetRandomBlock(){
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput() {
    if ((cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER)) != NULL) {
        state = (cont_state_t *)maple_dev_status(cont);

        if (state == NULL) {
            return;
        }

        uint16_t just_pressed = state->buttons & ~prev_buttons;

        prev_buttons = state->buttons;

        switch (just_pressed) {
            case CONT_DPAD_LEFT:
                MoveBlockLeft();
                break;

            case CONT_DPAD_RIGHT:
                MoveBlockRight();
                break;

            case CONT_DPAD_DOWN:
                MoveBlockDown();
                break;
            
            case CONT_X:
                RotateBlock();
                break;

            default:
                break;
        }
    }
}

void Game::MoveBlockLeft(){
    currentBlock.Move(0, -1);
    if(IsBlockOutside()){
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight(){
    currentBlock.Move(0, 1);
    if(IsBlockOutside()){
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown(){
    currentBlock.Move(1, 0);
    if(IsBlockOutside()){
        currentBlock.Move(-1, 0);
    }
}

bool Game::IsBlockOutside(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

void Game::RotateBlock(){
    currentBlock.Rotate();
    if(IsBlockOutside()){
        currentBlock.UndoRotation();
    }
}
