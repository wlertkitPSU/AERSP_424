#include "Rook.h"

// Constructor: Initializes the Rook with color and location
Rook::Rook(char color, std::pair<int, int> location)
    : Piece(color, ROOK, location) {}

// Helper function to generate moves in a single direction
inline std::vector<std::pair<int, int>> generateDirectionalMoves(
    const std::pair<int, int>& start, int row_dir, int col_dir, std::pair<int, int> target = {-1, -1}) {
    std::vector<std::pair<int, int>> path;
    auto current = start;

    // Move in the specified direction until out of bounds or reaching the target
    while (true) {
        current = {current.first + row_dir, current.second + col_dir};

        if (!checkBounds(current)) break; // Stop if out of bounds
        path.push_back(current);

        if (current == target) return path; // Stop when the target is reached
    }

    // If target is not reached, clear the path (for moveCheck)
    if (target != std::make_pair(-1, -1)) path.clear();
    return path;
}

// Returns all squares between the rook's current square and the target square
std::vector<std::pair<int, int>> Rook::moveCheck(std::pair<int, int> move_to) {
    // Directions the rook can move: vertical and horizontal
    const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    // Generate moves in each direction and check for the target
    for (const auto& dir : directions) {
        auto path = generateDirectionalMoves(location(), dir.first, dir.second, move_to);
        if (!path.empty()) return path; // Return the path if the move is valid
    }

    return {}; // Return empty vector if no valid path
}

// Returns all possible moves for the rook
std::vector<std::vector<std::pair<int, int>>> Rook::allMoveCheck() {
    std::vector<std::vector<std::pair<int, int>>> all_moves;

    // Directions the rook can move: vertical and horizontal
    const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    // Generate moves in all directions
    for (const auto& dir : directions) {
        auto path = generateDirectionalMoves(location(), dir.first, dir.second);
        if (!path.empty()) all_moves.push_back(path);
    }

    return all_moves;
}
