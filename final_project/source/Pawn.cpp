#include <iostream>
#include "Pieces.h"
#include "Pawn.h"
#include "Game.h"

Pawn::Pawn(int color)
{
    isWhite = color;
    isAlive = true;

    if (color == 0) {
    x = 0;
    } else {
    x = 7;
    }
    
    occupying_piece_value = -3;
}

// Stores all possible moves for the pawn
vector<Square> Pawn::getMoves(Square cells[][8], int x, int y)
{
    possibleMoves.clear();

    //black pawn
    if (cells[x][y].occupied_color == -1)
    {
         // can move twice if it hasn't moved yet
        if(x == 1)
            if(cells[x + 2][y].occupied_color == 0)
                possibleMoves.push_back(cells[x + 2][y]);

        // otherwise move once
        if (x != 7)
            if (cells[x + 1][y].occupied_value == 0 && cells[x + 1][y].occupied_color == 0)
                possibleMoves.push_back(cells[x + 1][y]);

        //Diagonal captures
        if (y != 0 && cells[x + 1][y - 1].occupied_color == 1)
            possibleMoves.push_back(cells[x + 1][y - 1]);
        if (y != 7 && cells[x + 1][y + 1].occupied_color == 1)
            possibleMoves.push_back(cells[x + 1][y + 1]);
    }

    //white pawn
    if (cells[x][y].occupied_color == 1)
    {

        // can move twice if it hasn't moved yet
        if(x == 6)
            if(cells[x - 2][y].occupied_color == 0)
                possibleMoves.push_back(cells[x - 2][y]);
        // otherwise move once
        if (x != 0)
            if (cells[x - 1][y].occupied_value == 0 && cells[x - 1][y].occupied_color == 0)
                possibleMoves.push_back(cells[x - 1][y]);
        
        //Diagonal Capture
        if (y != 0 && cells[x - 1][y - 1].occupied_color == -1)
            possibleMoves.push_back(cells[x - 1][y - 1]);
        if (y != 7 && cells[x - 1][y + 1].occupied_color == -1)
            possibleMoves.push_back(cells[x - 1][y + 1]);
    }
    return possibleMoves;
}