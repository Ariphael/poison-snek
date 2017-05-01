#include "Food.h"
#include "Snake.h"
#include "Poison.h"

Food::Food(Board& brd)
	:
	brd(brd),
	FoodLoc(Location(-1,-1)),
	range(6,54)
{
}

void Food::GenFood(Poison& poison)
{
	FoodLoc_Define:
	FoodLoc = Location((float)range(rand), (float)range(rand));
	if (poison.GetIndex(FoodLoc._x, FoodLoc._y)) {
		goto FoodLoc_Define;
	}
}

void Food::DrawFood(Graphics& gfx,Poison &poison)
{
	if (FoodLoc._x < 0 || FoodLoc._y < 0) {
		GenFood(poison);
	}
	brd.DrawBox(FoodLoc, gfx, Colors::Red);
}

bool Food::IsEaten(Snake& snek,Poison& poison)
{
	if (snek.GetCurrentPos()._x == FoodLoc._x && snek.GetCurrentPos()._y == FoodLoc._y) {
		GenFood(poison);
		return true;
	}
	else {
		return false;
	}
}

Location& Food::GetLoc()
{
	return FoodLoc;
}

Food::~Food()
{
}
