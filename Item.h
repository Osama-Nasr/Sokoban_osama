#pragma once
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include "Level.h"

extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}

void ItemInit();
void ItemQuit();

class Item
{
public:
	Item(SDL_Renderer* renderer, char const type, bool canMove, int i, int j, bool walkAbove);
 	Item();
	~Item();
	void manualDestructor();
	//virtual Item();

	void setRenderer(SDL_Renderer *renderer);
	bool loadImage(char filename[]);
	void setSize(int w, int h);
	void setPos(int x, int y); 
	void setPosOnScreen(int x, int y); 
	void setCanMove(bool canMove);
	void setType(char type);
	void setImage(SDL_Texture* im);
	void setWalkAbove(bool walkAbove);
	bool getCanMove();
	char getType();
	bool getWalkAbove();
	SDL_Texture* getImage();
	SDL_Rect* getPos();
	SDL_Rect* getPosOnScreen();

	void draw();
	bool possibleToMove();
protected:

	bool canMove;
	bool walkAbove;
	char type;

	SDL_Texture* image;
	SDL_Rect posOnScreen;
	SDL_Rect pos;
	SDL_Renderer* ren;

private:
	
}; 

	