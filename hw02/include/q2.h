#ifndef Q2_H
#define Q2_H

#pragma once

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

void robots(int id, std::mutex& ma, std::mutex& mb, std::mutex& m0);

#endif