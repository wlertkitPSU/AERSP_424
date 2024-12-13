#include "Knight.h"

// Constructor
Knight::Knight(char color, std::pair<int, int> location) : Piece(color, KNIGHT, location) {}

// Returns all squares between the knight's current square and the square being moved to.
std::vector<std::pair<int, int>> Knight::moveCheck(std::pair<int, int> move_to)
{
    std::pair<int, int> to_add;
    std::vector<std::pair<int, int>> move_to_list;

    // Move up two, right one.
    to_add = {location().first + 2, location().second + 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move right two, up one.
    to_add = {location().first + 1, location().second + 2};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move right two, down one.
    to_add = {location().first - 1, location().second + 2};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move down two, right one.
    to_add = {location().first - 2, location().second + 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move down two, left one.
    to_add = {location().first - 2, location().second - 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move left two, down one.
    to_add = {location().first - 1, location().second - 2};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move left two, up one.
    to_add = {location().first + 1, location().second - 2};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move up two, left one.
    to_add = {location().first + 2, location().second - 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    return move_to_list;
}

// Returns all possible squares the knight can move to.
std::vector<std::vector<std::pair<int, int>>> Knight::allMoveCheck()
{
    std::pair<int, int> to_add;
    std::vector<std::pair<int, int>> move;
    std::vector<std::vector<std::pair<int, int>>> move_to_list;

    // Move up two, right one.
    to_add = {location().first + 2, location().second + 1};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move right two, up one.
    to_add = {location().first + 1, location().second + 2};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move right two, down one.
    to_add = {location().first - 1, location().second + 2};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move down two, right one.
    to_add = {location().first - 2, location().second + 1};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move down two, left one.
    to_add = {location().first - 2, location().second - 1};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move left two, down one.
    to_add = {location().first - 1, location().second - 2};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move left two, up one.
    to_add = {location().first + 1, location().second - 2};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    // Move up two, left one.
    to_add = {location().first + 2, location().second - 1};
    if (checkBounds(to_add))
    {
        move.push_back(to_add);
    }

    move_to_list.push_back(move);

    return move_to_list;
}
