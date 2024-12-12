#ifndef KING_H
#define KING_H

#include <vector>
#include "Square.h"
#include "Pieces.h"
#include "Square.h"

class King : public Pieces
{
public:
    King(int);
    bool isStaleMate(Square Cells[][8], int x, int y);
    bool isCheck(Square Cells[][8], int x, int y);
    bool isCheckmate(Square Cells[][8], int x, int y);
    vector<Square> getMoves(Square cells[][8], int x, int y);

protected:
private:
};

#endif // KING_H