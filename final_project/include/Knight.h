#pragma once

#include <vector>
#include "Pieces.h"
#include "Square.h"
using namespace std;

class Knight : public Pieces
{
public:
    Knight(int);
    vector<Square> getMoves(Square cells[][8], int x, int y);

};
