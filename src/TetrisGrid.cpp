#include "../include/TetrisGrid.hpp"

TetrisGrid::TetrisGrid()
{
    for (int i = 0; i < gridLines; ++i)
    {
        for (int j = 0; j < gridColumns; ++j)
            grid[i][j] = 0;
    }
}

