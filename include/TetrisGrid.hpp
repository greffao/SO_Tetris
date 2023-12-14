/**
 * @file TetrisGrid.hpp
 * @author @greffao
 * @brief Classe 'TetrisGrid' que implementa a grade do jogo, onde as
 *        peças se movimentam. Note que há o uso de semáforos, visto
 *        que o grid é acessado pela main e pela thread t_game.
 * 
 *        Class 'TetrisGrid' that implements the game grid, where the 
 *        pieces move. Note that there's the use of semaphores since 
 *        the grid is accessed by both the main function and the t_game 
 *        thread.
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TETRIS_GRID_HPP
#define TETRIS_GRID_HPP

#include <SFML/Graphics.hpp>
#include <mutex>

/*Lado do quadrado do gridSquares*/
#define SQUARE_SIDE 20
/*Espacinho entre os quadrados*/
#define SQUARE_SPACE 2

/*Posição do grid*/
#define GRID_X 300
#define GRID_Y 10

/*Número de linhas e colunas do grid*/
#define GRID_COLUMNS 10
#define GRID_LINES 20

/*Flag que indica o tipo de acesso do grid*/
#define ACCESS -1

class TetrisGrid
{
public:
    bool gridShow;
    int grid[GRID_COLUMNS][GRID_LINES];

    sf::RectangleShape gridSquares[GRID_COLUMNS][GRID_LINES];

public:
    TetrisGrid();

    void hide();
    void show();

    /*Funções de acesso ao grid. Note que há o uso de semáforos, pois o
    grid é acessado pela thread t_game e pela linha principal do programa.*/
    void atualizaGridSquares();
    int acessarGrid(int coluna, int linha, int conteudo);
    void resetGrid();

    void draw(sf::RenderWindow& window);
};

#endif