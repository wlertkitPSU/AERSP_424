#include "q1.h"
#include "sensorFactory.h"
#include "aerospaceControlSystem.h"
#include "matplot/matplot.h"

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

    // QUESTION 4
    std::cout << "#################### QUESTION 4 ####################" << std::endl;
    
    // Generating meshgrid
    std::vector<double> x = matplot::iota(-5, 0.1, 0.5);
    std::vector<double> y = matplot::iota(-5, 0.1, 0.5);
    auto [X, Y] = matplot::meshgrid(x, y);

    // Computing z = sin(sqrt(x^2 + y^2))
    auto z = [](double x, double y){
        return std::sin(std::sqrt(x*x + y*y));
    };
    auto Z = matplot::transform(X, Y, z);

    // Plotting
    auto fig = matplot::figure();
    auto ax = fig->add_axes();
    ax->surf(X, Y, Z);

    std::cout << "##################### END OF QUESTION 4 #####################" << std::endl;
    return 0;
}