#include "q1.h"
#include "q2.h"
#include "sensorFactory.h"
#include "aerospaceControlSystem.h"

int main() {
    // QUESTION 1
    std::cout << "#################### QUESTION 1 ####################" << std::endl;

    // Creating sensors
    Sensor* tempSensorPtr = SensorFactory::createSensor("Temperature");
    Sensor* altSensorPtr = SensorFactory::createSensor("Altitude");
    Sensor* velSensorPtr = SensorFactory::createSensor("Airspeed");

    // Control system
    AerospaceControlSystem ctrlSys;
    ctrlSys.addSensor(tempSensorPtr);
    ctrlSys.addSensor(altSensorPtr);
    ctrlSys.addSensor(velSensorPtr);
    ctrlSys.monitorAndAdjust();

    // Removing memory address after finishing to prevent memory leak
    delete tempSensorPtr;
    delete altSensorPtr;
    delete velSensorPtr;

    std::cout << "##################### END OF QUESTION 1 #####################" << std::endl;
    return 0;

    // QUESTION 2
    std::cout << "#################### QUESTION 2 ####################" << std::endl;

    RobotTaskManager manager;
    manager.startTasks();

    std::cout << "##################### END OF QUESTION 2 #####################" << std::endl;
    return 0;
}