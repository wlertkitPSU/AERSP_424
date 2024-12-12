#pragma once

#include <vector>
#include "Pieces.h"

using namespace std;

class Queen : public Pieces
{
public:
    Queen(int);
    vector<Square> getMoves(Square cells[][8], int x, int y);

};

