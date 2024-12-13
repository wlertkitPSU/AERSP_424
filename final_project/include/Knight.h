#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <vector>
#include <utility>

class Knight : public Piece
{
public:
    // Constructor.
    Knight(char color, std::pair<int, int> location);

    // Returns all squares between the knight's current square and the square being moved to.
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to);

    // Returns all possible squares the knight can move to.
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck();
};

#endif