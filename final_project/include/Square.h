#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"  // Make sure to include the header for the Piece class
#include <utility>  // For pair<int, int>

// An individual square on the chess board.
//
// Is either occupied or not occupied by a piece.
class Square
{
private:
    // Attributes.
    bool _occupied; // True if the square is occupied.
    Piece *_piece;  // Pointer to a piece occupying the square.

public:
    // Constructors.
    Square();                   // Default constructor.
    Square(const Square &s);     // Copy constructor.

    // Getters.
    bool occupied() const;       // Return occupied bool of square.
    Piece *piece() const;        // Return piece pointer occupying square.

    // Remove a piece from the square.
    void remove_piece();

    // Sets the location of a piece to the location of this square on the board, renders it
    // occupied, and points to the piece.
    void set_piece(Piece *piece, std::pair<int, int> location);
};

#endif