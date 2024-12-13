#include "Bishop.h"

// Constructor
Bishop::Bishop(char color, std::pair<int, int> location) : Piece(color, BISHOP, location) {}

// Returns all squares between the bishop's current square and the square being moved to.
std::vector<std::pair<int, int>> Bishop::moveCheck(std::pair<int, int> move_to)
{
    std::pair<int, int> to_add;
    std::vector<std::pair<int, int>> move_to_list;

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

// Returns all possible squares the bishop can move to.
std::vector<std::vector<std::pair<int, int>>> Bishop::allMoveCheck()
{
    std::pair<int, int> to_add;
    std::vector<std::vector<std::pair<int, int>>> move_to_list;

    // Move diagonally top right many spaces.
    std::vector<std::pair<int, int>> diag_top_right;
    to_add = {location().first + 1, location().second + 1};
    while (checkBounds(to_add))
    {
        diag_top_right.push_back(to_add);
        to_add = {to_add.first + 1, to_add.second + 1};
    }
    move_to_list.push_back(diag_top_right);

    // Move diagonally bottom right many spaces.
    std::vector<std::pair<int, int>> diag_bottom_right;
    to_add = {location().first - 1, location().second + 1};
    while (checkBounds(to_add))
    {
        diag_bottom_right.push_back(to_add);
        to_add = {to_add.first - 1, to_add.second + 1};
    }
    move_to_list.push_back(diag_bottom_right);

    // Move diagonally bottom left many spaces.
    std::vector<std::pair<int, int>> diag_bottom_left;
    to_add = {location().first - 1, location().second - 1};
    while (checkBounds(to_add))
    {
        diag_bottom_left.push_back(to_add);
        to_add = {to_add.first - 1, to_add.second - 1};
    }
    move_to_list.push_back(diag_bottom_left);

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