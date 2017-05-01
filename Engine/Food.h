#pragma once
#include "Location.h"
#include "Board.h"
#include <random>
class Food
{
public:
	Food()=default;
	Food(Board& brd);
	void GenFood(class Poison& poison);
	void DrawFood(Graphics& gfx, class Poison& poison);
	bool IsEaten(class Snake& snek, class Poison& poison);
	Location& GetLoc();
	~Food();
private:
	Location FoodLoc;
	Board& brd;
	std::mt19937 rand;
	std::uniform_int_distribution<int> range;
};

