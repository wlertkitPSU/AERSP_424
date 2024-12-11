#include <iostream>
#include <vector>
#include "Pieces.h"
#include "King.h"
using namespace std;

King::King(int color)
{
    isWhite = color;
    isAlive = true;

    if (color == 0) {
    x = 0;
    } else {
    x = 7;
    }

    y = 4;
    occupying_piece_value = 3;
}

// Loop to check all possible moves 
vector<Square> King::getMoves(Square Cells[][8], int x, int y)
{
    possibleMoves.clear();
    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}; // all possible moves.
    int dy[] = {1, -1, 0, -1, 1, 0, -1, 1}; // all possible moves.
    for (int i = 0; i < 8; i++)
    { 
        // Make sure moves are in bounds in x and y
        if (x + dx[i] > 7 || x + dx[i] < 0)
            continue;
        if (y + dy[i] > 7 || y + dy[i] < 0)
            continue;

        // Checks if moves are occupied by ally piece    
        if (Cells[x + dx[i]][y + dy[i]].occupied_color == Cells[x][y].occupied_color)
            continue;
        possibleMoves.push_back(Cells[x + dx[i]][y + dy[i]]);
    }
    return possibleMoves;
}


// Method to check if the king is in check
bool King::isCheck(Square Cells[][8], int x, int y)
{
    // Checks if the king is in check front straight lines
    //The right
    int r = x + 1;
    while (r < 8)
    {
        if (Cells[r][y].occupied_color == 0)
            continue;
        else if (Cells[r][y].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[r][y].occupied_value == 2 || Cells[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r++;
    }
    // The left
    r = x - 1;
    while (r >= 0)
    {
        if (Cells[r][y].occupied_color == 0)
            continue;
        else if (Cells[r][y].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[r][y].occupied_value == 2 || Cells[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r--;
    }
    // From in front
    r = y + 1;
    while (r < 8)
    {
        if (Cells[x][r].occupied_color == 0)
            continue;
        else if (Cells[x][r].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[x][r].occupied_value == 2 || Cells[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r++;
    }
    // From behind
    r = y - 1;
    while (r >= 0)
    {
        if (Cells[x][r].occupied_color == 0)
            continue;
        else if (Cells[x][r].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[x][r].occupied_value == 2 || Cells[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r--;
    }
    // Checks diagonals for any checks

    // Front right
    int a = x + 1, b = y + 1;
    while (a < 8 && b < 8)
    {
        if (Cells[a][b].occupied_color == 0)
            continue;
        else if (Cells[a][b].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[a][b].occupied_value == 2 || Cells[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a++;
        b++;
    }
    // Back Right
    a = x + 1, b = y - 1;
    while (a < 8 && b >= 0)
    {
        if (Cells[a][b].occupied_color == 0)
            continue;
        else if (Cells[a][b].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[a][b].occupied_value == 2 || Cells[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a++;
        b--;
    }
    // Front Left
    a = x - 1, b = y + 1;
    while (a >= 0 && b < 8)
    {
        if (Cells[a][b].occupied_color == 0)
            continue;
        else if (Cells[a][b].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[a][b].occupied_value == 2 || Cells[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a--;
        b++;
    }

    //Back Left
    a = x - 1, b = y - 1;
    while (a >= 0 && b >= 0)
    {
        if (Cells[a][b].occupied_color == 0)
            continue;
        else if (Cells[a][b].occupied_color == Cells[x][y].occupied_color)
            break;
        else
        {
            if (Cells[a][b].occupied_value == 2 || Cells[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a--;
        b--;
    }
    // Checks if another king is putting it in check
    int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int dy[] = {1, -1, 1, -1, 0, 0, -1, 1};
    for (int i = 0; i < 8; i++)
    {
        if (Cells[x + dx[i]][y + dy[i]].occupied_color != Cells[x][y].occupied_color && Cells[x + dx[i]][y + dy[i]].occupied_value == 3)
            return true;
    }
    // Checks to see if a king has it in check
    int xa[] = {2, 2, -2, -2, 1, 1, -1, -1}; // all possible moves.
    int ya[] = {1, -1, 1, -1, 2, -2, 2, -2}; // all possible moves.
    for (int i = 0; i < 8; i++)
    {
        if (Cells[x + xa[i]][y + ya[i]].occupied_color != Cells[x][y].occupied_color && Cells[x + xa[i]][y + ya[i]].occupied_value == -1)
            return true;
    }
    // Checks to see if a pawn has it in check

    //white
    if (Cells[x][y].occupied_color == 1)
    {
        if (x < 8 && y > 0 && Cells[x + 1][y - 1].occupied_color == 0 && Cells[x + 1][y - 1].occupied_value == -3)
            return true;
        if (x < 8 && y < 8 && Cells[x + 1][y + 1].occupied_color == 0 && Cells[x + 1][y + 1].occupied_value == -3)
            return true;
    }
    //black
    else if (Cells[x][y].occupied_color == -1)
    {
        if (x > 0 && y > 0 && Cells[x - 1][y - 1].occupied_color == 0 && Cells[x - 1][y - 1].occupied_value == -3)
            return true;
        if (x > 0 && y < 8 && Cells[x - 1][y + 1].occupied_color == 0 && Cells[x - 1][y + 1].occupied_value == -3)
            return true;
    }
    return false;
}

// checks for checkmate
bool King::isCheckmate(Square Cells[][8], int x, int y)
{
    if (!possibleMoves.size() && isCheck(Cells, x, y))
        return true;
    return false;
}

// Checks for Stalemate
bool King::isStaleMate(Square Cells[][8], int x, int y)
{
    if (!possibleMoves.size() && !isCheck(Cells, x, y))
        return true;
    return false;
}