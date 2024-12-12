#pragma once

#include <iostream>
#include <vector>
#include"square.h"
using namespace std;

class Pieces
{
public:
    
    int x, y;
    bool isAlive;
    bool isWhite;
    bool occupying_piece_color;
    int occupying_piece_value;

    vector<Square> possibleMoves;
    virtual vector<Square> getMoves(Square Cells[][8], int x, int y) = 0;

    bool isValidMove(int destX, int destY, Square Cells[][8]); // Validates the move
    void setPosition(int newX, int newY); // Updates the piece's position
    
    
};

