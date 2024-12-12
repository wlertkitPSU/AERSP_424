#pragma once

#include <iostream>
#include <vector>
#include "Pieces.h"
using namespace std;

class Bishop : public Pieces
{
public:
    Bishop(int color);
    vector<Square> getMoves(Square cells[][8], int x, int y);

};

