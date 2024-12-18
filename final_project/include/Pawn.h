#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>

class Pawn : public Piece
{
public:
    // Constructor
    Pawn(char color, std::pair<int, int> location);

    // Checks if moving to `move_to` is valid and returns the path
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to) override;

    // Returns all possible moves for the pawn
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck() override;
};

#endif
