#include "../include/I.hpp"

int I::down(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    int bottom = gridGame.acessarGrid(x, y + 3, ACCESS);

    if ( y == 0 && bottom != 0 ) return GAME_OVER;

    if (y + 3 == GRID_LINES || bottom != 0) return REACHED_BOTTOM;

    gridGame.acessarGrid(x, y + 3, ID_I);

    gridGame.acessarGrid(x, y, 0);

    centro[Y] = y + 1;
         
    return NO_REACHED_BOTTOM;
}

void I::left(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x > 0 &&
        gridGame.acessarGrid(x - 1, y, ACCESS) == 0 && 
        gridGame.acessarGrid(x - 1, y + 1, ACCESS) == 0 &&
        gridGame.acessarGrid(x - 1, y + 2, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x - 1, y, ID_I);
        gridGame.acessarGrid(x - 1, y + 1, ID_I);
        gridGame.acessarGrid(x - 1, y + 2, ID_I);

        gridGame.acessarGrid(x, y, 0);
        gridGame.acessarGrid(x, y + 1, 0);
        gridGame.acessarGrid(x, y + 2, 0);

        centro[X] = x - 1;
    }
}

void I::right(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x + 1 < GRID_COLUMNS && 
        gridGame.acessarGrid(x + 1, y, ACCESS) == 0 && 
        gridGame.acessarGrid(x + 1, y + 1, ACCESS) == 0 &&
        gridGame.acessarGrid(x + 1, y + 2, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x + 1, y, ID_I);
        gridGame.acessarGrid(x + 1, y + 1, ID_I);
        gridGame.acessarGrid(x + 1, y + 2, ID_I);

        gridGame.acessarGrid(x, y, 0);
        gridGame.acessarGrid(x, y + 1, 0);
        gridGame.acessarGrid(x, y + 2, 0);

        centro[X] = x + 1;
    }
}