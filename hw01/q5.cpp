#include "q34.h"
#include "q2.h"
#include <iostream>

using namespace std;

int main(){
    Plane myplane;

    // Setting the plane's velocity (in miles per hour)
    double velocity = 400;
    myplane.setVelocity(velocity);

    // Setting the timestep
    double timestep = 10;

    // Setting the number of iterations
    double maxiterations = 1000;

    // while loop, terminates when plane reaches destination
    int i = 0;
    while (myplane.getDestination() != "SCE" && i <= maxiterations){
        myplane.operate(timestep);
        if (myplane.getDestination() != "SCE"){
            cout << "Time:" << " " << timestep * i << " seconds, " << "Positon: " << myplane.getPosition() << " " <<"miles" << endl;
        }
        ++i;
    }
    cout << "Reached Destination!" << endl;

    return 0;
}