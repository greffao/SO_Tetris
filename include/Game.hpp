/**
 * @file Game.hpp
 * @author @greffao
 * @brief A classe 'Game' implementa toda a lógica do jogo: a movimentação
 *        e colisão das peças, os comandos do jogador, a detecção de uma
 *        linha completa, a atualização do grid e a computação do score.
 * 
 *        The 'Game' class implements the entire logic of the game: the 
 *        movement and collision of pieces, player commands, detection of 
 *        a completed line, grid updates, and score computation.
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <thread>
#include <mutex>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <queue>

#include "TetrisGrid.hpp"
#include "Buffer.hpp"
#include "Piece.hpp"
#include "Square.hpp"
#include "PieceGenerator.hpp"

#define TIME 50

class Game
{
public:
    TetrisGrid gridGame;
    bool inPlay;
    int score;

public:
    Game();

    /*Note que nestas funções, há o uso de semáforos, pois a
    variável inPlay pode ser acessada pela thread t_game e
    pela main.*/
    void start(Buffer& buffer);
    void end(Buffer& buffer);

    void play(Buffer& buffer);

    void draw(sf::RenderWindow& window);
};

#endif