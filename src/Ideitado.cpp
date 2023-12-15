#include "../include/IDeitado.hpp"

int IDeitado::down(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    int a = gridGame.acessarGrid(x, y + 1, ACCESS);
    int b = gridGame.acessarGrid(x + 1, y + 1, ACCESS);
    int c = gridGame.acessarGrid(x + 2, y + 1, ACCESS);

    if (y == 0 && (a != 0 || b != 0 || c != 0)) return GAME_OVER;

    if (y + 1 == GRID_LINES || a != 0 || b != 0 || c != 0) return REACHED_BOTTOM;

    gridGame.acessarGrid(x, y + 1, ID_DEITADO);
    gridGame.acessarGrid(x + 1, y + 1, ID_DEITADO);
    gridGame.acessarGrid(x + 2, y + 1, ID_DEITADO);

    gridGame.acessarGrid(x, y, 0);
    gridGame.acessarGrid(x + 1, y, 0);
    gridGame.acessarGrid(x + 2, y, 0);

    centro[Y] = y + 1;
         
    return NO_REACHED_BOTTOM;
}

void IDeitado::left(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x > 0 && gridGame.acessarGrid(x - 1, y, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x - 1, y, ID_DEITADO);
        gridGame.acessarGrid(x + 2, y, 0);

        centro[X] = x - 1;
    }
}

void IDeitado::right(TetrisGrid& gridGame)
{
    int x = centro[X];
    int y = centro[Y];

    if( x + 3 < GRID_COLUMNS && gridGame.acessarGrid(x + 3, y, ACCESS) == 0 )
    {
        gridGame.acessarGrid(x + 3, y, ID_DEITADO);
        gridGame.acessarGrid(x, y, 0);

        centro[X] = x + 1;
    }
}