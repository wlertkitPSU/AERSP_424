#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <vector>
#include <utility>

class Queen : public Piece
{
public:
    // Constructor
    Queen(char color, std::pair<int, int> location);

    // Returns all squares between the queen's current square and the square being moved to.
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to);

    // Returns all possible squares the queen can move to.
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck();
};

#endif