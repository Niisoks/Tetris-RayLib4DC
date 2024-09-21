#include "grid.h"
#include <kos.h>

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 24;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize(){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            grid[row][column] = 0;
        }
    }
}

void Grid::Print(){
    printf("Printing Grid");
    for(int row =0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            printf("%d ", grid[row][column]);
        }
        printf("\n");
    }
}

std::vector<Color> Grid::GetCellColors(){
    const Color darkGrey = {26, 31, 40, 255};
    const Color green = {47, 230, 23, 255};
    const Color red = {232, 18, 18, 255};
    const Color orange = {226, 116, 17, 255};
    const Color yellow = {237, 234, 4, 255};
    const Color purple = {166, 0, 247, 255};
    const Color cyan = {21, 204, 209, 255};
    const Color blue = {13, 64, 216, 255};
    const Color lightBlue = {59, 85, 162, 255};
    const Color darkBlue = {44, 44, 127, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::Draw(){
    for (int row = 0; row < numRows; row++){
        for (int column = 0; column < numCols; column++){
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
        
    }
    
}