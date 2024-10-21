#ifndef Q68_H
#define Q68_H

#include <iostream>
#include <string>
#include <memory>
#include "q34.h"



using namespace std;

// Modified question 6 (used in q8)
class Pilot
{
private:
std::string name;
    

public:

    std::unique_ptr<Plane> myPlane;

    // constructor
    Pilot(std::string pilotname);

    // destructor
    ~Pilot();

    // get functions
    string getName();



};

#endif