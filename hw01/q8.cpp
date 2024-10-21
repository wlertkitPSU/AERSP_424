#include "q2.cpp"
#include "q34.cpp"
#include "q68.cpp"


#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main ()
{
    std::string pilotname;
    std::string copilotname;
    std::string from;
    std::string to;

    cout << "Please input the pilot's name." << endl;
    std::cin >> pilotname;
    cout << "Please input the co-pilot's name." << endl;
    std::cin >> copilotname;

    cout << "Please input your starting airport code (in caps)." << endl;
    std::cin >> from;
    cout << "Please input the airport code (in caps) that you would like to fly to." << endl;
    std::cin >> to;

    std::cout << "################ Question 7 ##########################" << endl;
    Pilot pilot(pilotname);
    Pilot copilot(copilotname);

    // Making a smart pointer to the object plane
    pilot.myPlane = std::make_unique<Plane>(from,to);
    copilot.myPlane = NULL;

    // Setting the plane's velocity (in miles per hour)
    double velocity = 400;
    pilot.myPlane->setVelocity(velocity);

    // Setting the timestep
    double timestep = 10;

    // Setting the number of iterations
    double maxiterations = 1000;
    

    std::cout << "Pilot " << pilot.getName()  << " with certificate number "  << &pilot <<   " is in control of the plane: "  << pilot.myPlane.get() << endl; 
    std::cout << "Pilot "  << copilot.getName() << " with certificate number " << &copilot <<   " is in control of the plane: " << copilot.myPlane.get() << endl;
    std::cout << "" << endl;
    
    int i = 0;
    while (i <= maxiterations)
    {
        // If statement that checks which value is null and which is not to avoid segmentation error
        if((pilot.myPlane && pilot.myPlane->getAt_SCE()) || (copilot.myPlane && copilot.myPlane->getAt_SCE())){
            
            // If statement that checks which value is null and which is not to avoid segmentation error
            if(pilot.myPlane)
            {
            std::cout << "The plane " << pilot.myPlane.get() << " is at SCE!" << endl;
            }
            else if(copilot.myPlane)
            {
            std::cout << "The plane " << copilot.myPlane.get() << " is at SCE!" << endl;   
            }
            
            //swap who is in control of the plane
            std::swap(pilot.myPlane, copilot.myPlane);

            //print who is in control of the plane
            std::cout << "Pilot " << pilot.getName() << " with certificate number: " <<  &pilot << " is in control of the plane: " << pilot.myPlane.get() << endl; 
            std::cout << "Pilot " << copilot.getName() << " with certificate number: " << &copilot << " is in control of the plane: " << copilot.myPlane.get() << endl;
            std::cout << "" << endl;
        }

        // while loop, terminates when plane reaches destination
        // If statement that checks which value is null and which is not to avoid segmentation error. It will use whichever pointer is not null to run the operate function.
        if (pilot.myPlane) {
            pilot.myPlane->operate(timestep);
            if (pilot.myPlane->getPosition() == 0){
                cout << "Navigation from " << pilot.myPlane->getOrigin() << " to " << pilot.myPlane->getDestination() << " has been completed. On to the next leg!" << endl;
            }
        }

        if (copilot.myPlane) {
            copilot.myPlane->operate(timestep);
            if (copilot.myPlane->getPosition() == 0){
                cout << "Navigation from " << copilot.myPlane->getOrigin() << " to " << copilot.myPlane->getDestination() << " has been completed. On to the next leg!" << endl;
            }
        }

        ++i;
    }

    return 0;

    
}