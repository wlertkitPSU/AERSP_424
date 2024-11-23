#ifndef Q3_H
#define Q3_H

#pragma once

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <vector>




void aircraft(int id, std::mutex& mtx, std::queue<int>& trafficPattern, std::condition_variable& cv, std::atomic<bool>& atc_quit, int MAX_TRAFFIC_PATTERN);

void airTrafficController(std::mutex& mtx, std::queue<int>& trafficPattern, std::condition_variable& cv, std::atomic<bool>& atc_quit, int MAX_TRAFFIC_PATTERN);

#endif