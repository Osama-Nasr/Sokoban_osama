#pragma once
#include <time.h>
#include "Item.h"
#include "Constants.h"
#include "fstream"
#include <iostream>
#include <string>
using namespace std;

extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}

class Item;

class Level {
public:

	Level(SDL_Renderer* renderer);
	Level();
	~Level();
	void manualDestructor();

	void PlaySpeacificLevel(int lvlNo, SDL_Renderer* renderer);
	void clearMap();
	void drawMap();
	bool checkMove(int moveDirection);
	void movePlayer(int moveDirection, SDL_Renderer* renderer);
	void swapObjects(Item& old, Item& mNew);	//https://www.geeksforgeeks.org/passing-reference-to-a-pointer-in-c/
	void show();
	void updatingPositions(int xNewPosition, int yNewPosition, char playerOrBox);			//this is for the changing the like position and image after swaping them
	bool checkWin();

	void setMapInit(bool mapInit);
	bool getMapInit();
	
	int moves = 0;
	double finishTime = 0.0;
	bool saved = false;

	Item** map;
	Item* goal[game::MAX_GOALS];
	int goalsNumber = 0;
private:
	Item *player;
	int j, i;
	bool mapInit = false;


};