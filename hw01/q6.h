#ifndef Q6_H
#define Q6_H

#include <iostream>
#include <string>
#include "q34.h"

using namespace std;

class Pilot
{
private:
std::string name;
    

public:

    // constructor
    Pilot(std::string pilotname);

    // destructor
    ~Pilot();

    // get functions
    string getName();

    // pointer to Plane class
    Plane* myPlane;

};

#endif