#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
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

    // QUESTION 2
    std::cout<< "TIME_GRABBING_TOOL:   " << "500" << std::endl;
    std::cout << "TIME_LANDING_TOOL:   " << "500" << std::endl;
    std::cout << "TIME_USING_TOOL:     " << "1000" << std::endl;
    
    std::cout << "#################### QUESTION 2 ####################" << std::endl;

    std::mutex m1,m2,m3,m4,m5;
    std::mutex m0;

    std::thread t0([&] {robots(0,m1,m2,m0);});
    std::thread t1([&] {robots(1,m2,m3,m0);});
    std::thread t2([&] {robots(2,m3,m4,m0);});
    std::thread t3([&] {robots(3,m4,m5,m0);});
    std::thread t4([&] {robots(4,m5,m1,m0);});
    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "##################### END OF QUESTION 2 #####################" << std::endl;

    // QUESTION 3

    std::cout << "#################### QUESTION 3 ####################" << std::endl;

    int MAX_TRAFFIC_PATTERN = 3;
    int TOTAL_AIRCRAFT = 10;

    // Shared resources
    std::queue<int> trafficPattern; // Queue for aircraft in runway
    std::mutex mtx;
    std::condition_variable cv; // Condition variable for ATC sleep/wake
    std::atomic<bool> atc_quit = false;

    std::thread atc(airTrafficController, std::ref(mtx), std::ref(trafficPattern), std::ref(cv), std::ref(atc_quit), MAX_TRAFFIC_PATTERN);
    std::vector<std::thread> aircraftThreads;

    // Create 10 aircraft threads
    for (int i = 0; i < TOTAL_AIRCRAFT; ++i)
    {
        aircraftThreads.push_back(std::thread(aircraft, i + 1, std::ref(mtx), std::ref(trafficPattern), std::ref(cv), std::ref(atc_quit), MAX_TRAFFIC_PATTERN));
    }

     // Join aircraft threads
    for (auto& t : aircraftThreads)  // Iterating over the vector of threads and joining them
    {
        t.join();
    }

    // End ATC if aircraft threads finish
    atc_quit = true;
    cv.notify_one();
    atc.join();

    std::cout << "################# End of Question 3 #############.\n";


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