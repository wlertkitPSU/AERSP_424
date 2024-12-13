#include "Queen.h"

// Constructor
Queen::Queen(char color, std::pair<int, int> location) : Piece(color, QUEEN, location) {}

// Returns all squares between the queen's current square and the square being moved to.
std::vector<std::pair<int, int>> Queen::moveCheck(std::pair<int, int> move_to)
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

    // Move diagonally top right many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first + 1, to_add.second + 1};
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

    // Move diagonally bottom right many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first - 1, to_add.second + 1};
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

    // Move diagonally bottom left many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first - 1, to_add.second - 1};
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

    // Move diagonally top left many spaces.
    move_to_list.clear();
    to_add = {location().first, location().second};
    while (checkBounds(to_add))
    {
        to_add = {to_add.first + 1, to_add.second - 1};
        move_to_list.push_back(to_add);

        if (to_add == move_to)
        {
            return move_to_list;
        }
    }

    return move_to_list;
}

// Returns all possible squares the queen can move to.
std::vector<std::vector<std::pair<int, int>>> Queen::allMoveCheck()
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

    // Move diagonally top right many spaces.
    std::vector<std::pair<int, int>> diag_top_right;
    to_add = {location().first + 1, location().second + 1};
    while (checkBounds(to_add))
    {
        diag_top_right.push_back(to_add);
        to_add = {to_add.first + 1, to_add.second + 1};
    }
    move_to_list.push_back(diag_top_right);

    // Move right many spaces.
    std::vector<std::pair<int, int>> right;
    to_add = {location().first, location().second + 1};
    while (checkBounds(to_add))
    {
        right.push_back(to_add);
        to_add = {to_add.first, to_add.second + 1};
    }
    move_to_list.push_back(right);

    // Move diagonally bottom right many spaces.
    std::vector<std::pair<int, int>> diag_bottom_right;
    to_add = {location().first - 1, location().second + 1};
    while (checkBounds(to_add))
    {
        diag_bottom_right.push_back(to_add);
        to_add = {to_add.first - 1, to_add.second + 1};
    }
    move_to_list.push_back(diag_bottom_right);

    // Move down many spaces.
    std::vector<std::pair<int, int>> down;
    to_add = {location().first - 1, location().second};
    while (checkBounds(to_add))
    {
        down.push_back(to_add);
        to_add = {to_add.first - 1, to_add.second};
    }
    move_to_list.push_back(down);

    // Move diagonally bottom left many spaces.
    std::vector<std::pair<int, int>> diag_bottom_left;
    to_add = {location().first - 1, location().second - 1};
    while (checkBounds(to_add))
    {
        diag_bottom_left.push_back(to_add);
        to_add = {to_add.first - 1, to_add.second - 1};
    }
    move_to_list.push_back(diag_bottom_left);

    // Move left many spaces.
    std::vector<std::pair<int, int>> left;
    to_add = {location().first, location().second - 1};
    while (checkBounds(to_add))
    {
        left.push_back(to_add);
        to_add = {to_add.first, to_add.second - 1};
    }
    move_to_list.push_back(left);

    // Move diagonally top left many spaces.
    std::vector<std::pair<int, int>> diag_top_left;
    to_add = {location().first + 1, location().second - 1};
    while (checkBounds(to_add))
    {
        diag_top_left.push_back(to_add);
        to_add = {to_add.first + 1, to_add.second - 1};
    }
    move_to_list.push_back(diag_top_left);

    return move_to_list;
}