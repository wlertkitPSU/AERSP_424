#include "sensorFactory.h"

Sensor* SensorFactory::createSensor(std::string sensorName){
    if (sensorName == "Temperature"){
        return new tempSensor;
    } else if (sensorName == "Altitude"){
        return new altSensor;
    } else if (sensorName == "Airspeed"){
        return new velSensor;
    } else {
        return nullptr;
    }
}