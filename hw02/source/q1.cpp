#include "q1.h"

// Temperature Sensor
tempSensor::tempSensor(){
    std::cout << "Sensor created " << this << " of type Temperature" << std::endl;
}

tempSensor::~tempSensor(){
    std::cout << "Sensor deleted " << this << " of type Temperature" << std::endl;
}

void tempSensor::gatherData(){
    std::cout << "Gathering data from Temperature Sensor" << std::endl;
    Sensor::gatherData();
}

void tempSensor::processData(){
    std::cout << "Processing data from Temperature Sensor" << std::endl;
    Sensor::processData();
}

// Altitude Sensor
altSensor::altSensor(){
    std::cout << "Sensor created " << this << " of type Altitude" << std::endl;
}

altSensor::~altSensor(){
    std::cout << "Sensor deleted " << this << " of type Altitude" << std::endl;
}

void altSensor::gatherData(){
    std::cout << "Gathering data from Altitude Sensor" << std::endl;
    Sensor::gatherData();
}

void altSensor::processData(){
    std::cout << "Processing data from Altitude Sensor" << std::endl;
    Sensor::processData();
}

// Airspeed Sensor
velSensor::velSensor(){
    std::cout << "Sensor created " << this << " of type Airspeed" << std::endl;
}

velSensor::~velSensor(){
    std::cout << "Sensor deleted " << this << " of type Airspeed" << std::endl;
}

void velSensor::gatherData(){
    std::cout << "Gathering data from Airspeed Sensor" << std::endl;
    Sensor::gatherData();
}

void velSensor::processData(){
    std::cout << "Processing data from Airspeed Sensor" << std::endl;
    Sensor::processData();
}