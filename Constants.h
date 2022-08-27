// Constants.h
#pragma once
#if !defined(MYLIB_CONSTANTS_H)

namespace game {
	const int SCREEN_HEIGHT = 500 + 36;
	const int SCREEN_WIDTH = 800;
	const int item_size_width = 50;
	const int item_size_high = 50;
	const int MAX_GOALS = 7;
};

namespace direction {
	const int UP = 1;
	const int DOWN = 2;
	const int RIGHT = 3;
	const int LEFT = 4;
};

namespace board {

	const int xSize = 14;	//those are the boarders size of the x in the .txt files in levels
	const int ySize = 9;	//those are the boarders size of the y in the .txt files in levels

	const char EMPTY = '*';
	const char WALL = '#';
	const char PLAYER = '?';
	const char BOX = '@';
	const char GOAL = '!';
};


#endif