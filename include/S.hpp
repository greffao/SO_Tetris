#ifndef S_HPP
#define S_HPP

#include "Piece.hpp"

#define ID_S 7

class S : public Piece
{
public:
    const int id = ID_S;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif