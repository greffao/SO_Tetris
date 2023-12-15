#ifndef T_HPP
#define T_HPP

#include "Piece.hpp"

#define ID_T 5

class T : public Piece
{
public:
    const int id = ID_T;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif