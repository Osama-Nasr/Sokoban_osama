#pragma once
#include<stdio.h>
#include<string.h>
#include <string>
#include "Constants.h"
#include <fstream>
#include "Level.h"
#include "LinkedList.h"

using namespace std;
extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}

class Draw {
private:
	SDL_Surface* charset;
public:
	Draw();
	~Draw();
	void manualDestructor();

	char text[128];
	void TextStartingMenu(SDL_Surface* screen, SDL_Surface* eti);
	void TextOptions(SDL_Surface *screen, SDL_Surface* eti, int activeOption, int level, int showResultsLvl, LinkedList* results);
	void TextGame(SDL_Surface* screen, double worldTime, double fps, int moves);
	void winMessage(SDL_Surface* screen);
	void TextContinueMenu(SDL_Surface* screen, SDL_Surface* eti, Level level);

	void DrawString(SDL_Surface* screen, int x, int y, const char* text);
	void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color);
	void DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color);
	void DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k,
		Uint32 OUTlineColor, Uint32 fillColor);

};