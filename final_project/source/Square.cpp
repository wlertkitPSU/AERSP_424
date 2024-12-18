#include "Square.h"

// Default constructor: creates an empty square
Square::Square() : _occupied(false), _piece(nullptr) {}

// Copy constructor: copies the square state
Square::Square(const Square& s) : _occupied(s._occupied), _piece(s._piece) {}

// Check if the square is occupied
bool Square::occupied() const {
    return _occupied;
}

// Return pointer to the occupying piece
Piece* Square::piece() const {
    return _piece;
}

// Remove the piece from the square
void Square::remove_piece() {
    if (_occupied) { // Only reset if the square is occupied
        _occupied = false;
        _piece = nullptr;
    }
}

// Place a piece on the square and update its location
void Square::set_piece(Piece* piece, std::pair<int, int> location) {
    if (_piece == piece) return; // Avoid redundant operations

    if (piece != nullptr) { 
        _occupied = true;
        _piece = piece;
        _piece->set_location(location); // Update the piece's location
    } else {
        remove_piece(); // If nullptr, reset the square
    }
}

// Return a string representation of the square's state
std::string Square::to_string() const {
    return _occupied ? _piece->fullName() : ".";
}
