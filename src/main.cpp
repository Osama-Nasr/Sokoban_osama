#define _USE_MATH_DEFINES

#include "Game.h"
#include <stdlib.h>
#include <time.h>

int t1, t2;
double delta, distance, worldTime;

extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char** argv) {

	Game game;
	game.start();

	return 0;
};
