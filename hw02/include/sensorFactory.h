#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include <iostream>
#include <string>
#include "q1.h"

class SensorFactory {
    public:
        static Sensor* createSensor(std::string sensorName);
};

#endif