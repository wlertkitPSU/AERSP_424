#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Square.h"

class Board
{
private:
    const int _rows = 8;                       // Number of rows
    const int _cols = 8;                       // Number of columns
    vector<vector<Square>> _squares;           // 2D grid for the board
    vector<Piece *> _white, _black;            // Active pieces
    vector<char> _captured_white, _captured_black; // Captured pieces

    void init_pieces();                        // Initialize pieces
    void init_board();                         // Place pieces on the board

    bool is_valid_coords(const string &coord);
    bool can_capture(Square *target_square, char piece_color);
    void remove_captured_piece(Square *target_square);
    bool is_valid_pawn_move(Piece *piece, pair<int, int> target_loc, Square *target_square);
    bool is_king_threatened(char king_color);

public:
    Board();
    ~Board();

    void print_board(ostream &out) const;      // Prints the board
    void play_user();                          // Play a game of chess

    int move(char color, string from, string to); // Move a piece
    bool is_legal(Piece *from_piece, Piece *to_piece, pair<int, int> to_loc);
    bool is_checkmate(char color);
    int is_check(Piece *piece);

    int rows() const { return _rows; }         // Getter for rows
    int columns() const { return _cols; }      // Getter for columns
};

bool checkMoveCoords(char file, char rank);    // Helper for bounds check

#endif
