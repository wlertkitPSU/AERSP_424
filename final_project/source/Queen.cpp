#include "Queen.h"

// Constructor: Initializes the queen with a color and location
Queen::Queen(char color, std::pair<int, int> location)
    : Piece(color, QUEEN, location) {}

// Helper function to generate directional moves
std::vector<std::pair<int, int>> generateDirectionalMoves(
    const std::pair<int, int>& start, int row_dir, int col_dir, std::pair<int, int> target = {-1, -1})
{
    std::vector<std::pair<int, int>> path;
    auto current = start;

    // Move in the specified direction until out of bounds or hitting the target
    while (true) {
        current = {current.first + row_dir, current.second + col_dir};

        if (!checkBounds(current)) break;  // Stop if out of bounds
        path.push_back(current);

        if (current == target) return path;  // Stop if the target square is reached
    }

    // Return empty path if no valid move to the target square
    if (target != std::make_pair(-1, -1)) path.clear();
    return path;
}

// Checks if a move to `move_to` is valid and returns the path
std::vector<std::pair<int, int>> Queen::moveCheck(std::pair<int, int> move_to) {
    std::vector<std::pair<int, int>> path;

    // All possible directions for the Queen
    const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, // Vertical and horizontal
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonals
    };

    for (const auto& dir : directions) {
        path = generateDirectionalMoves(location(), dir.first, dir.second, move_to);
        if (!path.empty()) return path;  // Return the path if a valid move is found
    }

    return {};  // Return empty vector if no valid path
}

// Returns all possible moves for the Queen
std::vector<std::vector<std::pair<int, int>>> Queen::allMoveCheck() {
    std::vector<std::vector<std::pair<int, int>>> all_moves;

    // All possible directions for the Queen
    const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, // Vertical and horizontal
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonals
    };

    for (const auto& dir : directions) {
        auto path = generateDirectionalMoves(location(), dir.first, dir.second);
        if (!path.empty()) all_moves.push_back(path);
    }

    return all_moves;
}
