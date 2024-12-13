#include "King.h"

King::King(char color, std::pair<int, int> location)
    : Piece(color, KING, location) {}

std::vector<std::pair<int, int>> King::moveCheck(std::pair<int, int> move_to)
{
    std::pair<int, int> to_add;
    std::vector<std::pair<int, int>> move_to_list;

    // Move up one space.
    to_add = {location().first + 1, location().second};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move diagonally top right one space.
    to_add = {location().first + 1, location().second + 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move right one space.
    to_add = {location().first, location().second + 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move diagonally bottom right one space.
    to_add = {location().first - 1, location().second + 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move down one space.
    to_add = {location().first - 1, location().second};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move diagonally bottom left one space.
    to_add = {location().first - 1, location().second - 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move left one space.
    to_add = {location().first, location().second - 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    // Move diagonally top left one space.
    to_add = {location().first + 1, location().second - 1};
    if (to_add == move_to)
    {
        move_to_list.push_back(to_add);
        return move_to_list;
    }

    return move_to_list;
}

std::vector<std::vector<std::pair<int, int>>> King::allMoveCheck()
{
    std::pair<int, int> to_add;
    std::vector<std::vector<std::pair<int, int>>> move_to_list;

    // Move up one space.
    to_add = {location().first + 1, location().second};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> up;
        up.push_back(to_add);
        move_to_list.push_back(up);
    }

    // Move diagonally top right one space.
    to_add = {location().first + 1, location().second + 1};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> diag_top_right;
        diag_top_right.push_back(to_add);
        move_to_list.push_back(diag_top_right);
    }

    // Move right one space.
    to_add = {location().first, location().second + 1};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> right;
        right.push_back(to_add);
        move_to_list.push_back(right);
    }

    // Move diagonally bottom right one space.
    to_add = {location().first - 1, location().second + 1};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> diag_bottom_right;
        diag_bottom_right.push_back(to_add);
        move_to_list.push_back(diag_bottom_right);
    }

    // Move down one space.
    to_add = {location().first - 1, location().second};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> down;
        down.push_back(to_add);
        move_to_list.push_back(down);
    }

    // Move diagonally bottom left one space.
    to_add = {location().first - 1, location().second - 1};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> diag_bottom_left;
        diag_bottom_left.push_back(to_add);
        move_to_list.push_back(diag_bottom_left);
    }

    // Move left one space.
    to_add = {location().first, location().second - 1};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> left;
        left.push_back(to_add);
        move_to_list.push_back(left);
    }

    // Move diagonally top left one space.
    to_add = {location().first + 1, location().second - 1};
    if (checkBounds(to_add))
    {
        std::vector<std::pair<int, int>> diag_top_left;
        diag_top_left.push_back(to_add);
        move_to_list.push_back(diag_top_left);
    }

    return move_to_list;
}