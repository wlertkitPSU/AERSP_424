#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <vector>
#include <utility>

class King : public Piece
{
public:
    // Constructor
    King(char color, std::pair<int, int> location);

    // Returns all squares between the king's current square and the square being moved to.
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to);

    // Returns all possible squares the king can move to.
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck();
};

#endif