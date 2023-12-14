#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>

#include "Piece.hpp"

#define ID_SQUARE 1

class Square : public Piece
{
public:
    const int id = ID_SQUARE;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif