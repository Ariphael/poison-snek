#include "Poison.h"
#include "Snake.h"
#include "Border.h"
#include "Food.h"
#include <iostream>


Poison::Poison(Board& brd)
	:
	AllocPos( Location(-1,-1) ),
	brd( brd ),
	LocDist(6, 54)
{
}

void Poison::GenPoison(Snake& snek, Food& apple)
{
	Allocate:
	AllocPos = Location((float)LocDist(RanEngine), (float)LocDist(RanEngine));
	for (int i = 0; i < snek.SnakePos.size(); i++){
		if (AllocPos._x == snek.SnakePos[i]._x && AllocPos._y == snek.SnakePos[i]._y) {
			goto Allocate;
		}
	}
	if (AllocPos._x == apple.GetLoc()._x && AllocPos._y == apple.GetLoc()._y) {
		goto Allocate;
	}
	if (PoisonCount() == 2) {
		std::cout << "debug" << std::endl;
	}
	PoisonPos[79 * (int)AllocPos._y + (int)AllocPos._x]=true;
	AllocPos = Location(-1,-1);
}

void Poison::DrawPoison(Graphics & gfx)
{
	for (int i = 0; i < 79 * 59; i++) {
		if (PoisonPos[i] == true) {
			brd.DrawBox(Location((float)-(79*floor(i/79)-i), (float)floor(i/79)), gfx, c);
		}
	}
}

bool Poison::GetIndex(int x, int y)
{
	if (PoisonPos[79 * y + x] == true) {
		return true;
	}
	else {
		return false;
	}
}

int Poison::PoisonCount()
{
	int n = 0;
	for (int i = 0; i < 79 * 59; i++) {
		if (PoisonPos[i] == true) {
			n++;
		}
	}
	return n;
}


Poison::~Poison()
{
}
