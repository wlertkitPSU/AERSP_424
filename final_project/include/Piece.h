#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
using namespace std;

// Constants to represent color names.
const char WHITE = 'W';
const char BLACK = 'B';

// Constants to represent piece names.
const char KING = 'K';
const char QUEEN = 'Q';
const char ROOK = 'R';
const char BISHOP = 'B';
const char KNIGHT = 'N';
const char PAWN = 'P';

// Constants to represent potential movement outcomes.
const int BAD = -1;      // The piece cannot be moved to this square.
const int GOOD = 0;      // The piece can be moved to this square.
const int CHECK = 1;     // The enemy player's king is vulnerable and needs to be protected.
const int CHECKMATE = 2; // The enemy player's king is vulnerable and cannot be protected. You win.
const int STALEMATE = 3; // The enemy player's king isn't vulnerable, but cannot make a valid move. Nobody wins. Draw.

// Functions.
bool checkBounds(pair<int, int> location);

class Piece
{
private:
    // Attributes
    char _color;              // The color of the piece. Can be 'W' or 'B'.
    char _name;               // The name of the piece. Can be 'K', 'Q', 'R', 'B', 'N', or 'P'
    pair<int, int> _location; // Current location of the piece on the chess board. Bottom left is {0,0}, top right is {7,7}.

public:
    // Constructors.
    Piece();                                                                                   // Default constructor.
    Piece(char color, char name, pair<int, int> location);                                     // Constructor for a specific piece.

    // Destructor
    virtual ~Piece() {}
    
    // Getters
    char color() const;                                                                       // Return the color char of the piece.
    char name() const;                                                                        // Return the name char of the piece.
    string fullName() const;                                                                  // Return the color+name of the piece, giving it a unique name for that player's side.
    pair<int, int> location() const;                                                          // Return the location pair of ints of the piece.

    // Setters
    void move(pair<int, int> location);                                                       // Sets the location of the piece to the argument's value.

    virtual vector<pair<int, int>> moveCheck(pair<int, int> move_to) = 0;                     // Pure virtual function for returning the moves of a piece in a single direction.
    virtual vector<vector<pair<int, int>>> allMoveCheck() = 0;                                // Pure virtual function for returning all the moves of a piece.
};

#endif