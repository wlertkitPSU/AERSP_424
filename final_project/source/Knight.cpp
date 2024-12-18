#include "Knight.h"

// Constructor
Knight::Knight(char color, std::pair<int, int> location)
    : Piece(color, KNIGHT, location) {}

// Helper function to generate all potential moves for a Knight
inline std::vector<std::pair<int, int>> generateKnightMoves(const std::pair<int, int>& start) {
    // List of relative offsets for all Knight moves
    const std::vector<std::pair<int, int>> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    std::vector<std::pair<int, int>> moves;
    for (const auto& offset : offsets) {
        std::pair<int, int> move = {start.first + offset.first, start.second + offset.second};
        if (checkBounds(move)) {
            moves.push_back(move);
        }
    }
    return moves;
}

// Checks if moving to `move_to` is valid and returns the path
std::vector<std::pair<int, int>> Knight::moveCheck(std::pair<int, int> move_to) {
    auto possible_moves = generateKnightMoves(location());
    for (const auto& move : possible_moves) {
        if (move == move_to) {
            return {move}; // Return a single-element path if valid
        }
    }
    return {}; // Return an empty vector if the move is invalid
}

// Returns all possible moves for the Knight
std::vector<std::vector<std::pair<int, int>>> Knight::allMoveCheck() {
    auto possible_moves = generateKnightMoves(location());
    std::vector<std::vector<std::pair<int, int>>> result;
    for (const auto& move : possible_moves) {
        result.push_back({move}); // Each move is a separate path for the Knight
    }
    return result;
}
