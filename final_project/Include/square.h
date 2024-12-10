#pragma once
#include <memory>
#include "piece.h"

class Square {
public:
    Square(int row, int col);
    int getRow() const;
    int getCol() const;
    std::unique_ptr<Piece>& getPiece();
    void setPiece(std::unique_ptr<Piece> newPiece);

private:
    int row;
    int col;
    std::unique_ptr<Piece> piece;
};