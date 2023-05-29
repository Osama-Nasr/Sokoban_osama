#include "Item.h"

Item::Item(SDL_Renderer* renderer, char const type, bool canMove, int i, int j, bool walkAbove)
{
	setCanMove(canMove);
	setType(type);
	setRenderer(renderer);
	setImage(NULL);
	setWalkAbove(walkAbove);
	
	if (type == board::GOAL)
		loadImage("image/goal.bmp");
	else if (type == board::WALL)
		loadImage("image/wall.bmp");
	else if (type == board::PLAYER)
		loadImage("image/player.bmp");
	else if (type == board::BOX)
		loadImage("image/box.bmp");
	else if (type == board::EMPTY)
		loadImage("image/tile.bmp");

	setSize(game::item_size_width, game::item_size_high);
	setPos( i, j);
	setPosOnScreen( i, j);	
}

Item::Item()
{
	//cout << "Item() ";
	setType(board::EMPTY);
	setCanMove(false);
	setPos(-1, -1);
	setSize(0, 0);
	setImage(NULL);
	setWalkAbove(true);
}

Item::~Item()
{
	/*if (image != NULL) {
		SDL_DestroyTexture(image);	
		image = NULL;
	}*/
}

void Item::manualDestructor()
{
	if (image != NULL) {
		SDL_DestroyTexture(image);
		image = NULL;
	}
}

void ItemInit() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//IMG_Init(IMG_INIT_BMP);
}

void ItemQuit() 
{
	SDL_Quit;
}

void Item::setRenderer(SDL_Renderer *dest)
{
	ren = dest;
}

bool Item::loadImage(char filename[])
{
	if (image != NULL) 
	{
		SDL_DestroyTexture(image);
		image = NULL;
	}
	SDL_Surface* temp = SDL_LoadBMP(filename);
	if (temp != NULL)
	{
		image = SDL_CreateTextureFromSurface(ren, temp);
		SDL_FreeSurface(temp);
		if (image != NULL)
			return true;
	}
	cout << "problem in loading picture " << filename << endl;
	return false;
}

void Item::setSize(int w, int h)
{
	posOnScreen.w = w;
	posOnScreen.h = h;
}

void Item::setPos(int x, int y)
{
	if (x >= 0 && y>=0) {
		pos.x = x;
		pos.y = y;
	}
}

void Item::setPosOnScreen(int x, int y)
{
	if (x >= 0 && y >= 0) {
		posOnScreen.x = (x + 1) * game::item_size_width;		// the plus one is for the sake of starting from one
		posOnScreen.y = (y + 1) * game::item_size_high;
	}
}

void Item::setCanMove(bool canMove)
{
	this->canMove = canMove;
}

void Item::setType(char type)
{
	this->type = type;
}

void Item::setImage(SDL_Texture* im)
{
	image = im;
}

bool Item::getCanMove()
{
	return canMove;
}

char Item::getType()
{
	return type;
}

bool Item::getWalkAbove()
{
	return walkAbove;
}

SDL_Texture* Item::getImage()
{
	return image;
}

void Item::setWalkAbove(bool walkAbove)
{
	this->walkAbove = walkAbove;
}

void Item::draw()
 {
	if (image != NULL)
	{
		SDL_RenderCopy(ren, image, NULL, &posOnScreen);
	}
}

SDL_Rect* Item::getPos()
{
	return &pos;
}

SDL_Rect* Item::getPosOnScreen()
{
	return &posOnScreen;
}

bool Item::possibleToMove()
{
	return false;
}

