#include "../include/L.hpp"

int L::down(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if ( y + 2 == GRID_LINES || 
              gridGame.acessarGrid(x, y + 2, ACCESS) == 1 ||
              gridGame.acessarGrid(x + 1, y + 2, ACCESS) == 1 ) return REACHED_BOTTOM;

    if ( y == 0 &&
              ( gridGame.acessarGrid(x, y + 2, ACCESS) == 1 ||
                gridGame.acessarGrid(x + 1, y + 2, ACCESS) == 1 )) return GAME_OVER;


    gridGame.acessarGrid(x, y + 2, 1);
    gridGame.acessarGrid(x + 1, y + 2, 1);

    gridGame.acessarGrid(x, y + 1, 0);
    gridGame.acessarGrid(x + 1, y, 0);

    centro[Y] = y + 1;

    return NO_REACHED_BOTTOM;
}

void L::left(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x > 0 &&
        gridGame.acessarGrid(x - 1, y, ACCESS) == 0 && 
        gridGame.acessarGrid(x - 1, y + 1, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x, y, 1);
        gridGame.acessarGrid(x - 1, y + 1, 1);

        gridGame.acessarGrid(x + 1, y, 0);
        gridGame.acessarGrid(x + 1, y + 1, 0);

        centro[X] = x - 1;
    }
}

void L::right(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x + 2 < GRID_COLUMNS &&
        gridGame.acessarGrid(x + 2, y, ACCESS) == 0 && 
        gridGame.acessarGrid(x + 2, y + 1, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x + 2, y, 1);
        gridGame.acessarGrid(x + 2, y + 1, 1);


        gridGame.acessarGrid(x + 1, y, 0);
        gridGame.acessarGrid(x, y + 1, 0);

        centro[X] = x + 1;
    }
}