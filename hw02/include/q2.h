#ifndef q2_H
#define q2_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

class RobotTaskManager {
public:
    RobotTaskManager();
    void performTask(int robot_id);
    void startTasks();

private:
    std::mutex tool_mutexes[5];
};

#endif
