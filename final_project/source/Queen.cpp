#include <iostream>
#include "Pieces.h"
#include "Queen.h"

Queen::Queen(int color)
{
    isWhite = color;
    isAlive = true;
    
    if (color == 0) {
    x = 0;
    } else {
    x = 7;
    }
    
    y = 3;
    occupying_piece_value = 2;
}

// Checking all possible Queen moves
vector<Square> Queen::getMoves(Square cells[][8], int x, int y)
{
    possibleMoves.clear();

    // Down right
    int a = x + 1, b = y + 1;
    while (a <= 7 && b <= 7)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else
        {
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a++;
        b++;
    }

    // Down Left
    a = x + 1, b = y - 1;
    while (a <= 7 && b >= 0)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else
        {
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a++;
        b--;
    }
    // up left
    a = x - 1, b = y - 1;
    while (a >= 0 && b >= 0)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else
        {
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a--;
        b--;
    }
    // up right
    a = x - 1, b = y + 1;
    while (a >= 0 && b <= 7)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else
        {
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a--;
        b++;
    }
    // up
    int r = x - 1;
    while (r >= 0)
    {
        if (cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if (cells[r][y].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[r][y].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[r][y]);
            break;
        }
        r--;
    }
    // down
    r = x + 1;
    while (r <= 7)
    {
        if (cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if (cells[r][y].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[r][y].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[r][y]);
            break;
        }
        r++;
    }
    // left
    r = y - 1;
    while (r >= 0)
    {
        if (cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if (cells[x][r].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[x][r].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[x][r]);
            break;
        }
        r--;
    }
    // right
    r = y + 1;
    while (r <= 7)
    {
        if (cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if (cells[x][r].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[x][r].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[x][r]);
            break;
        }
        r++;
    }
    return possibleMoves;
}