#include "q2.h"

RobotTaskManager::RobotTaskManager() {}

void RobotTaskManager::performTask(int robot_id) {
    int left_tool = robot_id;
    int right_tool = (robot_id + 1) % 5;

    while (true) {
        auto start_time = std::chrono::high_resolution_clock::now();

        // Attempt to grab the tools
        std::cout << "Robot " << robot_id << " is reaching and grabbing the tools." << std::endl;

        // Lock the tools using to avoid deadlocks
        std::lock(tool_mutexes[left_tool], tool_mutexes[right_tool]);
        std::lock_guard<std::mutex> lock1(tool_mutexes[left_tool], std::adopt_lock);
        std::lock_guard<std::mutex> lock2(tool_mutexes[right_tool], std::adopt_lock);

        // Once robot has grabbed both tools it starts performing the task
        std::cout << "Robot " << robot_id << " has grabbed the tools and is starting the task." << std::endl;

        // Simulates grabbing tools (500 ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Simulate landing process (500 ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Simulate using the tools (1000 ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Return the tools
        std::cout << "Robot " << robot_id << " has completed the task and is returning the tools." << std::endl;

        // Simulate some delay before attempting the task again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Function to start all robot tasks
void RobotTaskManager::startTasks() {
    // Output the times each robot has to perform tasks
    std::cout << "Time grabbing tool: 500 ms" << std::endl;
    std::cout << "Time landing process: 500 ms" << std::endl;
    std::cout << "Time using tool: 1000 ms" << std::endl;

    // Create threads for each robot
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(&RobotTaskManager::performTask, this, i);
    }

    // Wait for all threads to complete
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    std::cout << "All robots have completed their tasks." << std::endl;
}