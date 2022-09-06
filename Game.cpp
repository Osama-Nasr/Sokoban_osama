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
	results = new LinkedList[game::total_levels * 2 + 1];		//mutible by two so that the array will be like this rs = {[lvl1.moves],[lvl1.FT],[lvl2.moeves],[lvl2.FT],..}and the first place will be empty
	for (int i = 0; i < game::total_levels * 2 + 1; i++)
	{
		results[i] = LinkedList();
	}
	//results[1].setNumberOfInsertions(4);  this is working
	readingFromFileForResults();
	for (int i = 0; i < game::total_levels * 2 + 1; i++)
	{
		cout << i << " ";
		results[i].Display();
		cout << endl;
	}

	time.setT1(SDL_GetTicks());
}

Game::~Game()
{
	//// delete enemies;
	//for (int i = 0; i < numberOfenemies; i++)
	//{
	//	delete enemies[i];x
	//}
	//delete bonuses;
	cout << "~game" << endl;

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
	 
	this->level.~Level();
	this->text.~Draw();
	this->results->clear();

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
			text.TextOptions(screen, eti, activeOption, lvl, sequentail);
			action.takeActionForOption(event, options, activeOption, lvl, quit, sequentail);
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
		if (newGameFlage == true)		//this if statment is to rest the delta becuase it will be running so for that
		{
			time.setDelta(0.0);
			newGameFlage = false;
		}
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

		text.TextGame(screen, time.getWorldTime(), time.getFps(), level.moves);

		updatingScreen();
	
		action.takePlayerActions(event, quit, level, this->lvl, renderer);
		
		if (sequentail == true)
			level.playSeqaunceLevels();
		else
			if (level.getMapInit() == false)
				level.PlaySpeacificLevel(lvl, renderer);

		level.drawMap();

		if (level.checkWin()) {
			mContinueMenu = true;
			level.finishTime = time.getWorldTime();
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(25);
		//level.drawTest();
		/*level.levelMode(&player, &bar, renderer, lvl, startCountingTimeForRehealing,
			rehealingTime, time.getWorldTime(), enemies, bonuses, mContinueMenu,
			bonusesTime, shootTime, enemyShootEverySEC, numberOfgettingShooted, numberOfHits, points);*/
		time.setFrames(time.getFrames() + 1);
	}
}

void Game::continueMenu()
{
	//text.winMessage(screen);
	text.TextContinueMenu(screen, eti, level);
	for (int i = 0; i < game::total_levels * 2 + 1; i++)
	{
		cout << i << " ";
		results[i].Display();
		cout << endl;
	}
	action.takeActionsContinueMenu(event, this->level, this->time, quit, mMenu, mContinueMenu, points, lvl, renderer, newGameFlage, results);
	updatingScreen();
}

void Game::updatingScreen()
{
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	//		SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Game::readingFromFileForResults()
{
	ifstream rs;
	int lvl = 0;
	long long int moves = 0;
	long double FT = 0.0;
	rs.open("results/result.txt");
	if (rs.fail())
		cerr << "Error in opening a file";
	else {

		while (rs >> lvl >> moves >> FT)
		{
			if (results[lvl + (lvl - 1)].getChangedFirst() == false)
			{
				results[lvl + (lvl - 1)].changeFirst(moves, FT, lvl);
				results[lvl * 2].changeFirst(moves, FT, lvl);
			}
			else
			{
				results[lvl + (lvl - 1)].Insert(POSITION_BEG, moves, FT, lvl);		// for this formula check out my execl file in the notes dircetoy we will ignore the first space
				results[lvl * 2].Insert(POSITION_BEG, moves, FT, lvl);				
			}
		}
	}
}

