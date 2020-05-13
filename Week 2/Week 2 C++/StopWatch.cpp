#include "StopWatch.h"
void StopWatch::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void StopWatch::stop()
{
    endTime = std::chrono::high_resolution_clock::now();
}

long long StopWatch::getElapsedTime()
{
    return std::chrono::duration_cast<std::chrono::seconds>>(endTime - startTime).count();
}