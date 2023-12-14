#ifndef I_HPP
#define I_HPP

#include <iostream>

#include "Piece.hpp"

#define ID_I 3

class I : public Piece
{
public:
    const int id = ID_I;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif