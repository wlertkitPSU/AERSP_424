#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <string>
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

// Movement outcomes
enum MoveOutcome { BAD = -1, GOOD, CHECK, CHECKMATE, STALEMATE };

// Helper function to check bounds
bool checkBounds(pair<int, int> location);

class Piece
{
protected:
    char _color;              // 'W' for White, 'B' for Black
    char _name;               // 'K', 'Q', 'R', etc.
    pair<int, int> _location; // {row, column} of the piece

public:
    // Constructors
    Piece();                                   
    Piece(char color, char name, pair<int, int> location);  

    virtual ~Piece() {} // Virtual destructor for base class safety

    // Getters
    char color() const;                       
    char name() const;                        
    string fullName() const;                  
    pair<int, int> location() const;          

    // Setters
    void set_location(const pair<int, int>& new_location); 

    // Display Information
    void print_info() const; // Utility to print piece details

    // Movement (to be implemented in derived classes)
    virtual vector<pair<int, int>> moveCheck(pair<int, int> move_to) = 0;
    virtual vector<vector<pair<int, int>>> allMoveCheck() = 0;
};

// Operator overload for comparison
inline bool operator==(const Piece *lhs, const Piece &rhs)
{
    return lhs->fullName() == rhs.fullName() && lhs->location() == rhs.location();
}

#endif
