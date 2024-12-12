#include "game.h"
#include "square.h"
#include "Pieces.h"

// Constructor
Game::Game() {
    // Initializes board and pieces
    isOver = false;
    whiteTurn = true;
    number_of_moves = 0;
    selected_piece = nullptr;
    selected = false;
    gameStatus = true;

    // Initializes the board cells
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cells[i][j] = Square(i, j);
        }
    }

    // Initializes white pieces
    w_king = new King("White", 0, 4);
    w_queen = new Queen("White", 0, 3);
    w_bishop[0] = new Bishop("White", 0, 2);
    w_bishop[1] = new Bishop("White", 0, 5);
    w_rook[0] = new Rook("White", 0, 0);
    w_rook[1] = new Rook("White", 0, 7);
    w_knight[0] = new Knight("White", 0, 1);
    w_knight[1] = new Knight("White", 0, 6);
    for (int i = 0; i < 8; ++i) {
        w_pawn[i] = new Pawn("White", 1, i);
    }

    // Initializes black pieces
    b_king = new King("Black", 7, 4);
    b_queen = new Queen("Black", 7, 3);
    b_bishop[0] = new Bishop("Black", 7, 2);
    b_bishop[1] = new Bishop("Black", 7, 5);
    b_rook[0] = new Rook("Black", 7, 0);
    b_rook[1] = new Rook("Black", 7, 7);
    b_knight[0] = new Knight("Black", 7, 1);
    b_knight[1] = new Knight("Black", 7, 6);
    for (int i = 0; i < 8; ++i) {
        b_pawn[i] = new Pawn("Black", 6, i);
    }

    // Adds pieces to vectors
    whitePieces.push_back(w_king);
    whitePieces.push_back(w_queen);
    for (int i = 0; i < 2; ++i) {
        whitePieces.push_back(w_bishop[i]);
        whitePieces.push_back(w_rook[i]);
        whitePieces.push_back(w_knight[i]);
    }
    for (int i = 0; i < 8; ++i) {
        whitePieces.push_back(w_pawn[i]);
    }

    blackPieces.push_back(b_king);
    blackPieces.push_back(b_queen);
    for (int i = 0; i < 2; ++i) {
        blackPieces.push_back(b_bishop[i]);
        blackPieces.push_back(b_rook[i]);
        blackPieces.push_back(b_knight[i]);
    }
    for (int i = 0; i < 8; ++i) {
        blackPieces.push_back(b_pawn[i]);
    }
}

// Destructor
Game::~Game() {
    // Frees dynamically allocated memory
    delete w_king;
    delete w_queen;
    for (int i = 0; i < 2; ++i) {
        delete w_bishop[i];
        delete w_rook[i];
        delete w_knight[i];
    }
    for (int i = 0; i < 8; ++i) {
        delete w_pawn[i];
    }

    delete b_king;
    delete b_queen;
    for (int i = 0; i < 2; ++i) {
        delete b_bishop[i];
        delete b_rook[i];
        delete b_knight[i];
    }
    for (int i = 0; i < 8; ++i) {
        delete b_pawn[i];
    }
}

// Start the game
void Game::Start() {
    printBoard();
    run();
}

// Prints the current board state
void Game::printBoard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Prints each square with its piece
            std::cout << cells[i][j].getPiece() << " ";
        }
        std::cout << std::endl;
    }
}

// Draw the current game state (for graphics)
void Game::draw() const {
    std::cout << "Drawing game..." << std::endl;
}

// Select a piece
bool Game::SelectPiece(Square Cells[][8], int x, int y) {
    // Check if the cell has a piece
    if (Cells[x][y].getPiece() == nullptr) {
        return false; // No piece to select
    }

    // Check if the piece belongs to the current player
    if (whiteTurn && Cells[x][y].getPiece()->isWhite) {
        selected_piece = Cells[x][y].getPiece();
        selected = true;
        return true;
    } else if (!whiteTurn && !Cells[x][y].getPiece()->isWhite) {
        selected_piece = Cells[x][y].getPiece();
        selected = true;
        return true;
    }
    return false;
}

// Move the selected piece
void Game::moveSelected(Square Cells[][8], int x, int y) {
    // Checks if the move is valid (implement actual move logic in Pieces class)
    if (selected_piece->isValidMove(x, y, Cells)) {
        Cells[x][y].setPiece(*selected_piece); // Moves the piece to the new square
        selected_piece->setPosition(x, y); // Updates the piece's position
        number_of_moves++;
        selected = false; // Deselects the piece
        whiteTurn = !whiteTurn; // Changes player turn
    }
}

// Run the game -- handles user input and game loop
void Game::run() {
    while (!isOver) {
        // Gets input, moves piece, checks game status, etc.
        int x, y;
        std::cout << "Enter coordinates to move (x y): ";
        std::cin >> x >> y;

        if (selected) {
            moveSelected(cells, x, y);
        } else {
            SelectPiece(cells, x, y);
        }

        printBoard(); // Prints board after each move
        // Add more logic to check for checkmate, stalemate (need to incorporate from King class)
    }
}

// Draws possible moves for the selected piece
void Game::DrawPossibleMoves() {
    // Implement logic to highlight possible moves for the selected piece (need to incorporate from pieces class)
}

// Handles game-over conditions (checkmate, stalemate, etc.)
void Game::gameOver() {
    isOver = true;
    std::cout << "Game Over!" << std::endl;
}

// Sets up the right side of the window for graphical rendering (for graphics)
void Game::SetRightSideofWindow() {
    // Implement specific rendering logic for the right side of the window
}

// Checks if a piece is selected
bool Game::getSelected() const {
    return selected;
}