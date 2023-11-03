#ifndef TETRIS_GRID_HPP
#define TETRIS_GRID_HPP

class TetrisGrid
{
private:
    static const int gridColumns = 10;
    static const int gridLines = 20;

    int grid[gridLines][gridColumns];

public:

    /**
     * @brief Construtor do TetrisGrid que inicializa
     * todos os espaços da matriz 'grid' com 0.
     */
    TetrisGrid();

    int** getGrid();

};

#endif