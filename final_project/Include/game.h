#pragma once
#include "Pieces.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include <vector>
#include <iostream>

class Game
{
public:
    Game();
    void Start();
    void DrawPossibleMoves();
    bool SelectPiece(Square Cells[][8], int x, int y);
    void draw() const;
    void moveSelected(Square Cells[][8], int x, int y);
    bool getSelected();
    void gameOver();
    void SetRightSideofWindow();
    void printBoard() const; // New function to print the board
    void run(); // New function to handle user inputs
    Square cells[8][8];
    bool isOver;

private:
    std::vector<Square> moves;
    std::vector<Pieces *> whitePieces;
    std::vector<Pieces *> blackPieces;
    // white pieces
    King *w_king;
    Queen *w_queen;
    Bishop *w_bishop[2];
    Rook *w_rook[2];
    Knight *w_knight[2];
    Pawn *w_pawn[8];
    // black pieces
    King *b_king;
    Queen *b_queen;
    Bishop *b_bishop[2];
    Rook *b_rook[2];
    Knight *b_knight[2];
    Pawn *b_pawn[8];

    bool gameStatus, selected, whiteTurn;
    Pieces *selected_piece;
    int number_of_moves;
};