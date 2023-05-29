#pragma once
#include <iostream>
#include "Level.h"
#include "Time.h"
#include "LinkedList.h"
#define position_beging 0

using namespace std;

extern "C" {
#include"SDL2-2.0.10/include/SDL.h"
#include"SDL2-2.0.10/include/SDL_main.h"
}

class Actions
{
public:
	void takeActionForOption(SDL_Event event, bool& options, int& activeOption, int& level, int& quit, int& showResultsLvl);
	void takeActionStartingMenu(SDL_Event event, int& quit, bool& options, bool& mMenu, Time& time);
	void takePlayerActions(SDL_Event event, int& quit, Level &level, int lvl, SDL_Renderer* renderer);
	void takeActionsContinueMenu(SDL_Event event, Level& level, Time& time, int& quit, bool& mMenu, bool& mContinueMenu, int& lvl, SDL_Renderer* renderer, bool& mNewGameFlage, LinkedList*& results);

	Actions();
	~Actions();
};
