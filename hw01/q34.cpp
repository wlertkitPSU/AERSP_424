#include "q2.h"
#include "q34.h"

// constructor
Plane::Plane() {
    cin >> origin >> destination;
    distance_map = distance_init();
}

// destructor
Plane::~Plane() {
    cout << "Plane Destroyed" << endl;
}

// operate function
void Plane::operate(double dt) {
    if (pos < distance_map[origin][destination]) {
        pos += vel * dt;
        at_SCE = false;
    } else {
        if (destination == "SCE") {
            string temp;
            at_SCE = true;
            temp = origin;
            origin = destination;
            destination = temp;
            pos = 0.0;
        }
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