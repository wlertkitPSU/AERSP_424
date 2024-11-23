#include "aerospaceControlSystem.h"

void AerospaceControlSystem::addSensor(Sensor* sensorPtr){
    AerospaceControlSystem::sensorPtrArray.push_back(sensorPtr);
}

void AerospaceControlSystem::monitorAndAdjust(){
    for (std::size_t i=0; i != AerospaceControlSystem::sensorPtrArray.size(); ++i){
        sensorPtrArray[i]->gatherData();
        sensorPtrArray[i]->processData();
        std::cout << "Adjusting controls based on sensor data" << std::endl;
    }
}