#pragma once

#include <string>
#include <vector>
#include "square.h"
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

    // Game-related functions
    void Start();
    void DrawPossibleMoves();
    bool SelectPiece(Square Cells[][8], int x, int y);
    void moveSelected(Square Cells[][8], int x, int y);
    void gameOver();
    void SetRightSideofWindow();
    void printBoard() const;
    void run(); // Handles user inputs and main game loop

    // Board and state management
    void draw() const; // Function to draw the board (probably for graphics rendering)
    bool getSelected() const; // Check if a piece is selected
    void updateBoardState(); // Update the state of the board after a move
    
    // Member variables (Board and pieces)
    Square cells[8][8]; // The 8x8 chessboard
    bool isOver; // Flag to indicate if the game is over
    bool whiteTurn; // Flag to track whose turn it is (true for white, false for black)
    int number_of_moves; // Number of moves made in the game
    Pieces *selected_piece; // Pointer to the currently selected piece
    
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
    // Private member variables
    std::vector<Square> moves; // Vector to store valid moves for the selected piece
    bool gameStatus; // Current game status (e.g., checkmate, stalemate)
    bool selected; // Flag indicating whether a piece is selected
};