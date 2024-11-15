#include "q1.h"

// Temperature Sensor
void tempSensor::gatherData(){
    Sensor::gatherData();
    std::cout << "Gathering data from Temperature Sensor" << std::endl;
}

void tempSensor::processData(){
    Sensor::processData();
    std::cout << "Processing data from Temperature Sensor" << std::endl;
}

// Altitude Sensor
void altSensor::gatherData(){
    Sensor::gatherData();
    std::cout << "Gathering data from Altitude Sensor" << std::endl;
}

void altSensor::processData(){
    Sensor::processData();
    std::cout << "Processing data from Altitude Sensor" << std::endl;
}

// Airspeed Sensor
void velSensor::gatherData(){
    Sensor::gatherData();
    std::cout << "Gathering data from Airspeed Sensor" << std::endl;
}

void velSensor::processData(){
    Sensor::processData();
    std::cout << "Processing data from Airspeed Sensor" << std::endl;
}