#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "Square.h"
#include "Pieces.h"
#include "Square.h"
using namespace std;

class Knight : public Pieces
{
public:
    Knight(int);
    vector<Square> getMoves(Square cells[][8], int x, int y);

protected:
private:
};

#endif // KNIGHT_H