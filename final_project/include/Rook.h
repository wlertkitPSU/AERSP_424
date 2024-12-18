#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <vector>
#include <utility>

class Rook : public Piece {
public:
    // Constructor
    Rook(char color, std::pair<int, int> location);

    // Returns all squares between the rook's current square and the square being moved to
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to) override;

    // Returns all possible squares the rook can move to
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck() override;
};

#endif
