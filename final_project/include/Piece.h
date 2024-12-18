#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Constants for piece colors
const char WHITE = 'W';
const char BLACK = 'B';

// Constants for piece names
const char KING = 'K';
const char QUEEN = 'Q';
const char ROOK = 'R';
const char BISHOP = 'B';
const char KNIGHT = 'N';
const char PAWN = 'P';

// Movement outcomes
enum MoveOutcome { BAD = -1, GOOD, CHECK, CHECKMATE, STALEMATE };

// Helper function to check bounds
bool checkBounds(pair<int, int> location);

// Base class for all chess pieces
class Piece {
protected:
    char _color;              // 'W' for White, 'B' for Black
    char _name;               // Name/type of the piece (KING, QUEEN, etc.)
    pair<int, int> _location; // {row, column} on the board

public:
    // Constructors
    Piece(); // Default constructor
    Piece(char color, char name, pair<int, int> location);

    virtual ~Piece() = default; // Virtual destructor for safe polymorphism

    // Accessors
    char color() const;                        // Returns the piece color
    char name() const;                         // Returns the piece type/name
    string fullName() const;                   // Returns full identifier (color + name)
    pair<int, int> location() const;           // Returns the piece's current location

    // Mutators
    void set_location(const pair<int, int>& new_location); // Sets the piece's location

    // Debugging
    void print_info() const; // Prints the piece's details for debugging

    // Pure virtual methods for movement logic
    virtual vector<pair<int, int>> moveCheck(pair<int, int> move_to) = 0;
    virtual vector<vector<pair<int, int>>> allMoveCheck() = 0;
};

// Operator overload for comparison
inline bool operator==(const Piece *lhs, const Piece &rhs)
{
    return lhs->fullName() == rhs.fullName() && lhs->location() == rhs.location();
}

#endif
