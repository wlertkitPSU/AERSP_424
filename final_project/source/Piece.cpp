#include "Piece.h"

// Check if a given location is within the bounds of the chessboard.
bool checkBounds(pair<int, int> location)
{
    return location.first >= 0 && location.first < 8 && location.second >= 0 && location.second < 8;
}

// Default constructor.
Piece::Piece() : _color(0), _name(0), _location({-1, -1}) {}

// Constructor for a specific piece.
Piece::Piece(char color, char name, pair<int, int> location)
    : _color(color), _name(name), _location(location) {}

// Destructor
Piece::~Piece(){}

// Getter for color.
char Piece::color() const
{
    return _color;
}

// Getter for name.
char Piece::name() const
{
    return _name;
}

// Getter for full name (color + name).
string Piece::fullName() const
{
    return string(1, _color) + _name;
}

// Getter for location.
pair<int, int> Piece::location() const
{
    return _location;
}

// Setter for location.
void Piece::move(pair<int, int> location)
{
    if (checkBounds(location))
    {
        _location = location;
    }
    else
    {
        cerr << "Error: Attempted to move to an out-of-bounds location." << endl;
    }
}
