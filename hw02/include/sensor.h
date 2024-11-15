#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

// Sensor Class
class Sensor {
public:
    virtual void gatherData() = 0;
    virtual void processData() = 0;
};

#endif