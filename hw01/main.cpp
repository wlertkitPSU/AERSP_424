#include "q34.h"
#include "q2.h"
#include <iostream>

using namespace std;

int main(){
    Plane myplane;

    // Setting the plane's velocity (in miles per hour)
    double velocity;
    cout << "Enter the plane's velocity between 400 mph and 500 mph: ";
    cin >> velocity;
    myplane.setVelocity(velocity);

    // Setting the timestep
    double timestep;
    cout << "Enter the timestep between 10 and 100 seconds: ";
    cin >> timestep;

    // Setting the number of iterations
    double maxiterations;
    cout << "Enter the maximum number of iterations between 1000 and 2000: ";
    cin >> maxiterations;

    // while loop, terminates when plane reaches destination
    int i = 0;
    while (myplane.getAt_SCE() == 0 && i <= maxiterations){
        myplane.operate(timestep);
        if (myplane.getAt_SCE() == 0){
            cout << "Time:" << " " << timestep * i << " seconds, " << "Positon: " << myplane.getPosition() << " " <<"miles" << endl;
        }
        ++i;
    }
    cout << "Reached Destination!" << endl;

    return 0;
}