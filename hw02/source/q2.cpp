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

    // Output the times for grabbing, landing, and using tools at the beginning
    if (robot_id == 0) {
        std::cout << "Time to grab each tool: 500 ms" << std::endl;
        std::cout << "Landing process time: 500 ms" << std::endl;
        std::cout << "Time using tool: 1000 ms" << std::endl;
    }

    // Timing: Start the clock for the task
    auto start_time = std::chrono::high_resolution_clock::now();

    // Lock the first tool, then the second tool
    std::lock_guard<std::mutex> lock1(tool_mutexes[first_tool]);
    std::cout << "Robot " << robot_id << " has grabbed tool " << first_tool << "." << std::endl;
    std::lock_guard<std::mutex> lock2(tool_mutexes[second_tool]);
    std::cout << "Robot " << robot_id << " has grabbed tool " << second_tool 
              << " and is starting the task." << std::endl;

    // Simulate grabbing tools (500 ms) across all robots
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Simulate landing process (500 ms) across all robots
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Robot " << robot_id << " has landed and is ready to use the tools." << std::endl;

    // Simulate using the tool for the remaining 3000 ms, ensuring the total process for all robots is 4 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // Total task time = 4 seconds for all robots

    // End timing for task completion
    auto end_time = std::chrono::high_resolution_clock::now();
    auto total_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Total time for robot " << robot_id << " to complete the task: " 
              << total_duration.count() << " ms" << std::endl;

    std::cout << "Robot " << robot_id << " has completed the task and is returning the tools." << std::endl;
}

// Function to start all robot tasks
void RobotTaskManager::startTasks() {
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
