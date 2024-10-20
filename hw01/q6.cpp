#include "q6.h"
#include "q34.h"


//Question 6
    // Constructor
    Pilot::Pilot(std::string pilotname) 
    {
        name = pilotname;
        
        cout << "Pilot "  << name << " with certificate number: " << &name << " is at the gate, ready to board the plane." << endl; 
    }

    // Deconstructor
    Pilot::~Pilot() 
    {
        cout << "Pilot " << name << " has deboarded the aircraft." << endl;
    }

    string Pilot::getName()
    {
        return name;   
    }

