#include "Actions.h"

void Actions::takeActionForOption(SDL_Event event,/* Player& player,*/ bool options, int activeOption,
	double& enemyShootEverySEC, int& level, int& quit, bool& sequentail)
{
	while (SDL_PollEvent(&event)) {

		cout << "taking actions" << endl;
		cout << activeOption << endl;

		switch (event.type) {
		case SDL_KEYDOWN:		
			if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
			
			else if (event.key.keysym.sym == SDLK_o)
				options = (options + 1) % 2;

			else if (event.key.keysym.sym == SDLK_UP)
			{
				switch (activeOption) {
				case 0:
					/*player.increaseSpeedX_left();
					player.increaseSpeedX_right();
					player.increaseSpeedY_down();
					player.increaseSpeedY_up();*/
					break;
				case 1:
					enemyShootEverySEC += 0.5;
					break;
				case 2:
					level += 1;
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

					/*player.decreaseSpeedX_left();
					player.decreaseSpeedX_right();
					player.decreaseSpeedY_down();
					player.decreaseSpeedY_up();*/
					break;
				case 1:
					enemyShootEverySEC -= 0.5;
					break;
				case 2:
					level -= 1;
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
			    cout <<"setiing activeOption 2works" << endl;
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

void Actions::takeActionsContinueMenu(SDL_Event event, Level& level, Time& time, int& quit, bool& mMenu, bool& mContinueMenu, int& points, int& lvl, SDL_Renderer* renderer)
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_p:
				lvl = (lvl + 1) % (game::total_levels + 1);		//the purpose of the 1 is to make the ciercal of the incearse and to make it go to the last number as well
				if (lvl == 0)
					lvl = 1;
				mContinueMenu = 0;
				time.setWorldTime(0.0);
				level.clearMap();
				level.PlaySpeacificLevel(lvl, renderer);

				break;
			case SDLK_m:
				mMenu = 1;
				mContinueMenu = 0;
				level.clearMap();
				level.setMapInit(false);

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
	//while (SDL_PollEvent(&event)) {
	//	switch (event.type) {
	//	case SDL_KEYDOWN:
	//		switch (event.key.keysym.sym) {
	//		case SDLK_ESCAPE: {
	//			quit = 1;
	//		}
	//			break;
	//		case SDLK_p:

	//		if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
	//		/*else if (event.key.keysym.sym == SDLK_d)
	//		{
	//			movementMode = (movementMode + 1) % 2;
	//		}*/
	//		else if (event.key.keysym.sym == SDLK_n)
	//		{
	//			mMenu = 1;
	//			mContinueMenu = 0;
	//			numberOfHits = 0;
	//			numberOfgettingShooted = 0;
	//			//player.blood = 1.0f;
	//			points = 0;
	//			//player.setPos(320, 370);
	//			/*for (int i = 0; i < numberOfenemies; i++)
	//			{
	//				enemies[i]->blood = 1.0f;
	//				enemies[i]->setLife(true);
	//			}*/
	//		}
	//		else if (event.key.keysym.sym == SDLK_c)
	//		{
	//			//player.setPos(320, 370);
	//			mContinueMenu = 0;
	//			points = 0;
	//		//	player.blood = 1.0f;
	//			/*for (int i = 0; i < numberOfenemies; i++)
	//			{
	//				enemies[i]->blood = 1.0f;
	//				enemies[i]->setLife(true);
	//			}*/
	//		}
	//		else if (event.key.keysym.sym == SDLK_1)
	//		{
	//			//player.setPos(320, 370);
	//			mContinueMenu = 0;
	//			points = 0;
	//			//player.blood = 1.0f;
	//			lvl = 0;
	//			/*for (int i = 0; i < numberOfenemies; i++)
	//			{
	//				enemies[i]->blood = 1.0f;
	//				enemies[i]->setLife(true);
	//			}*/
	//		}
	//		else if (event.key.keysym.sym == SDLK_2)
	//		{
	//			//player.setPos(320, 370);
	//			mContinueMenu = 0;
	//			points = 0;
	//			//player.blood = 1.0f;
	//			lvl = 1;
	//			/*for (int i = 0; i < numberOfenemies; i++)
	//			{
	//				enemies[i]->blood = 1.0f;
	//				enemies[i]->setLife(true);
	//			}*/
	//		}
	//		else if (event.key.keysym.sym == SDLK_3)
	//		{
	//			//player.setPos(320, 370);
	//			mContinueMenu = 0;
	//			points = 0;
	//			//player.blood = 1.0f;
	//			lvl = 2;
	//			/*for (int i = 0; i < numberOfenemies; i++)
	//			{
	//				enemies[i]->blood = 1.0f;
	//				enemies[i]->setLife(true);
	//			}*/
	//		}
	//		else if (event.key.keysym.sym == SDLK_4)
	//		{
	//			//player.setPos(320, 370);
	//			mContinueMenu = 0;
	//			points = 0;
	//			//player.blood = 1.0f;
	//			lvl = 3;
	//			/*for (int i = 0; i < numberOfenemies; i++)
	//			{
	//				enemies[i]->blood = 1.0f;
	//				enemies[i]->setLife(true);
	//			}*/
	//		}

	//	}
	//		break;
	//	case SDL_KEYUP:
	//		//etiSpeed = 1.0;
	//		break;
	//	case SDL_QUIT:
	//		quit = 1;
	//		break;
	//	};
	//};
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
		
				break;
			case SDLK_DOWN:
				if (level.checkMove(direction::DOWN)) 
					level.movePlayer(direction::DOWN, renderer);
	
				break;
			case SDLK_RIGHT:
				if (level.checkMove(direction::RIGHT)) 
					level.movePlayer(direction::RIGHT, renderer);

				break;
			case SDLK_LEFT:
				if (level.checkMove(direction::LEFT)) 
					level.movePlayer(direction::LEFT, renderer);

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