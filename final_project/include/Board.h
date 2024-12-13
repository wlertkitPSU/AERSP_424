#pragma once
#include "Piece.h"
#include "Square.h"

// The actual chess board
// Contains 8 rows and 8 columns of squares
// A square can either be occupied or not occupied by a piece
// The board also keeps track of all the uncaptured white pieces,
// uncaptured black pieces, captured white pieces, and captured black pieces
class Board
{
private:
    int _rows;                       // 8 rows
    int _cols;                       // 8 columns 
    vector<vector<Square>> _squares; // Individual board square
    vector<Piece *> _white;          // All white pieces currently on the board
    vector<Piece *> _black;          // All black pieces currently on the board
    vector<char> _white_captured;    // Names of all white pieces that have been captured by black
    vector<char> _black_captured;    // Names of all black pieces that have been captured by white

public:
    // Constructor and destructor
    Board();
    ~Board();

    // Called by board's default constructor
    void init_pieces(); // Initializes the pieces by creating all the initial chess pieces and adding them to _white and _black
    void init_board();  // Initializes the board by linking each initial square to its matching piece

    // Print functions
    void print_board(ostream &out) const;    // Prints the board and its contents in a readable format
    void print_active(ostream &out) const;   // Prints a list of the active pieces for both white and black
    void print_captured(ostream &out) const; // Prints a list of the captured pieces for both white and black

    // Getters
    int rows() const { return _rows; }    // Retrieves the integer value for rows that board holds
    int columns() const { return _cols; } // Retrieves the integer value for columns that board holds

    // Play functions
    void play_user(); // Play a game of chess between two human players locally

    // Other functions.
    int move(char color, string first, string second);                                         // Attempts to move a chess piece from one location to another. Return -1 if fail, 0 if good, 1 if check, 2 if checkmate, 3 if stalemate.
    bool is_suicide(Piece *move_from_piece, Piece *move_to_piece, pair<int, int> move_to_loc); // Checks if the player's king is vulnerable. Returns true if vulnerable.
    bool is_checkmate(char color);                                                             // Checks if the player is in checkmate. Returns true if in checkmate.
    int is_check(Piece *move_from_piece);                                                      // Checks if the player is in check. Returns 0 if good, 1 if check, 2 if checkmate, 3 if stalemate.
};

void pressEnterToContinue();                   // Pauses the game until the player presses the ENTER key on their keyboard
bool checkMoveCoords(char first, char second); // Checks to see if the coordinates given are within the boundaries of the 8x8 chess board
