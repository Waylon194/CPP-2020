#pragma once
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

class StopWatch
{
public:
    void start();
    void stop();
    duration<double> getElapsedTime();
private:
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point endTime;
};