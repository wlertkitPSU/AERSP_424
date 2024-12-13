#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>

class Pawn : public Piece
{
public:
    // Constructor
    Pawn(char color, std::pair<int, int> location);

    // Returns all squares between the pawn's current square and the square being moved to.
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to);

    // Returns all possible squares the pawn can move to.
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck();
};

#endif