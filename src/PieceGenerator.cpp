#include "../include/PieceGenerator.hpp"

Piece* PieceGenerator::newRandomPiece()
{
    int n = rand() % NUM_PIECES + 1;

    switch (n)
    {
    case 1:
        return new Square();
        break;
    
    case 2:
        return new L();
        break;
    
    case 3:
        return new I();
        break;

    case 4:
        return new IDeitado();
        break;
    }

    return NULL;
}