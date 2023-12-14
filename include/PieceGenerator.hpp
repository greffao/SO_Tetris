/**
 * @file PieceGenerator.hpp
 * @author @greffao
 * @brief A classe 'PieceGenerator' serve apenas para gerar uma nova
 *        peça aleatória para o jogador, sempre que a peça atual
 *        alcançar o chão do grid.
 *         
 *        The 'PieceGenerator' class serves solely to generate a new 
 *        random piece for the player whenever the current piece reaches 
 *        the bottom of the grid.
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PIECE_GEN_HPP
#define PIECE_GEN_HPP

#include <random>
#include <iostream>

#include "Piece.hpp"
#include "Square.hpp"
#include "L.hpp"
#include "I.hpp"
#include "IDeitado.hpp"

#define NUM_PIECES 4

class PieceGenerator
{
public:

public:

    /*Inserir novas peças aqui.*/
    Piece* newRandomPiece();
};

#endif