#ifndef q2_H
#define q2_H

#include <chrono>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>

class RobotTaskManager {
public:
    RobotTaskManager();
    void performTask(int robot_id);
    void startTasks();

private:
    std::mutex tool_mutexes[5];
};

#endif
