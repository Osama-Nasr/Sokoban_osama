#include "Time.h"

int Time::getT1()
{
    return t1;
}

int Time::getT2()
{
    return t2;
}

int Time::getFrames()
{
    return frames;
}

double Time::getFps()
{
    return fps;
}

double Time::getFpsTimer()
{
    return fpsTimer;
}

double Time::getDelta()
{
    return delta;
}

double Time::getDistance()
{
    return distance;
}

double Time::getWorldTime()
{
    return worldTime;
}

void Time::setT1(int t)
{
    t1 = t;
}

void Time::setT2(int t)
{
     t2 = t;
}

void Time::setFrames(int t)
{
    frames = t;
}

void Time::setFps(double t)
{
    fps = t;
}

void Time::setFpsTimer(double t)
{
    fpsTimer = t;
}

void Time::setDelta(double t)
{
    delta = t;
}

void Time::setDistance(double t)
{
    distance = t;
}

void Time::setWorldTime(double t)
{
    worldTime = t;
}
