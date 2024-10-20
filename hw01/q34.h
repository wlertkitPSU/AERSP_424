#ifndef Q34_H
#define Q34_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Plane {
private:
    double pos, vel, distance;
    bool at_SCE;
    string origin, destination;
    map<string, map<string, int>> distance_map;

public:
    // constructor
    Plane(std::string from, std::string to);

    // destructor
    ~Plane();

    // operate function
    void operate(double dt);

    // get functions
    double getPosition();
    string getOrigin();
    string getDestination();
    bool getAt_SCE();
    double getVelocity();

    // set functions
    void setVelocity(double new_vel);
};

#endif