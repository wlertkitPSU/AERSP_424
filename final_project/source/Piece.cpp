#include "Piece.h"

// Helper to check if a location is within the chessboard bounds
bool checkBounds(pair<int, int> location) {
    return location.first >= 0 && location.first < 8 &&
           location.second >= 0 && location.second < 8;
}

// Default constructor: Initializes an invalid piece
Piece::Piece() : _color(0), _name(0), _location({-1, -1}) {}

// Parameterized constructor: Initializes a piece with color, name, and location
Piece::Piece(char color, char name, pair<int, int> location)
    : _color(color), _name(name), _location(location) {
    if (!checkBounds(location)) {
        cerr << "Warning: Piece initialized with out-of-bounds location (" 
             << location.first << ", " << location.second << ")." << endl;
        _location = {-1, -1}; // Mark as invalid location
    }
}

// Getter for the piece's color
char Piece::color() const {
    return _color;
}

// Getter for the piece's name/type
char Piece::name() const {
    return _name;
}

// Returns the piece's full name (color + type)
string Piece::fullName() const {
    return string(1, _color) + _name;
}

// Getter for the current location
pair<int, int> Piece::location() const {
    return _location;
}

// Sets a new location for the piece
void Piece::set_location(const pair<int, int>& new_location) {
    if (checkBounds(new_location)) {
        _location = new_location;
    } else {
        cerr << "Error: Attempted to move to an out-of-bounds location (" 
             << new_location.first << ", " << new_location.second << ")." << endl;
    }
}

// Prints the piece's details for debugging
void Piece::print_info() const {
    cout << "Piece: " << fullName() 
         << " | Location: (" << _location.first << ", " << _location.second << ")" 
         << endl;
}