#include "StopWatch.h"
void StopWatch::start()
{
    startTime = high_resolution_clock::now();
}

void StopWatch::stop()
{
    endTime = high_resolution_clock::now();
}

duration<double> StopWatch::getElapsedTime()
{
    return duration_cast<duration<double>>(endTime - startTime);
}