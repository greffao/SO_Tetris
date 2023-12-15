#include "../include/TetrisGrid.hpp"
#include <iostream>
#include <cstring>

std::mutex mt_grid;

TetrisGrid::TetrisGrid()
{   
    for (int i = 0; i < GRID_COLUMNS; ++i)
    {
        for (int j = 0; j < GRID_LINES; ++j)
        {
            grid[i][j] = 0;

            gridSquares[i][j] = sf::RectangleShape(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));
            gridSquares[i][j].setPosition(GRID_X + i * (SQUARE_SIDE + SQUARE_SPACE), 
                                          GRID_Y + j * (SQUARE_SIDE + SQUARE_SPACE));
        }
    }

    gridShow = true;
}

void TetrisGrid::hide() {gridShow = false;}

void TetrisGrid::show() {gridShow = true;}

void TetrisGrid::atualizaGridSquares()
{
    for (int i = 0; i < GRID_COLUMNS; ++i)
    {
        for (int j = 0; j < GRID_LINES; ++j)
        {
            if(acessarGrid(i, j, ACCESS) == 0)
            {
                gridSquares[i][j].setFillColor(sf::Color(128, 128, 128));
            }
            else if(acessarGrid(i, j, ACCESS) == 1)
            {
                gridSquares[i][j].setFillColor(sf::Color(128, 0, 0));
            }
            else if(acessarGrid(i, j, ACCESS) == 2)
            {
                gridSquares[i][j].setFillColor(sf::Color(0, 128, 0));
            }
            else if(acessarGrid(i, j, ACCESS) == 3)
            {
                gridSquares[i][j].setFillColor(sf::Color(0, 0, 128)); 
            }
            else if(acessarGrid(i, j, ACCESS) == 4)
            {
                gridSquares[i][j].setFillColor(sf::Color(255, 255, 255)); 
            }
            else if(acessarGrid(i, j, ACCESS) == 5)
            {
                gridSquares[i][j].setFillColor(sf::Color(0, 0, 255)); 
            }
            else if(acessarGrid(i, j, ACCESS) == 6)
            {
                gridSquares[i][j].setFillColor(sf::Color(0, 255, 0)); 
            }
            else if(acessarGrid(i, j, ACCESS) == 7)
            {
                gridSquares[i][j].setFillColor(sf::Color(255, 0, 0)); 
            }
        }
    }
}

void TetrisGrid::draw(sf::RenderWindow& window)
{
    atualizaGridSquares();

    for (int i = 0; i < GRID_COLUMNS; i++)
    {
        for (int j = 2; j < GRID_LINES; j++)
        {
            window.draw(gridSquares[i][j]);
        }
    }
}

void TetrisGrid::resetGrid()
{
    mt_grid.lock();

    std::memset(grid, 0, sizeof(grid));

    mt_grid.unlock();
}

int TetrisGrid::acessarGrid(int coluna, int linha, int conteudo) {
    mt_grid.lock();

    /*Descomente esta parte do código, se quiser printar o grid no terminal.*/
    // for (int i = 0; i < GRID_COLUMNS; i++)
    // {
    //     for (int j = 0; j < GRID_LINES; j++)
    //     {
    //         std::cout << grid[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << "----------------------------------" << std::endl;

    if (conteudo != -1)
    {
        grid[coluna][linha] = conteudo;
        mt_grid.unlock();

        return -1;
    }
    else
    {
        int retorno = grid[coluna][linha];
        mt_grid.unlock();
    
        return retorno;
    }
}