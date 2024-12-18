#include "Square.h"

// Default constructor.
Square::Square() : _occupied(false), _piece(nullptr) {}

// Copy constructor.
Square::Square(const Square &s) : _occupied(s._occupied), _piece(s._piece) {}

// Return occupied bool of square.
bool Square::occupied() const { return _occupied; }

// Return piece pointer occupying square.
Piece *Square::piece() const { return _piece; }

// Remove a piece from the square.
void Square::remove_piece()
{
    _occupied = false;
    _piece = nullptr;
}

// Sets the location of a piece to the location of this square on the board, renders it
// occupied, and points to the piece.
void Square::set_piece(Piece *piece, std::pair<int, int> location)
{
    _occupied = true;
    _piece = piece;
    _piece->set_location(location);  // Moves the piece to the square's location
}