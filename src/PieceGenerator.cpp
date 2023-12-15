#include "../include/PieceGenerator.hpp"

Piece* PieceGenerator::newRandomPiece()
{
    int n = rand() % NUM_PIECES + 1;

    switch (n)
    {
    case ID_SQUARE:
        return new Square();
        break;
    
    case ID_L:
        return new L();
        break;
    
    case ID_I:
        return new I();
        break;

    case ID_DEITADO:
        return new IDeitado();
        break;
    case ID_T:
        return new T();
        break;
    case ID_TRANSPOSED_T:
        return new TransposedT();
        break;
    case ID_S:
        return new S();
        break;
    }

    return NULL;
}