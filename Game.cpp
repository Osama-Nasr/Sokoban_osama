#include "Game.h"

Game::Game()
{
	 eti = SDL_LoadBMP("image/eti.bmp");
	 if (eti == NULL) {
		 printf("SDL_LoadBMP(eti.bmp) error: %s\n", SDL_GetError());
		 SDL_Quit();
	 };

	 rc = SDL_CreateWindowAndRenderer(game::SCREEN_WIDTH, game::SCREEN_HEIGHT, 0,
		&window, &renderer);

	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, game::SCREEN_WIDTH, game::SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, "Sokoban");

	screen = SDL_CreateRGBSurface(0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, 32,
		0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, game::SCREEN_WIDTH, game::SCREEN_HEIGHT);
	
	level = Level(renderer);
	text = Draw();
	action = Actions();
	time = Time();

	time.setT1(SDL_GetTicks());
}

Game::~Game()
{
	//// delete enemies;
	//for (int i = 0; i < numberOfenemies; i++)
	//{
	//	delete enemies[i];
	//}
	//delete bonuses;
	//cout << "~game" << endl;

	for(int j = 0; j < board::ySize; j++)
	{
		for(int i = 0; i < board::xSize; i++){
			level.map[j][i].~Item();
		}
	}

	for (int i = 0; i < board::ySize; i++)
	{
		delete[] level.map[i];
	}
	delete[] level.map;

	ItemQuit();
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

}


void Game::start()
{
	while (!quit) {

		menu();
		game();
		continueMenu();
	}
} 

void Game::menu()
{
	while (mMenu && !quit)
	{
		text.TextStartingMenu(screen, eti);

		while (options && !quit)
		{
			text.TextOptions(screen, eti, enemyShootEverySEC, activeOption, /*player,*/ lvl, sequentail);
			action.takeActionForOption(event, /*player,*/ options,activeOption, enemyShootEverySEC, lvl, quit, sequentail);
			updatingScreen();
		}

		action.takeActionStartingMenu(event, quit, options, mMenu, this->time);
		updatingScreen();		
	}
}

void Game::game()
{
	//game
	while (!mMenu && !quit && !mContinueMenu) {

		
		time.setT2(SDL_GetTicks());
		// here t2-t1 is the time in milliseconds since
		// the last screen was drawn
		// delta is the same time in seconds
		
		time.setDelta((time.getT2() - time.getT1()) * 0.001);
		time.setT1(time.getT2());//430 / 6 / fps

		time.setWorldTime(time.getWorldTime() + time.getDelta());

		//time distance += etiSpeed * delta;

		int black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
		SDL_FillRect(screen, NULL, black);

		time.setFpsTimer(time.getFpsTimer() + time.getDelta());

		if (time.getFpsTimer() > 0.5) {
			time.setFps(time.getFrames() * 2);
			time.setFrames(0);
			time.setFpsTimer(time.getFpsTimer() - 0.5 );
		};

		text.TextGame(screen, time.getWorldTime(), time.getFps(), numberOfHits, numberOfgettingShooted, points);

		updatingScreen();
	
		action.takePlayerActions(event, quit, level, this->lvl, renderer);
		
		if (sequentail == true)
			level.playSeqaunceLevels();
		else
			if (level.getMapInit() == false)
				level.PlaySpeacificLevel(lvl, renderer);

		level.drawMap();

		mContinueMenu = level.checkWin();
		SDL_RenderPresent(renderer);
		SDL_Delay(25);
		//level.drawTest();
		/*level.levelMode(&player, &bar, renderer, lvl, startCountingTimeForRehealing,
			rehealingTime, time.getWorldTime(), enemies, bonuses, mContinueMenu,
			bonusesTime, shootTime, enemyShootEverySEC, numberOfgettingShooted, numberOfHits, points);*/

	}
}

void Game::continueMenu()
{
	//text.winMessage(screen);
	text.TextContinueMenu(screen, eti, points);
	action.takeActionsContinueMenu(event, this->level, this->time, quit, mMenu, mContinueMenu, points, lvl, renderer);

	updatingScreen();
}

void Game::updatingScreen()
{
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	//		SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

