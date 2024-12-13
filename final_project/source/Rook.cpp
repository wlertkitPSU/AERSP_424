#include "Rook.h"

// Constructor.
Rook::Rook(char color, std::pair<int, int> location) : Piece(color, ROOK, location) {}

// Returns all squares between the rook's current square and the square being moved to.
std::vector<std::pair<int, int>> Rook::moveCheck(std::pair<int, int> move_to)
{
    std::pair<int, int> to_add;
    std::vector<std::pair<int, int>> move_to_list;

    // Move up many spaces.
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first + 1, to_add.second};
        move_to_list.push_back(to_add);

        if (to_add == move_to)
        {
            return move_to_list;
        }
    }

    // Move right many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first, to_add.second + 1};
        move_to_list.push_back(to_add);

        if (to_add == move_to)
        {
            return move_to_list;
        }
    }

    // Move down many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first - 1, to_add.second};
        move_to_list.push_back(to_add);

        if (to_add == move_to)
        {
            return move_to_list;
        }
    }

    // Move left many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first, to_add.second - 1};
        move_to_list.push_back(to_add);

        if (to_add == move_to)
        {
            return move_to_list;
        }
    }

    return move_to_list;
}

// Returns all possible squares the rook can move to.
std::vector<std::vector<std::pair<int, int>>> Rook::allMoveCheck()
{
    std::pair<int, int> to_add;
    std::vector<std::vector<std::pair<int, int>>> move_to_list;

    // Move up many spaces.
    std::vector<std::pair<int, int>> up;
    to_add = {location().first + 1, location().second};
    while (checkBounds(to_add))
    {
        up.push_back(to_add);
        to_add = {to_add.first + 1, to_add.second};
    }
    move_to_list.push_back(up);

    // Move right many spaces.
    std::vector<std::pair<int, int>> right;
    to_add = {location().first, location().second + 1};
    while (checkBounds(to_add))
    {
        right.push_back(to_add);
        to_add = {to_add.first, to_add.second + 1};
    }
    move_to_list.push_back(right);

    // Move down many spaces.
    std::vector<std::pair<int, int>> down;
    to_add = {location().first - 1, location().second};
    while (checkBounds(to_add))
    {
        down.push_back(to_add);
        to_add = {to_add.first - 1, to_add.second};
    }
    move_to_list.push_back(down);

    // Move left many spaces.
    std::vector<std::pair<int, int>> left;
    to_add = {location().first, location().second - 1};
    while (checkBounds(to_add))
    {
        left.push_back(to_add);
        to_add = {to_add.first, to_add.second - 1};
    }
    move_to_list.push_back(left);

    return move_to_list;
}
