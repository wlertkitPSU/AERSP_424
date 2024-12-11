#include <iostream>
#include <vector>
#include "Pieces.h"
#include "Bishop.h"
using namespace std;

Bishop::Bishop(int color)
{
    isWhite = color;
    isAlive = true;

    if (color == 0) {
    x = 0;
    } else {
    x = 7;
    }

    occupying_piece_value = -2; // bishops have a value of -2
}

//Calculating all possible bishop moves on the board and stores them into the possibleMoves vector
vector<Square> Bishop::getMoves(Square cells[][8], int x, int y) 
{
    possibleMoves.clear();

    // Iterate diagonally in all four directions until the edge of the board is found

    //Top right
    int a = x + 1, b = y + 1; 
    while (a <= 7 && b <= 7)
    {
        //add all empty spaces to possible moves
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);

        //break if enemy is found
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;

        //break if ally is found
        else
        {
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        //checks the next square
        a++;
        b++;
    }

    // bottom right
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

    //Bottom left
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

    //Bottom right
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
    return possibleMoves;
}