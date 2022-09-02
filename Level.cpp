#include "Level.h"


Level::Level(SDL_Renderer* renderer)
{
	//cout << endl << "level(SDL_Renderer* renderer)" << endl;
	i = board::xSize;  //column
	j = board::ySize;  //row

	map = new Item* [this->j]();
	for (int z = 0; z < this->j; z++)
		map[z] = new Item[this->i]();

	player = new Item();
	//test = Item(3,renderer);
}

Level::Level()
{
	//cout << "Level()" << endl;
	i = board::xSize;  //column
	j = board::ySize;  //row

	map = new Item* [this->j]();
	for (int z = 0; z < this->j; z++)
		map[z] = new Item[this->i]();

	player = new Item();
}

Level::~Level()
{
	//cout << endl << "~Level" << endl;
	/*for (int j = 0; j < board::ySize; j++)
	{
		for (int i = 0; i < board::xSize; i++)
		{
			map[j][i].~Item();
		}
	}
	for (int i = 0; i < board::ySize; i++)
	{
		delete[] map[i];
	}
	delete[] map;*/
}

/*void Level::levelMode(Player* player, Bar* bar, SDL_Renderer* renderer, int level, bool& startCountingTimeForRehealing,
	double& rehealingTime, double worldTime, Enemy* enemies[], Bonuses* bonuses[], bool& continueMenu,
	double& bonusesTime, double& shootTime, double enemyShootEverySEC, int& numberOfgettingShooted, int& numberOfHits, int& points)
{
	player->move(player->getPlayerSpeedx(), player->getPlayerSpeedy());
	player->draw();
	player->bulletMove();
	bar->setSize(200 * player->blood, bar->getPos()->y / 12);
	bar->draw();
	bool allFalse = true;
	bool allTrue = true;

	SDL_RenderPresent(renderer);
	SDL_Delay(25);
}*/

void Level::initialize(int lvlNo)
{
}

void Level::PlaySpeacificLevel(int lvlNo, SDL_Renderer* renderer)
{
	ifstream file_reader;
	file_reader.open("Levels/lvl" + to_string(lvlNo) + ".txt");
	if (file_reader.fail()) {
		cout << "Error opening level # " << lvlNo << ". Check if file is corrupted\n";
	}

	char z;
	file_reader.get(z);
	if (z == '\n') 
		file_reader.get(z);

	for (int j = 0; j < this->j; j++) {
		if (z == '\n')
			file_reader.get(z);
		for (int i = 0; i < this->i; i++) {
			switch (z) {
			case board::WALL:
				map[j][i] = Item(renderer, board::WALL, false, i, j, false);
				break;
			case board::BOX: 
				map[j][i] = Item(renderer, board::BOX, true, i, j, false);
				break;
			case board::GOAL: 
				goal[goalsNumber] = new Item(renderer, board::GOAL, false, i, j, true);
				map[j][i] = Item(renderer, board::GOAL, false, i, j, true);
				goalsNumber++;
				break;
			case board::PLAYER: 
				map[j][i] = Item(renderer, board::PLAYER, true, i, j, false);
				player = new Item(renderer, board::PLAYER, true, i, j, false);
				break;
			case board::EMPTY: 
				map[j][i] = Item(renderer, board::EMPTY, false, i, j, true);
				break;
			//case '+': //Player on goal
			//	arr.at(i * y + j) = 6;
			//	break;
			//case board::OUT: //OUT
			//	map[j][i] = Item(board::OUT, false);
			//	break;
			}
			file_reader.get(z);
			if (z == '\n')
				file_reader.get(z);
		}
	}
	file_reader.close();
	mapInit = true;
}

void Level::playSeqaunceLevels()
{
}

void Level::clearMap()
{
	for (int z = 0; z < this->j; z++)
		for (int w = 0; w < this->i; w++)
			map[z][w] = Item();
	player = new Item();

	for (int i = 0; i < goalsNumber; i++)
		goal[i] = new Item();
	goalsNumber = 0;

}

void Level::drawMap()
{
	for (int j = 0; j < this->j; j++)
	{
		for (int i = 0; i < this->i; i++)
		{
			if (map[j][i].getType() != board::EMPTY && map[j][i].getType() != board::GOAL)
					map[j][i].draw();
		}
	}

	for (int i = 0; i < goalsNumber; i++)
	{
		goal[i]->draw();
	}
}

void Level::setMapInit(bool mapInit)
{
	this->mapInit = mapInit;
}

bool Level::getMapInit()
{
	return mapInit;
}

bool Level::checkMove(int moveDirection)
{	
	//those temp varibles are for the temperary new paramerters for the target possition to check if it's possible to move or not
	int xTemp = this->player->getPos()->x;
	int yTemp = this->player->getPos()->y;

	switch (moveDirection)
	{
	case direction::UP:
	{
		--yTemp;
		if (this->map[yTemp][xTemp].getType() == board::EMPTY || this->map[yTemp][xTemp].getType() == board::GOAL)
			return true;
		else if (this->map[yTemp][xTemp].getType() == board::WALL)
			return false;
		else if (this->map[yTemp][xTemp].getType() == board::BOX && this->map[yTemp - 1][xTemp].getWalkAbove() == true)
			return true;

		return false;
	}
		break;
	case direction::DOWN:
	{
		++yTemp;
		if (this->map[yTemp][xTemp].getType() == board::EMPTY || this->map[yTemp][xTemp].getType() == board::GOAL)
			return true;
		else if (this->map[yTemp][xTemp].getType() == board::WALL)
			return false;
		else if (this->map[yTemp][xTemp].getType() == board::BOX && this->map[yTemp + 1][xTemp].getWalkAbove() == true)
			return true;

		return false;
	}
		break;
	case direction::RIGHT:
	{	
		++xTemp;
		if (this->map[yTemp][xTemp].getType() == board::EMPTY || this->map[yTemp][xTemp].getType() == board::GOAL)
			return true;
		else if (this->map[yTemp][xTemp].getType() == board::WALL)
			return false;
		else if (this->map[yTemp][xTemp].getType() == board::BOX && this->map[yTemp][xTemp + 1].getWalkAbove() == true)
			return true;

		return false;
	}
		break;
	case direction::LEFT:
	{
		--xTemp;
		if (this->map[yTemp][xTemp].getType() == board::EMPTY || this->map[yTemp][xTemp].getType() == board::GOAL)
			return true;
		else if (this->map[yTemp][xTemp].getType() == board::WALL)
			return false;
		else if (this->map[yTemp][xTemp].getType() == board::BOX && this->map[yTemp][xTemp - 1].getWalkAbove() == true)
			return true;
		
		return false;
	}
		break;
	default:
		break;
	}

	
}

void Level::movePlayer(int moveDirection, SDL_Renderer* renderer)
{
	Item* tempPlace = nullptr;
	int xTempPlayerTarget;
	int yTempPlayerTarget;

	SDL_RenderPresent(renderer);
	switch (moveDirection)
	{
	case direction::UP:
	{
		xTempPlayerTarget = this->player->getPos()->x;
		yTempPlayerTarget = this->player->getPos()->y - 1;
		//show();
		//if there is a box infornt of the player we will move the box then we will move player
		if (map[yTempPlayerTarget][xTempPlayerTarget].getType() == board::BOX) {
			swapObjects(map[yTempPlayerTarget][xTempPlayerTarget], map[yTempPlayerTarget - 1][xTempPlayerTarget]);        //will swap the Item objects of the new position of the box with the old position 
			updatingPositions(xTempPlayerTarget, yTempPlayerTarget - 1, board::BOX);
		}
		swapObjects(map[this->player->getPos()->y][this->player->getPos()->x], map[yTempPlayerTarget][xTempPlayerTarget]);
		//show();
		//set the new parameters for player object
		updatingPositions(xTempPlayerTarget, yTempPlayerTarget, board::PLAYER);
	}
		break;
	case direction::DOWN:
	{
		xTempPlayerTarget = this->player->getPos()->x;
		yTempPlayerTarget = this->player->getPos()->y + 1;
		//show();

		//if there is a box infornt of the player we will move the box then we will move player
		if (map[yTempPlayerTarget][xTempPlayerTarget].getType() == board::BOX) {
			swapObjects(map[yTempPlayerTarget][xTempPlayerTarget], map[yTempPlayerTarget + 1][xTempPlayerTarget]);        //will swap the Item objects of the new position of the box with the old position 
			updatingPositions(xTempPlayerTarget, yTempPlayerTarget + 1, board::BOX);
		}

		//swapping the player only
		swapObjects(map[this->player->getPos()->y][this->player->getPos()->x], map[yTempPlayerTarget][xTempPlayerTarget]);
		//show();

		//set the new parameters for player object
		updatingPositions(xTempPlayerTarget, yTempPlayerTarget, board::PLAYER);
	}
		break;
	case direction::RIGHT:
	{
		xTempPlayerTarget = this->player->getPos()->x + 1;
		yTempPlayerTarget = this->player->getPos()->y;
		//show();
		//if there is a box infornt of the player we will move the box then we will move player
		if (map[yTempPlayerTarget][xTempPlayerTarget].getType() == board::BOX) {
			swapObjects(map[yTempPlayerTarget][xTempPlayerTarget], map[yTempPlayerTarget][xTempPlayerTarget + 1]);        //will swap the Item objects of the new position of the box with the old position 
			updatingPositions(xTempPlayerTarget + 1, yTempPlayerTarget, board::BOX);
		}
		swapObjects(map[this->player->getPos()->y][this->player->getPos()->x], map[yTempPlayerTarget][xTempPlayerTarget]);
		//show();

		//set the new parameters for player object
		updatingPositions(xTempPlayerTarget, yTempPlayerTarget, board::PLAYER);
	}
		break;
	case direction::LEFT:
	{
		xTempPlayerTarget = this->player->getPos()->x - 1;
		yTempPlayerTarget = this->player->getPos()->y;
		//show();
		//if there is a box infornt of the player we will move the box then we will move player
		if (map[yTempPlayerTarget][xTempPlayerTarget].getType() == board::BOX) {
			swapObjects(map[yTempPlayerTarget][xTempPlayerTarget], map[yTempPlayerTarget][xTempPlayerTarget - 1]);        //will swap the Item objects of the new position of the box with the old position 
			updatingPositions(xTempPlayerTarget - 1, yTempPlayerTarget, board::BOX);
		}
		swapObjects(map[this->player->getPos()->y][this->player->getPos()->x], map[yTempPlayerTarget][xTempPlayerTarget]);
		//show();
		//set the new parameters for player object
		updatingPositions(xTempPlayerTarget, yTempPlayerTarget, board::PLAYER);
	}
		break;
	default:
		break;
	}
}

void Level::updatingPositions(int xNewPosition, int yNewPosition, char playerOrBox) {
	if (playerOrBox == board::PLAYER)
	{
		player->setPos(xNewPosition, yNewPosition);
		player->setPosOnScreen(xNewPosition, yNewPosition);
		map[player->getPos()->y][player->getPos()->x].setPosOnScreen(xNewPosition, yNewPosition);
	}
	else if (playerOrBox == board::BOX)
	{
		map[yNewPosition][xNewPosition].setPosOnScreen(xNewPosition, yNewPosition);
	}
}

bool Level::checkWin()
{
	
	for (int i = 0; i < goalsNumber; i++)
	{
		if (map[goal[i]->getPos()->y][goal[i]->getPos()->x].getType() != board::BOX)
		{
			return false; //didn't win 
		}
	}
	return true;	//won
}

void Level::swapObjects(Item &old, Item &mNew)	//https://www.geeksforgeeks.org/passing-reference-to-a-pointer-in-c/
{
	Item temp = mNew;
	mNew = old;
	old = temp;
}

void Level::show()
{
	for (int j = 0; j < board::ySize; j++)
	{
		for (int i = 0; i< board::xSize; i++)
		{
			cout<<map[j][i].getType();
		}
		cout << endl;
	}

	for (int j = 0; j < board::ySize; j++)
	{
		for (int i = 0; i < board::xSize; i++)
		{
			if( j >= 2 && j <= 12 &&  i > 3 && i <=9 )
			cout << map[j][i].getPos()->y<< map[j][i].getType() <<map[j][i].getPos()->x<<" ";
		}
		cout << endl;
	}
}

