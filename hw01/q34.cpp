#include "q2.h"
#include "q34.h"

// constructor
Plane::Plane() {
    cout << "Enter Origin: ";
    cin >> origin;
    cout << "Enter Destination: ";
    cin >> destination;
    distance_map = distance_init();
    pos = 0;
    vel = 0;
    at_SCE = 0;
    distance = distance_map[origin][destination];
    cout << "Plane created at memory address " << this << endl;
}

// destructor
Plane::~Plane() {
    cout << "Plane destroyed" << endl;
}

// operate function
void Plane::operate(double dt) {
    if (pos < distance_map[origin][destination]) {
        pos += vel/3600 * dt;
        at_SCE = 0;
    } else {
        if (destination == "SCE") {
            at_SCE = 1;
        } else {
            string temp;
            temp = origin;
            origin = destination;
            destination = temp;
            pos = 0.0;
            at_SCE = 1;
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