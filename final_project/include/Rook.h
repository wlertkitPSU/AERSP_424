#ifndef ROOK_H
#define ROOK_H
#include "Pieces.h"
#include <vector>
using namespace std;
class Rook : public Pieces
{
public:
  Rook(int);
  vector<Square> getMoves(Square cells[][8], int x, int y);

protected:
private:
};

#endif // ROOK_H