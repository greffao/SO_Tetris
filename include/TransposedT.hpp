#ifndef TRANSPOSED_T_HPP
#define TRANSPOSED_T_HPP

#include "Piece.hpp"

#define ID_TRANSPOSED_T 6

class TransposedT : public Piece
{
public:
    const int id = ID_TRANSPOSED_T;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif