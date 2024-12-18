#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <vector>
#include <utility>

class King : public Piece {
public:
    // Constructor
    King(char color, std::pair<int, int> location);

    // Returns squares between the king's current square and the target square
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to) override;

    // Returns all valid moves for the king
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck() override;
};

#endif
