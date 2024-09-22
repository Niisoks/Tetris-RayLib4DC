#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
        Grid();
        void Initialize();
        void Print();
        void Draw();
        bool IsCellOutside(int row, int column);
        bool isCellEmpty(int row, int column);
        int grid[20][10];
    
    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};