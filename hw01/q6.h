#ifndef Q6_H
#define Q6_H

#include <iostream>
#include <string>
#include "q34.h"

using namespace std;

class Pilot {
private:
    string name;

public:
    // constructor
    Pilot(string pilotName);

    // destructor
    ~Pilot();

    // get functions
    string getName();

    // pointer to Plane class
    Plane* myPlane;
};

#endif