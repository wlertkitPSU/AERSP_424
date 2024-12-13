#include "Pawn.h"

// Constructor
Pawn::Pawn(char color, std::pair<int, int> location) : Piece(color, PAWN, location) {}

// Returns all squares between the pawn's current square and the square being moved to.
std::vector<std::pair<int, int>> Pawn::moveCheck(std::pair<int, int> move_to)
{
    std::pair<int, int> to_add;
    std::vector<std::pair<int, int>> move_to_list;

    // Piece is white
    if (color() == WHITE)
    {
        // Move up one space.
        to_add = {location().first + 1, location().second};
        move_to_list.push_back(to_add);
        if (to_add == move_to)
        {
            return move_to_list;
        }

        // Move up two spaces if at initial location.
        if (location().first == 1)
        {
            to_add = {location().first + 2, location().second};
            if (to_add == move_to)
            {
                move_to_list.push_back(to_add);
                return move_to_list;
            }
        }

        move_to_list.clear();

        // Move diagonally top right if capturing a piece.
        to_add = {location().first + 1, location().second + 1};
        if (to_add == move_to)
        {
            move_to_list.push_back(to_add);
            return move_to_list;
        }

        // Move diagonally top left if capturing a piece.
        to_add = {location().first + 1, location().second - 1};
        if (to_add == move_to)
        {
            move_to_list.push_back(to_add);
            return move_to_list;
        }
    }

    // Piece is black
    else
    {
        // Move down one space.
        to_add = {location().first - 1, location().second};
        move_to_list.push_back(to_add);
        if (to_add == move_to)
        {
            return move_to_list;
        }

        // Move down two spaces if at initial location.
        if (location().first == 6)
        {
            to_add = {location().first - 2, location().second};
            if (to_add == move_to)
            {
                move_to_list.push_back(to_add);
                return move_to_list;
            }
        }

        move_to_list.clear();

        // Move diagonally bottom right if capturing a piece.
        to_add = {location().first - 1, location().second + 1};
        if (to_add == move_to)
        {
            move_to_list.push_back(to_add);
            return move_to_list;
        }

        // Move diagonally bottom left if capturing a piece.
        to_add = {location().first - 1, location().second - 1};
        if (to_add == move_to)
        {
            move_to_list.push_back(to_add);
            return move_to_list;
        }
    }

    return move_to_list;
}

// Returns all possible squares the pawn can move to.
std::vector<std::vector<std::pair<int, int>>> Pawn::allMoveCheck()
{
    std::pair<int, int> to_add;
    std::vector<std::vector<std::pair<int, int>>> move_to_list;

    // Piece is white.
    if (color() == WHITE)
    {
        // Move up one space.
        to_add = {location().first + 1, location().second};
        std::vector<std::pair<int, int>> up;
        if (checkBounds(to_add))
        {
            up.push_back(to_add);
        }

        // Move up two spaces if at initial location.
        if (location().first == 1)
        {
            to_add = {location().first + 2, location().second};
            up.push_back(to_add);
        }

        move_to_list.push_back(up);

        // Move diagonally top right if capturing a piece.
        to_add = {location().first + 1, location().second + 1};
        if (checkBounds(to_add))
        {
            std::vector<std::pair<int, int>> diag_top_right;
            diag_top_right.push_back(to_add);
            move_to_list.push_back(diag_top_right);
        }

        // Move diagonally top left if capturing a piece.
        to_add = {location().first + 1, location().second - 1};
        if (checkBounds(to_add))
        {
            std::vector<std::pair<int, int>> diag_top_left;
            diag_top_left.push_back(to_add);
            move_to_list.push_back(diag_top_left);
        }
    }

    // Piece is black.
    else
    {
        // Move down one space.
        to_add = {location().first - 1, location().second};
        std::vector<std::pair<int, int>> down;
        if (checkBounds(to_add))
        {
            down.push_back(to_add);
        }

        // Move down two spaces if at initial location.
        if (location().first == 6)
        {
            to_add = {location().first - 2, location().second};
            down.push_back(to_add);
        }

        move_to_list.push_back(down);

        // Move diagonally bottom right if capturing a piece.
        to_add = {location().first - 1, location().second + 1};
        if (checkBounds(to_add))
        {
            std::vector<std::pair<int, int>> diag_bottom_right;
            diag_bottom_right.push_back(to_add);
            move_to_list.push_back(diag_bottom_right);
        }

        // Move diagonally bottom left if capturing a piece.
        to_add = {location().first - 1, location().second - 1};
        if (checkBounds(to_add))
        {
            std::vector<std::pair<int, int>> diag_bottom_left;
            diag_bottom_left.push_back(to_add);
            move_to_list.push_back(diag_bottom_left);
        }
    }

    return move_to_list;
}