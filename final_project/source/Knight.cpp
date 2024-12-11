#include <iostream>
#include <vector>
#include "Pieces.h"
#include "Knight.h"
using namespace std;

Knight::Knight(int color)
{
    isWhite = color;
    isAlive = true;
    
    if (color == 0) {
    x = 0;
    } else {
    x = 7;
    }

    occupying_piece_value = -1;
}

// Method returning all possible knight moves
std::vector<Square> Knight::getMoves(Square Cells[][8], int x, int y)
{
    possibleMoves.clear();
    static const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1}; // all possible in x
    static const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2}; // all possible in y
    for (int i = 0; i < 8; i++)
    {
        //check to make sure move is within bounds of board in x and y
        if (x + dx[i] > 7 || x + dx[i] < 0)
        {
            continue;
        }
        if (y + dy[i] > 7 || y + dy[i] < 0)
        {
            continue;
        }

        //check to make sure piece is not occupying this area
        if (Cells[x + dx[i]][y + dy[i]].occupied_color == Cells[x][y].occupied_color)
            continue;

        //Storing all valid moves
        possibleMoves.push_back(Cells[x + dx[i]][y + dy[i]]);
    
    }
    return possibleMoves;
}