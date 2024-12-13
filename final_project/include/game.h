#pragma once

#include <string>
#include <vector>
#include "Square.h"
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
    // Constructor and Destructor
    Game();
    ~Game();

    // Game functions
    void Start();
    bool SelectPiece(Square Cells[][8], int x, int y);
    void moveSelected(Square Cells[][8], int x, int y);
    void gameOver();
    void printBoard() const;
    void run(); // Handles user inputs and main game loop

    // Board and state management
    void draw() const; // Draws board
    bool getSelected() const; // Checks if a piece is selected
    void updateBoardState(); // Updates the state of the board after a move
    
    // Board and pieces variables
    Square cells[8][8]; // 8x8 board
    bool isOver; // Flags to indicate if the game is over
    bool whiteTurn; // Flags to track whose turn it is (true for white, false for black)
    int number_of_moves; // Number of moves made in the game
    Pieces *selected_piece;
    
    // Piece containers for white and black pieces
    std::vector<Pieces *> whitePieces;
    std::vector<Pieces *> blackPieces;
    
    // White pieces
    King *w_king;
    Queen *w_queen;
    Bishop *w_bishop[2];
    Rook *w_rook[2];
    Knight *w_knight[2];
    Pawn *w_pawn[8];

    // Black pieces
    King *b_king;
    Queen *b_queen;
    Bishop *b_bishop[2];
    Rook *b_rook[2];
    Knight *b_knight[2];
    Pawn *b_pawn[8];

private:
    std::vector<Square> moves; // Vector to store valid moves for the selected piece
    bool gameStatus; // Current game status
    bool selected; // Flag indicating whether a piece is selected
};