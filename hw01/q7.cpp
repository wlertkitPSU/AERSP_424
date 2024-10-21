#include "q34.h"
#include "q6.h"
#include "q2.h"

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main ()
{
    std::string pilotname;
    std::string copilotname;
    std::string planename;
    std::string from;
    std::string to;

    cout << "Please input the pilot's name." << endl;
    std::cin >> pilotname;
    cout << "Please input the co-pilot's name." << endl;
    std::cin >> copilotname;

    cout << "Please input your starting airport." << endl;
    std::cin >> from;
    cout << "Please input the airport you would like to fly to." << endl;
    std::cin >> to;

    std::cout << "################ Question 7 ##########################" << endl;
    Pilot pilot(pilotname);
    Pilot copilot(copilotname);
    Plane plane(from, to);

    // Setting the plane's velocity (in miles per hour)
    double velocity = 400;
    plane.setVelocity(velocity);

    // Setting the timestep
    double timestep = 10;

    // Setting the number of iterations
    double maxiterations = 1000;

    pilot.myPlane = &plane;
    copilot.myPlane = NULL;
    
    std::cout << "Pilot " << pilot.getName()  << " with certificate number "  << &pilot <<   " is in control of the plane: "  << pilot.myPlane << endl; 
    std::cout << "Pilot "  << copilot.getName() << " with certificate number " << &copilot <<   " is in control of the plane: " << copilot.myPlane << endl;
    std::cout << "" << endl;
    
    int i = 0;
    while (i <= maxiterations)
    {
        if(plane.getAt_SCE()){
            std::cout << "The plane " << &plane << " is at SCE!" << endl;
            
            Plane *temp;
            temp = pilot.myPlane;
            pilot.myPlane = copilot.myPlane;
            copilot.myPlane = temp;

            std::cout << "Pilot " << pilot.getName() << " with certificate number: " <<  &pilot << " is in control of the plane: " << pilot.myPlane << endl; 
            std::cout << "Pilot " << copilot.getName() << " with certificate number: " << &copilot << " is in control of the plane: " << copilot.myPlane<< endl;
            std::cout << "" << endl;
        }

        // while loop, terminates when plane reaches destination
        plane.operate(timestep);
        if (plane.getPosition() == 0){
            cout << "Navigation from " << plane.getOrigin() << " to " << plane.getDestination() << " has been completed. On to the next leg!" << endl;
        }
        
        ++i;
    }

    return 0;

    
}