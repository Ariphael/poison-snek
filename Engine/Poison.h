#pragma once
#include "Location.h"
#include "Board.h"
#include "Colors.h"
#include <random>
class Poison
{
public:
	Poison(Board& brd);
	void GenPoison(class Snake& snek, class Food& apple);
	void DrawPoison(Graphics& gfx);
	bool GetIndex(int x, int y);
	int PoisonCount(); //debugging
	~Poison();
private:
	bool PoisonPos[79 * 59] = { false };
	Location AllocPos;
	Color c = Colors::Gray;
	Board& brd;
	std::mt19937 RanEngine;
	std::uniform_int_distribution<int> LocDist;
};

