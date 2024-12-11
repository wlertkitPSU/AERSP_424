#pragma once

#include <iostream>
#include <vector>
#include "Pieces.h"

class Pawn : public Pieces
{
public:
    Pawn(int);
    vector<Square> getMoves(Square cells[][8], int x, int y);

};
