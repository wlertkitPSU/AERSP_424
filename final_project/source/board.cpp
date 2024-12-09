#include "board.h"
#include "player.h"
#include "piece.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor
Board::Board() {
    // Initializes an 8x8 game board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares[i][j] = std::make_unique<Square>(i, j); // Creates squares
        }
    }
    // Initializes pieces
    setupPieces();
}

// Sets up pieces on the board
void Board::setupPieces() {
    // Pawns
    for (int i = 0; i < 8; ++i) {
        squares[1][i]->setPiece(std::make_unique<Piece>('B', 'P')); // Black pawns
        squares[6][i]->setPiece(std::make_unique<Piece>('W', 'P')); // White pawns
    }

    // Rooks
    squares[0][0]->setPiece(std::make_unique<Piece>(PieceType::Rook, 'B'));
    squares[0][7]->setPiece(std::make_unique<Piece>(PieceType::Rook, 'B'));
    squares[7][0]->setPiece(std::make_unique<Piece>(PieceType::Rook, 'W'));
    squares[7][7]->setPiece(std::make_unique<Piece>(PieceType::Rook, 'W'));

    // Knights
    squares[0][1]->setPiece(std::make_unique<Piece>(PieceType::Knight, 'B'));
    squares[0][6]->setPiece(std::make_unique<Piece>(PieceType::Knight, 'B'));
    squares[7][1]->setPiece(std::make_unique<Piece>(PieceType::Knight, 'W'));
    squares[7][6]->setPiece(std::make_unique<Piece>(PieceType::Knight, 'W'));

    // Bishops
    squares[0][2]->setPiece(std::make_unique<Piece>(PieceType::Bishop, 'B'));
    squares[0][5]->setPiece(std::make_unique<Piece>(PieceType::Bishop, 'B'));
    squares[7][2]->setPiece(std::make_unique<Piece>(PieceType::Bishop, 'W'));
    squares[7][5]->setPiece(std::make_unique<Piece>(PieceType::Bishop, 'W'));

    // Queens
    squares[0][3]->setPiece(std::make_unique<Piece>(PieceType::Queen, 'B'));
    squares[7][3]->setPiece(std::make_unique<Piece>(PieceType::Queen, 'W'));

    // Kings
    squares[0][4]->setPiece(std::make_unique<Piece>(PieceType::King, 'B'));
    squares[7][4]->setPiece(std::make_unique<Piece>(PieceType::King, 'W'));
}

// Prints the board to text based display (for now)
void Board::print() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (squares[i][j]->getPiece()) {
                std::cout << squares[i][j]->getPiece()->getSymbol() << " ";
            } else {
                std::cout << ". "; // Empty square
            }
        }
        std::cout << std::endl;
    }
}

// Applies a move
bool Board::applyMove(const std::string& move, Player::PlayerColor playerColor) {
    int startRow = 6, startCol = 4; 
    int endRow = 4, endCol = 4;
    
    // Example of using playerColor if needed
    // You can convert playerColor to a char if necessary
    char colorChar = (playerColor == Player::PlayerColor::White) ? 'W' : 'B';

    return movePiece(startRow, startCol, endRow, endCol);
}

// Moves a piece from one square to another
bool Board::movePiece(int startRow, int startCol, int endRow, int endCol) {
    if (squares[startRow][startCol]->getPiece() == nullptr) {
        return false;
    }
    squares[endRow][endCol]->setPiece(std::move(squares[startRow][startCol]->getPiece()));
    return true;
}

// Checks if a player is in checkmate
bool Board::isCheckmate(char playerColor) const {
    // Checkmate logic here
    return false; // Just a placeholder
}

// Checks if a player is in stalemate
bool Board::isStalemate(char playerColor) const {
    return false;
}
