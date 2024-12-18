#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <vector>
#include <utility>

class Knight : public Piece
{
public:
    // Constructor
    Knight(char color, std::pair<int, int> location);

    // Checks if moving to `move_to` is valid and returns the path
    std::vector<std::pair<int, int>> moveCheck(std::pair<int, int> move_to) override;

    // Returns all possible moves for the Knight
    std::vector<std::vector<std::pair<int, int>>> allMoveCheck() override;
};

#endif
