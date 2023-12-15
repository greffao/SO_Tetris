#include "../include/S.hpp"

int S::down(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    int a = gridGame.acessarGrid(x - 1, y + 2, ACCESS);
    int b = gridGame.acessarGrid(x + 1, y + 1, ACCESS);
    int c = gridGame.acessarGrid(x, y + 2, ACCESS); 

    if ( y == 0 && ( a != 0 || b != 0 || c != 0) ) return GAME_OVER;

    if ( y + 2 == GRID_LINES || a != 0 || b != 0  || c != 0) return REACHED_BOTTOM;

    gridGame.acessarGrid(x - 1, y + 2, ID_S);
    gridGame.acessarGrid(x + 1, y + 1, ID_S);
    gridGame.acessarGrid(x, y + 2, ID_S);

    gridGame.acessarGrid(x, y, 0);
    gridGame.acessarGrid(x + 1, y, 0);
    gridGame.acessarGrid(x - 1, y + 1, 0);

    centro[Y] = y + 1;

    return NO_REACHED_BOTTOM;
}

void S::left(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x > 0 &&
        gridGame.acessarGrid(x - 1, y, ACCESS) == 0 && 
        gridGame.acessarGrid(x - 2, y + 1, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x - 2, y + 1, ID_S);
        gridGame.acessarGrid(x - 1, y, ID_S);

        gridGame.acessarGrid(x + 1, y, 0);
        gridGame.acessarGrid(x, y + 1, 0);

        centro[X] = x - 1;
    }
}

void S::right(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x + 2 < GRID_COLUMNS && 
        gridGame.acessarGrid(x + 2, y, ACCESS) == 0 && 
        gridGame.acessarGrid(x + 1, y + 1, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x + 2, y, ID_S);
        gridGame.acessarGrid(x + 1, y + 1, ID_S);

        gridGame.acessarGrid(x - 1, y + 1, 0);
        gridGame.acessarGrid(x, y, 0);

        centro[X] = x + 1;
    }
}