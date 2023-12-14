#include "../include/PieceGenerator.hpp"

Piece* PieceGenerator::newRandomPiece()
{
    int n = rand() % NUM_PIECES + 1;

    switch (n)
    {
    case 1:
        return new Square();
        break;
    
    default:
        break;
    }

    return NULL;
}