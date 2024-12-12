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
        int x, y;
        bool validInput = false;

        // Gets valid input
        while (!validInput) {
            std::cout << "Enter coordinates (x y): ";
            if (!(std::cin >> x >> y)) {
                std::cin.clear(); // Clears error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards invalid input
                std::cout << "Invalid input. Please enter two integers between 0 and 7.\n";
                continue;
            }

            // Checks if coordinates are in range
            if (x < 0 || x >= 8 || y < 0 || y >= 8) {
                std::cout << "Coordinates out of bounds. Please enter values between 0 and 7.\n";
            } else {
                validInput = true;
            }
        }

        // Handles input
        if (selected) {
            // Checks if the move is valid
            bool validMove = false;
            for (const auto& move : moves) {
                if (move.x == x && move.y == y) {
                    validMove = true;
                    break;
                }
            }

            if (validMove) {
                moveSelected(cells, x, y);
                selected = false;
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        } else {
            // Attempt to select a piece
            if (!SelectPiece(cells, x, y)) {
                std::cout << "Invalid selection. Either the square is empty or it's not your turn.\n";
            }
        }

        printBoard(); // Prints the board after each turn

    }
}