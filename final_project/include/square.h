#pragma once
#include "Pieces.h"

class Square {
public:
    Square(int x = 0, int y = 0);  // Default constructor with optional initialization
    void setPiece(Pieces* pieces);   // Set the piece on the square
    Pieces* getPiece() const;       // Get the piece on the square

    // Additional methods
    bool isOccupied() const;       // Check if the square is occupied by a piece
    int getX() const;              // Get the x-coordinate of the square
    int getY() const;              // Get the y-coordinate of the square

private:
    int x, y;                      // Coordinates of the square
    Pieces* pieces;                  // Pointer to the piece on this square
};
