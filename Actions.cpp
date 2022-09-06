#include "Actions.h"

void Actions::takeActionForOption(SDL_Event event, bool& options, int& activeOption, int& level, int& quit, bool& sequentail)
{
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_KEYDOWN:		
			if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
			
			else if (event.key.keysym.sym == SDLK_o)
				options = (options + 1) % 2;

			else if (event.key.keysym.sym == SDLK_UP)
			{
				switch (activeOption) {
				case 0:
					if(++level > game::total_levels) 
						level -= 1;
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					sequentail = (sequentail + 1) % 2;
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				}
			}
			else if (event.key.keysym.sym == SDLK_DOWN)
			{
				switch (activeOption) {
				case 0:
					if(--level <= 0)
					level += 1;
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					sequentail = (sequentail + 1) % 2;
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				}
			}
			else if (event.key.keysym.sym == SDLK_1)
			{
				activeOption = 0;
			}
			else if (event.key.keysym.sym == SDLK_2)
			{
				activeOption = 1;
			}
			else if (event.key.keysym.sym == SDLK_3)
			{
				activeOption = 2;
			}
			else if (event.key.keysym.sym == SDLK_4)
			{
				activeOption = 3;
			}
			else if (event.key.keysym.sym == SDLK_5)
			{
				activeOption = 4;
			}
			else if (event.key.keysym.sym == SDLK_6)
			{
				activeOption = 5;
			}
			else if (event.key.keysym.sym == SDLK_7)
			{
				activeOption = 6;
			}
			else if (event.key.keysym.sym == SDLK_8)
			{
				activeOption = 7;
			}
			break;
		case SDL_KEYUP:
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		};
	}
}

void Actions::takeActionStartingMenu(SDL_Event event, int& quit, bool& options, bool& mMenu, Time& time)
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_o:
				options = (options + 1) % 2;
				break;
			case SDLK_s:
				mMenu = 0;
				time.setWorldTime(0.0);
				break;
			case SDLK_ESCAPE:
				quit = 1;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		};
	};
}

void Actions::takeActionsContinueMenu(SDL_Event event, Level& level, Time& time, int& quit, bool& mMenu, bool& mContinueMenu,
	int& points, int& lvl, SDL_Renderer* renderer, bool& mNewGameFlage, LinkedList *&results)
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_p:		//to the play the next level
				lvl = (lvl + 1) % (game::total_levels + 1);		//the purpose of the 1 is to make the ciercal of the incearse and to make it go to the last number as well
				if (lvl == 0)
					lvl = 1;

				mContinueMenu = 0;

				level.clearMap();
				level.PlaySpeacificLevel(lvl, renderer);
				time.setWorldTime(0.0);
				level.saved = false;
				level.moves = 0;
				level.finishTime = 0.0;
				mNewGameFlage = true;

				break;
			case SDLK_m:		///going to the back to the menu

				mMenu = 1;
				mContinueMenu = 0;

				level.clearMap();
				level.setMapInit(false);
				time.setWorldTime(0.0);
				level.saved = false;
				level.moves = 0;
				level.finishTime = 0.0;
				mNewGameFlage = true;
				break;
			case SDLK_s:
				if (level.saved == false) 
				{
					bool tempCF = results[lvl + (lvl - 1)].getChangedFirst();

					if (tempCF == false)
					{
						results[lvl + (lvl - 1)].changeFirst(level.moves, time.getWorldTime(), lvl);
						results[lvl * 2].changeFirst(level.moves, time.getWorldTime(), lvl);
					}
					else 
					{
						results[lvl + (lvl - 1)].Insert(POSITION_BEG, level.moves, time.getWorldTime(), lvl);
						results[lvl * 2].Insert(POSITION_BEG, level.moves, time.getWorldTime(), lvl);
					}
					
					//write the result to the file of results
					results[0].writeToFile(lvl, level.moves, time.getWorldTime());			//this is empty and i will just use it for the writing perpose
				
					level.saved = true;
				}
				break;
			case SDLK_ESCAPE:
				quit = 1;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		};
		//SDL_Delay(20);
	};
}

void Actions::takePlayerActions(SDL_Event event, int& quit, Level &level, int lvl, SDL_Renderer* renderer)
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				if (level.checkMove(direction::UP)) 
					level.movePlayer(direction::UP, renderer);
				level.moves++;

				break;
			case SDLK_DOWN:
				if (level.checkMove(direction::DOWN)) 
					level.movePlayer(direction::DOWN, renderer);
				level.moves++;
				break;
			case SDLK_RIGHT:
				if (level.checkMove(direction::RIGHT)) 
					level.movePlayer(direction::RIGHT, renderer);
				level.moves++;
				break;
			case SDLK_LEFT:
				if (level.checkMove(direction::LEFT)) 
					level.movePlayer(direction::LEFT, renderer);
				level.moves++;
				break;
			case SDLK_n:
				level.clearMap();
				level.PlaySpeacificLevel(lvl, renderer);
				
				break;
			case SDLK_SPACE:
				//player.shoot();
				break;
			case SDLK_ESCAPE:
				quit = 1;
			default:
				break;
			}
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		};
		//SDL_Delay(20);
	};
}

Actions::Actions()
{
}

Actions::~Actions()
{
}