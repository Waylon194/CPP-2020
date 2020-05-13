#pragma once
#include <ctime>
#include <ratio>
#include <chrono>

class StopWatch
{
public:
    void start();
    void stop();
    long long getElapsedTime();
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
};