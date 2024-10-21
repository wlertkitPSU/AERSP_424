#include "q2.h"
#include "q34.h"
#include <cmath> 

// constructor
Plane::Plane(std::string from, std::string to) {
    origin = from;
    destination = to;
    distance_map = distance_init();
    pos = 0;
    vel = 0;
    at_SCE = 0;

    std::cout << "Plane created at " << this << endl;
}

// destructor
Plane::~Plane() {
    cout << "Plane Destroyed" << endl;
}

// operate function
void Plane::operate(double dt) {
    if (round(pos) < distance_map[origin][destination]) {
        pos += vel/3600 * dt;
        at_SCE = false;
    } else {
        if (destination == "SCE") { 
            at_SCE = true;
        }
        string temp;
        temp = origin;
        origin = destination;
        destination = temp;
        pos = 0.0;
    }
}

// get functions
double Plane::getPosition() {
    return pos;
}

string Plane::getOrigin() {
    return origin;
}

string Plane::getDestination() {
    return destination;
}

bool Plane::getAt_SCE() {
    return at_SCE;
}

double Plane::getVelocity() {
    return vel;
}

// set functions
void Plane::setVelocity(double new_vel) {
    vel = new_vel;
}