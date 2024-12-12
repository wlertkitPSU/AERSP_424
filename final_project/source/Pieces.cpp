#include <iostream>
#include <vector>
#include "Pieces.h"
#include "Square.h"
using namespace std;

// Checks if the move is valid for the current piece
bool Pieces::isValidMove(int destX, int destY, Square Cells[][8]) {
    // Get possible moves for the piece
    std::vector<Square> moves = getMoves(Cells, x, y);
    
    // Check if the destination square is in the list of possible moves
    for (const Square& move : moves) {
        if (move.x == destX && move.y == destY) {
            return true;
        }
    }
    return false;
}

// Updates the piece's position
void Pieces::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}