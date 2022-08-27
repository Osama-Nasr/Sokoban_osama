#pragma once

extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}

class Time
{
private:
	int t1, t2;
	int frames = 0;
	double fps = 0, fpsTimer = 0;
	double delta, distance = 0, worldTime = 0;

public:
	int getT1();
	int getT2();
	int getFrames();
	double getFps();
	double getFpsTimer();
	double getDelta();
	double getDistance();
	double getWorldTime();

	void setT1(int t);
	void setT2(int t);
	void setFrames(int t);
	void setFps(double t);
	void setFpsTimer(double t);
	void setDelta(double t);
	void setDistance(double t);
	void setWorldTime(double t);
};



