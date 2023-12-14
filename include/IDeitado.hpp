#ifndef IDEITADO_HPP
#define IDEITADO_HPP

#include <iostream>

#include "Piece.hpp"

#define ID_DEITADO 4

class IDeitado : public Piece
{
public:
    const int id = ID_DEITADO;

public:
    int down(TetrisGrid& gridGame) override;
    void left(TetrisGrid& gridGame) override;
    void right(TetrisGrid& gridGame) override;
};

#endif