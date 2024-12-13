#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <vector>
#include <utility>

class Bishop : public Piece
{
public:
    // Constructor
    Bishop(char color, std::pair<int, int> location);

    // Returns all squares between the bishop's current square and the square being moved to.
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to);

    // Returns all possible squares the bishop can move to.
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck();
};

#endif