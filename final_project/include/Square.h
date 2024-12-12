#pragma once
#include "Pieces.h"

class Square {
public:
    Square(int x = 0, int y = 0);
    void setPiece(Pieces* pieces);   // Sets the piece on the square
    Pieces* getPiece() const;       // Gets the piece on the square

    // Additional methods
    bool isOccupied() const;       // Checks if the square is occupied by a piece
    int getX() const;              // Gets the x-coordinate of the square
    int getY() const;              // Gets the y-coordinate of the square
    int x, y;                      // Coordinates of the square
    int occupied_value;            // 0 if unoccupied, 3 if king,2 if Queen, 1 if Rook, -1 if Knight, -2 if Bishop, -3 if Pawn
    int occupied_color;            // 0 if unoccupied, 1 if white, -1 if black.
    int cell_color; 

private:
    Pieces* pieces;                
};
