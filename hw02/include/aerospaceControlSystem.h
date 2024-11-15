#ifndef AEROSPACECONTROLSYSTEM_H
#define AEROSPACECONTROLSYSTEM_H

#include <iostream>
#include <vector>
#include "q1.h"

class AerospaceControlSystem {
    private:
        std::vector<Sensor*> sensorPtrArray;

    public:
        void addSensor(Sensor* sensorPtr);
        void monitorAndAdjust();
};

#endif