#include "square.h"
#include <memory>

// Constructor
Square::Square(int row, int col)
    : row(row), col(col), piece(nullptr) {}

// Get the row of the square
int Square::getRow() const {
    return row;
}

// Get the column of the square
int Square::getCol() const {
    return col;
}

// Get the piece on the square
std::unique_ptr<Piece>& Square::getPiece() {
    return piece;
}

// Set a piece on the square
void Square::setPiece(std::unique_ptr<Piece> newPiece) {
    piece = std::move(newPiece);
}
