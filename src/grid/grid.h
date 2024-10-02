#pragma once
#include <vector>
#include <raylib.h>
#include "../animation/animation.h"

class Grid{
    public:
        Grid();
        void Initialize();
        void Print();
        void Draw();
        bool IsCellOutside(int row, int column);
        bool isCellEmpty(int row, int column);
        int ClearFullRows();
        int grid[20][10];
    
    private:
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
        Texture2D lineClearTexture;
        SpriteAnimation lineClearAnimation;
};