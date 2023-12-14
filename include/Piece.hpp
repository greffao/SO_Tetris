/**
 * @file Piece.hpp
 * @author @greffao
 * @brief A classe 'Piece' é uma classe abstrara que serve de base para
 *        todas as peças do jogo. Polimorfismo é usado para lidar com
 *        as peças, por isso que esta classe é importante.
 * 
 *        The 'Piece' class is an abstract class that serves as the base 
 *        for all game pieces. Polymorphism is used to handle the pieces, 
 *        which is why this class is important.
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PIECE_HPP
#define PIECE_HPP

#include <thread>
#include <mutex>

#include "TetrisGrid.hpp"

#define X 0
#define Y 1

#define REACHED_BOTTOM 0
#define NO_REACHED_BOTTOM 1
#define GAME_OVER 2

class Piece
{
public:
    int centro[2];
    std::mutex mt_piece;

public:
    /*Construtor coloca a peça na sua posição inicial.*/
    Piece();
    virtual ~Piece() {};

    virtual int down(TetrisGrid& gridGame) = 0;
    virtual void left(TetrisGrid& gridGame) = 0;
    virtual void right(TetrisGrid& gridGame) = 0;

};

#endif