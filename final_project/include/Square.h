#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"
#include <utility>
#include <string>

// Represents a square on the chessboard
class Square
{
private:
    bool _occupied;       // True if the square contains a piece
    Piece* _piece;        // Pointer to the occupying piece

public:
    // Constructors
    Square();                                    // Default constructor
    Square(const Square& s);                     // Copy constructor

    // Accessors
    bool occupied() const;                       // Check if the square is occupied
    Piece* piece() const;                        // Get the occupying piece

    // Mutators
    void remove_piece();                         // Remove the piece from the square
    void set_piece(Piece* piece, std::pair<int, int> location); // Place a piece on the square

    // Utility
    std::string to_string() const;               // Return square state as string for debugging
};

#endif
