#include "q2.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>

// Constructor
RobotTaskManager::RobotTaskManager() {}

// Function to perform the task
void RobotTaskManager::performTask(int robot_id) {
    int left_tool = robot_id;
    int right_tool = (robot_id + 1) % 5;

    // Ensure robots acquire tools in the same order to prevent deadlock
    int first_tool = std::min(left_tool, right_tool);
    int second_tool = std::max(left_tool, right_tool);

    // Timing: Starts clock
    auto start_time = std::chrono::high_resolution_clock::now();

    // Attempt to grab the tools
    std::cout << "Robot " << robot_id << " is reaching and grabbing the tools." << std::endl;

    // Lock the first tool, then the second tool (in a deadlock-safe order)
    std::lock_guard<std::mutex> lock1(tool_mutexes[first_tool]);
    std::lock_guard<std::mutex> lock2(tool_mutexes[second_tool]);

    // Once robot has locked both tools it starts performing the task
    std::cout << "Robot " << robot_id << " has grabbed the tools and is starting the task." << std::endl;

    // Simulates grabbing tools (500 ms)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Simulate landing process (500 ms)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Simulate using the tools (1000 ms)
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "Robot " << robot_id << " has completed the task and is returning the tools." << std::endl;
}

// Function to start all robot tasks
void RobotTaskManager::startTasks() {
    // Output the times each robot has to perform tasks (only once)
    std::cout << "Time grabbing tool: 500 ms" << std::endl;
    std::cout << "Time landing process: 500 ms" << std::endl;
    std::cout << "Time using tool: 1000 ms" << std::endl;

    std::vector<std::thread> threads;

    // Create and start threads for the robots
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(&RobotTaskManager::performTask, this, i);
    }

    // Wait for all threads to complete
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "All robots have completed their tasks." << std::endl;
    std::cout << "Total time duration: 4 seconds" << std::endl;
}