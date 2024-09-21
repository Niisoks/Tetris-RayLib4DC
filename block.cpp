#include "block.h"

Block::Block(){
    cellSize = 24;
    rotationState = 0;
    colors = GetCellColors();
}

void Block::Draw(){
    std::vector<Position> tiles = cells[rotationState];
    for(Position item: tiles){
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize -1, colors[id]);
    }
}