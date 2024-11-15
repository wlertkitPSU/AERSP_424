#ifndef Q1_H
#define Q1_H

#include <iostream>
#include "sensor.h"

// Temperature Sensor
class tempSensor : public Sensor {
    public:
        void gatherData();
        void processData();
};

// Altitude Sensor
class altSensor : public Sensor {
    public:
        void gatherData();
        void processData();
};

// Airspeed Sensor
class velSensor : public Sensor {
    public:
        void gatherData();
        void processData();
};

#endif