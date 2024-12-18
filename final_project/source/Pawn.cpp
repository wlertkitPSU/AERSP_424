#include "Pawn.h"

// Constructor
Pawn::Pawn(char color, std::pair<int, int> location)
    : Piece(color, PAWN, location) {}

// Helper function to generate potential pawn moves
inline std::vector<std::pair<int, int>> generatePawnMoves(const std::pair<int, int>& location, char color, bool initialMove) {
    std::vector<std::pair<int, int>> moves;
    int direction = (color == WHITE) ? 1 : -1;

    // Move forward one space
    moves.push_back({location.first + direction, location.second});

    // Move forward two spaces if on the initial row
    if (initialMove) {
        moves.push_back({location.first + 2 * direction, location.second});
    }

    // Diagonal captures
    moves.push_back({location.first + direction, location.second + 1});
    moves.push_back({location.first + direction, location.second - 1});

    return moves;
}

// Checks if moving to `move_to` is valid and returns the path
std::vector<std::pair<int, int>> Pawn::moveCheck(std::pair<int, int> move_to) {
    // Determine if the pawn is in its initial position
    bool initialMove = (color() == WHITE && location().first == 1) || 
                       (color() == BLACK && location().first == 6);

    // Get all potential moves for this pawn
    auto potential_moves = generatePawnMoves(location(), color(), initialMove);

    // Validate the target move
    for (const auto& move : potential_moves) {
        if (move == move_to && checkBounds(move)) {
            return {move};
        }
    }

    return {}; // Return an empty vector if the move is invalid
}

// Returns all possible moves for the pawn
std::vector<std::vector<std::pair<int, int>>> Pawn::allMoveCheck() {
    // Determine if the pawn is in its initial position
    bool initialMove = (color() == WHITE && location().first == 1) || 
                       (color() == BLACK && location().first == 6);

    // Get all potential moves for this pawn
    auto potential_moves = generatePawnMoves(location(), color(), initialMove);

    // Filter valid moves
    std::vector<std::vector<std::pair<int, int>>> valid_moves;
    for (const auto& move : potential_moves) {
        if (checkBounds(move)) {
            valid_moves.push_back({move});
        }
    }

    return valid_moves;
}
