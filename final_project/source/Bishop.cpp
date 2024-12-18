#include "Bishop.h"

// Constructor: Initializes the bishop with color and location
Bishop::Bishop(char color, std::pair<int, int> location)
    : Piece(color, BISHOP, location) {}

// Helper function to generate moves in a diagonal direction
inline std::vector<std::pair<int, int>> generateDiagonalMoves(
    std::pair<int, int> start, int row_dir, int col_dir, std::pair<int, int> target = {-1, -1})
{
    std::vector<std::pair<int, int>> path;
    auto current = start;

    while (true)
    {
        current = {current.first + row_dir, current.second + col_dir};

        if (!checkBounds(current))
            break; // Stop if out of bounds
        path.push_back(current);

        if (current == target)
            return path; // Return path if target is reached
    }

    if (target != std::make_pair(-1, -1))
        path.clear(); // Clear path if target not reached

    return path;
}

// Returns all squares between the bishop's current square and the target square
std::vector<std::pair<int, int>> Bishop::moveCheck(std::pair<int, int> move_to)
{
    // Directions: diagonally (top-right, bottom-right, bottom-left, top-left)
    const std::vector<std::pair<int, int>> directions = {
        {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    // Check each direction for a valid path to the target square
    for (const auto &dir : directions)
    {
        auto path = generateDiagonalMoves(location(), dir.first, dir.second, move_to);
        if (!path.empty())
            return path; // Return the path if valid
    }

    return {}; // Return an empty vector if no valid move
}

// Returns all possible squares the bishop can move to
std::vector<std::vector<std::pair<int, int>>> Bishop::allMoveCheck()
{
    std::vector<std::vector<std::pair<int, int>>> all_moves;

    // Directions: diagonally (top-right, bottom-right, bottom-left, top-left)
    const std::vector<std::pair<int, int>> directions = {
        {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    // Generate all possible moves in each direction
    for (const auto &dir : directions)
    {
        auto path = generateDiagonalMoves(location(), dir.first, dir.second);
        if (!path.empty())
            all_moves.push_back(path);
    }

    return all_moves;
}
