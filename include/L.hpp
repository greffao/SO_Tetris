#ifndef L_HPP
#define L_HPP

#include <iostream>

#include "Piece.hpp"

#define ID_L 2

class L : public Piece
{
public:
    const int id = ID_L;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif