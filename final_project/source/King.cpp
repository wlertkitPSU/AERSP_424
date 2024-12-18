#include "King.h"

// Constructor: Initializes the King with color and location
King::King(char color, std::pair<int, int> location)
    : Piece(color, KING, location) {}

// Returns the squares between the king's current square and the target square
std::vector<std::pair<int, int>> King::moveCheck(std::pair<int, int> move_to) {
    // List of all potential moves for the king (one square in any direction)
    std::vector<std::pair<int, int>> potential_moves = {
        {location().first + 1, location().second},       // Up
        {location().first + 1, location().second + 1},  // Up-Right
        {location().first, location().second + 1},      // Right
        {location().first - 1, location().second + 1},  // Down-Right
        {location().first - 1, location().second},      // Down
        {location().first - 1, location().second - 1},  // Down-Left
        {location().first, location().second - 1},      // Left
        {location().first + 1, location().second - 1}   // Up-Left
    };

    // Check if the target square is a valid move
    for (const auto& move : potential_moves) {
        if (move == move_to && checkBounds(move)) {
            return {move};
        }
    }

    // If the move is invalid, return an empty vector
    return {};
}

// Returns all valid moves for the King
std::vector<std::vector<std::pair<int, int>>> King::allMoveCheck() {
    // List of all potential moves for the king
    std::vector<std::pair<int, int>> potential_moves = {
        {location().first + 1, location().second},       // Up
        {location().first + 1, location().second + 1},  // Up-Right
        {location().first, location().second + 1},      // Right
        {location().first - 1, location().second + 1},  // Down-Right
        {location().first - 1, location().second},      // Down
        {location().first - 1, location().second - 1},  // Down-Left
        {location().first, location().second - 1},      // Left
        {location().first + 1, location().second - 1}   // Up-Left
    };

    // Filter moves to ensure they are within bounds
    std::vector<std::vector<std::pair<int, int>>> valid_moves;
    for (const auto& move : potential_moves) {
        if (checkBounds(move)) {
            valid_moves.push_back({move});
        }
    }

    return valid_moves;
}
