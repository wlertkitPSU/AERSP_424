#include "q34.h"
#include "q6.h"

// constructor
Pilot::Pilot(string pilotName) : name(pilotName){
    cout << "Pilot " << getName() << ", ID: " << this << ", is at the gate and ready to board the plane" << endl;
};

// destructor
Pilot::~Pilot() {
    cout << "Pilot " << getName() << " has left the plane" << endl;
}

// get pilot name
string Pilot::getName(){
    return name;
}