#include "../include/IDeitado.hpp"

int IDeitado::down(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if (gridGame.acessarGrid(x, y + 1, ACCESS) == 0 &&
        gridGame.acessarGrid(x + 1, y + 1, ACCESS) == 0 &&
        gridGame.acessarGrid(x + 2, y + 1, ACCESS) == 0 &&
        y + 1 < GRID_LINES)
    {
        gridGame.acessarGrid(x, y + 1, 1);
        gridGame.acessarGrid(x + 1, y + 1, 1);
        gridGame.acessarGrid(x + 2, y + 1, 1);

        gridGame.acessarGrid(x, y, 0);
        gridGame.acessarGrid(x + 1, y, 0);
        gridGame.acessarGrid(x + 2, y, 0);

        centro[Y] = y + 1;
    }
    else if (y == 0 &&
            (gridGame.acessarGrid(x, y + 1, ACCESS) == 1 ||
             gridGame.acessarGrid(x + 1, y + 1, ACCESS) == 1 ||
             gridGame.acessarGrid(x + 2, y + 1, ACCESS) == 1)) return GAME_OVER;

    else if (y + 1 == GRID_LINES || 
            gridGame.acessarGrid(x, y + 1, ACCESS)     == 1 ||
            gridGame.acessarGrid(x + 1, y + 1, ACCESS) == 1 ||  
            gridGame.acessarGrid(x + 2, y + 1, ACCESS) == 1) return REACHED_BOTTOM;
         
    return NO_REACHED_BOTTOM;
}

void IDeitado::left(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( gridGame.acessarGrid(x - 1, y, ACCESS) == 0 &&
        x > 0)
    {
        gridGame.acessarGrid(x - 1, y, 1);
        gridGame.acessarGrid(x + 2, y, 0);

        centro[X] = x - 1;
    }
}

void IDeitado::right(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( gridGame.acessarGrid(x + 3, y, ACCESS) == 0 &&
        x + 3 < GRID_COLUMNS)
    {
        gridGame.acessarGrid(x + 3, y, 1);
        gridGame.acessarGrid(x, y, 0);

        centro[X] = x + 1;
    }
}