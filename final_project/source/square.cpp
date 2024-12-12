#include "square.h"

Square::Square(int x, int y) : x(x), y(y), pieces(nullptr) {}

void Square::setPiece(Pieces* p) {
    pieces = p;
}

Pieces* Square::getPiece() const {
    return pieces;
}

bool Square::isOccupied() const {
    return pieces != nullptr;  // Returns true if a piece occupies the square
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}