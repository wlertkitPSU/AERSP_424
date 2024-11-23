#include "sensor.h"

Sensor::Sensor(){}

Sensor::~Sensor(){}

void Sensor::gatherData(){
    std::cout << "Data Gathered!" << std::endl;
}

void Sensor::processData(){
    std::cout << "Data Processed!" << std::endl;
}