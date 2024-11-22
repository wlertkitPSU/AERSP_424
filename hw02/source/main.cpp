#include <q1.h>
#include <q2.h>
#include <q4.h>
#include <sensorFactory.h>
#include <aerospaceControlSystem.h>
#include <matplot/matplot.h>

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

    // QUESTION 2
     std::cout << "#################### QUESTION 2 ####################" << std::endl;

    RobotTaskManager manager;

    // Start the tasks for all robots
    manager.startTasks();

    std::cout << "##################### END OF QUESTION 2 #####################" << std::endl;

    // QUESTION 4
    std::cout << "#################### QUESTION 4 ####################" << std::endl;
    
    // Creating a 3D graph
    create3DGraph();
    std::cout << "Output graph is shown in graph_3D.jpg" << std::endl;

    // Read from CSV file and plot
    csvPlot();
    std::cout << "Output graph is shown in butterfly_curve.jpg" << std::endl;

    std::cout << "##################### END OF QUESTION 4 #####################" << std::endl;
    return 0;
}