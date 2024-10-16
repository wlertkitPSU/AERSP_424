#include "q34.h"
#include "q2.h"
#include <iostream>

using namespace std;

int main(){
    Plane myplane;
    myplane.setVelocity(400);
    int timestep = 10;
    int maxiterations = 1000;
    for (int i = 0; i < maxiterations; ++i){
        myplane.operate(timestep);
        cout << timestep * i << " " << myplane.getPosition() << endl;

    }
    return 0;
}