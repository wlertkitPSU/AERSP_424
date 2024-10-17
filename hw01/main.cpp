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

    for (double i = 0; i < maxiterations; ++i){
        myplane.operate(timestep);
        cout << "Time:" << " " << timestep * i << " " << "Positon: " << myplane.getPosition() << " " <<"miles" << endl;

    }
    return 0;
}