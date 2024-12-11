#include <iostream>
#include "Pieces.h"
#include <vector>
#include "Rook.h"
using namespace std;

Rook::Rook(int color)
{
    isWhite = color;
    isAlive = true;

    
    occupying_piece_value = 1;
    if (color == 0) {
    x = 0;
    } else {
    x = 7;
    }

}

//Finds all possible rook moves
vector<Square> Rook::getMoves(Square cells[][8], int x, int y)
{
    possibleMoves.clear();

    //checks down
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
    //checks up
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
    //checks left
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
    //checks right
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