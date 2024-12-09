#pragma once
#include <memory>
#include <vector>
#include "square.h"
#include "piece.h"

class Board {
public:
    Board();
    void print() const;
    bool applyMove(const std::string& move, Player::PlayerColor playerColor);
    bool isCheckmate(char playerColor) const;
    bool isStalemate(char playerColor) const;

private:
    std::unique_ptr<Square> squares[8][8];
    void setupPieces();
    bool movePiece(int startRow, int startCol, int endRow, int endCol);
};
