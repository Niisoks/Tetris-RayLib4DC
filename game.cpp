#include "game.h"
#include "constants.h"
#include <random>
#include <kos.h>
#include <oggvorbis/sndoggvorbis.h>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    prev_buttons = 0;
    gameOver = false;
    score = 0;
    lastHeldMoveTime = 0.0;
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
    currentBlock.Draw(Constants::gridOffset, 11);
}

void Game::DrawNext(int offsetX, int offsetY){
    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(offsetX - 15, offsetY + 20);
            break;
        case 4:
            nextBlock.Draw(offsetX - 15, offsetY + 10);
            break;
        default:
            nextBlock.Draw(offsetX, offsetY);
            break;
    }
    
}

void Game::HandleInput() {
    if ((cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER)) != NULL) {
        state = (cont_state_t *)maple_dev_status(cont);

        if (state == NULL) {
            return;
        }

        uint16_t just_pressed = state->buttons & ~prev_buttons;

        double currentTime = GetTime();  
        prev_buttons = state->buttons; 

        switch (just_pressed) {
            case CONT_START:
                if(gameOver){
                    gameOver = false;
                    Reset();
                }
                break;

            case CONT_DPAD_LEFT:
                MoveBlockLeft();
                lastHeldMoveTime = currentTime + 0.1;
                break;

            case CONT_DPAD_RIGHT:
                MoveBlockRight();
                lastHeldMoveTime = currentTime + 0.1;
                break;

            case CONT_DPAD_DOWN:
                MoveBlockDown();
                UpdateScore(0, 1);
                lastHeldMoveTime = currentTime;
                break;

            case CONT_X:
                RotateBlock();
                break;

            default:
                break;
        }

        if (prev_buttons & (CONT_DPAD_LEFT | CONT_DPAD_RIGHT | CONT_DPAD_DOWN)) {
            if (currentTime - lastHeldMoveTime >= moveThreshold) {
                if (prev_buttons & CONT_DPAD_LEFT) {
                    MoveBlockLeft();
                }
                if (prev_buttons & CONT_DPAD_RIGHT) {
                    MoveBlockRight();
                }
                if (prev_buttons & CONT_DPAD_DOWN) {
                    MoveBlockDown();
                    UpdateScore(0, 1);
                }
                lastHeldMoveTime = currentTime;
            }
        }
    }
}

void Game::MoveBlockLeft(){
    if(gameOver) return;
    currentBlock.Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight(){
    if(gameOver) return;
    currentBlock.Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown(){
    if(gameOver) return;
    currentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(-1, 0);
        LockBlock();
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
    if(gameOver) return;
    currentBlock.Rotate();
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.UndoRotation();
    } else {
        sndoggvorbis_start("/rd/rotate.ogg", 0);
    }
}

void Game::LockBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    lastHeldMoveTime = 0;
    for(Position item: tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    if(rowsCleared > 0){
        sndoggvorbis_start("/rd/clear.ogg", 0);
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.isCellEmpty(item.row, item.column) == false){
            return false;
        }
    }
    return true;
}

void Game::Reset(){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints){
    switch(linesCleared){
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        case 4:
            score += 1000;
            break;
        default:
            break;
    }

    score += moveDownPoints;
}
