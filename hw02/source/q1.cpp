#include "q1.h"

// Temperature Sensor
void tempSensor::gatherData(){
    std::cout << "Gathering data from Temperature Sensor" << std::endl;
    Sensor::gatherData();
}

void tempSensor::processData(){
    std::cout << "Processing data from Temperature Sensor" << std::endl;
    Sensor::processData();
}

// Altitude Sensor
void altSensor::gatherData(){
    std::cout << "Gathering data from Altitude Sensor" << std::endl;
    Sensor::gatherData();
}

void altSensor::processData(){
    std::cout << "Processing data from Altitude Sensor" << std::endl;
    Sensor::processData();
}

// Airspeed Sensor
void velSensor::gatherData(){
    std::cout << "Gathering data from Airspeed Sensor" << std::endl;
    Sensor::gatherData();
}

void velSensor::processData(){
    std::cout << "Processing data from Airspeed Sensor" << std::endl;
    Sensor::processData();
}