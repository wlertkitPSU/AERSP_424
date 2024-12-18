#include "Piece.h"

// Check if a location is within the bounds of the chessboard
bool checkBounds(pair<int, int> location) {
    return location.first >= 0 && location.first < 8 && location.second >= 0 && location.second < 8;
}

// Default constructor
Piece::Piece() : _color(0), _name(0), _location({-1, -1}) {}

// Constructor for specific piece
Piece::Piece(char color, char name, pair<int, int> location)
    : _color(color), _name(name), _location(location) {}

// Getter for color
char Piece::color() const {
    return _color;
}

// Getter for name
char Piece::name() const {
    return _name;
}

// Getter for full name
string Piece::fullName() const {
    return string(1, _color) + _name;
}

// Getter for location
pair<int, int> Piece::location() const {
    return _location;
}

// Setter for location
void Piece::set_location(const pair<int, int>& new_location) {
    if (checkBounds(new_location)) {
        _location = new_location;
    } else {
        cerr << "Error: Attempted to move to an out-of-bounds location: (" 
             << new_location.first << ", " << new_location.second << ")." << endl;
    }
}

// Utility to print piece details
void Piece::print_info() const {
    cout << "Piece: " << fullName() 
         << " | Location: (" << _location.first << ", " << _location.second << ")"
         << endl;
}
