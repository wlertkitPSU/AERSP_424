#ifndef Q1_H
#define Q1_H

#include <iostream>
#include "sensor.h"

// Temperature Sensor
class tempSensor : public Sensor {
    public:
        tempSensor();
        ~tempSensor();
        void gatherData();
        void processData();
};

// Altitude Sensor
class altSensor : public Sensor {
    public:
        altSensor();
        ~altSensor();
        void gatherData();
        void processData();
};

// Airspeed Sensor
class velSensor : public Sensor {
    public:
        velSensor();
        ~velSensor();
        void gatherData();
        void processData();
};

#endif