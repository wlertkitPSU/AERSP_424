#include "q3.h"


using namespace std;

// Function for aircraft behavior
void aircraft(int id, std::mutex& mtx, std::queue<int>& trafficPattern, std::condition_variable& cv, std::atomic<bool>& atc_quit, int MAX_TRAFFIC_PATTERN)
{
    unique_lock<mutex> lock(mtx);
    std::cout << "Aircraft " << id << " is requesting to land.\n";
    if (trafficPattern.size() > MAX_TRAFFIC_PATTERN)
    {
        std::cout << "diverted aircraft " << id << std::endl;
        return;
    }
    trafficPattern.push(id);
    lock.unlock();
    cv.notify_one();
}

// Function for ATC behavior
void airTrafficController(std::mutex& mtx, std::queue<int>& trafficPattern, std::condition_variable& cv, std::atomic<bool>& atc_quit, int MAX_TRAFFIC_PATTERN)
{
    while (!atc_quit || !trafficPattern.empty())
    {
        unique_lock<mutex> lock(mtx);

        // Sleep until there are aircraft in the pattern or one arrives
        cv.wait(lock, [&]
                { return atc_quit || !trafficPattern.empty(); });

        if (!trafficPattern.empty())
        {
            // Handle the next aircraft
            int currentAircraft = trafficPattern.front();
            trafficPattern.pop();
            std::cout << "ATC handling Aircraft " << currentAircraft << ".\n";   // debug statement
            std::this_thread::sleep_for(chrono::seconds(1));                     // 1 second delay for landing
            std::cout << "ATC has landed Aircraft " << currentAircraft << ".\n"; // debug statement
        }
    }
}


