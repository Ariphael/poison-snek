#include "Snake.h"
#include "Border.h"
#include "Food.h"
#include "Poison.h"
#include "Border.h"
#include <iostream>


Snake::Snake(Board& brd)
	:
	SnakeDir(direction::right),
	brd(brd)
{
}

void Snake::GenSnake()
{
	SnakePos.push_back(Location(10, 10));
	SnakePos.push_back(Location(10, 11));
	SnakePos.push_back(Location(10, 12));
}

void Snake::Update(Food& apple, Poison& poison, Sound& SoundFX)
{
	if (SnakePos.size() == 0) {
		GenSnake();
	}
	if (apple.IsEaten(*this,poison)) {
		GrowthCounter = 5;
		SoundFX.Play();
	}
	switch (SnakeDir) {
	case direction::up:
		SnakePos.push_back(Location(SnakePos[SnakePos.size() - 1]._x, SnakePos[SnakePos.size() - 1]._y - 1));
		if (GrowthCounter == 0) {
			for (int i = 0; i < SnakePos.size() - 1; i++) {
				SnakePos[i] = SnakePos[i + 1];
			}
			SnakePos.pop_back();
		}
		else {
			GrowthCounter--;
		}
			break;
		case direction::right:
			SnakePos.push_back(Location(SnakePos[SnakePos.size() - 1]._x+1, SnakePos[SnakePos.size() - 1]._y));
			if (GrowthCounter == 0) {
				for (int i = 0; i < SnakePos.size() - 1; i++) {
					SnakePos[i] = SnakePos[i + 1];
				}
				SnakePos.pop_back();
			}
			else {
				GrowthCounter--;
			}
			break;
		case direction::down:
			SnakePos.push_back(Location(SnakePos[SnakePos.size() - 1]._x, SnakePos[SnakePos.size() - 1]._y+1));
			if (GrowthCounter == 0) {
				for (int i = 0; i < SnakePos.size() - 1; i++) {
					SnakePos[i] = SnakePos[i + 1];
				}
				SnakePos.pop_back();
			}
			else {
				GrowthCounter--;
			}
			break;
		case direction::left:
			SnakePos.push_back(Location(SnakePos[SnakePos.size() - 1]._x-1, SnakePos[SnakePos.size() - 1]._y));
			if (GrowthCounter == 0) {
				for (int i = 0; i < SnakePos.size() - 1; i++) {
					SnakePos[i] = SnakePos[i + 1];
				}
				SnakePos.pop_back();
			}
			else {
				GrowthCounter--;
			}
			break;
	}
}

void Snake::Manage(Keyboard & kbd)
{
	if (kbd.KeyIsPressed(0x26) && SnakeDir != direction::down) { // UP KEY EVENT
		SnakeDir = direction::up;
	}
	if (kbd.KeyIsPressed(0x27) && SnakeDir != direction::left) { // RIGHT KEY EVENT
		SnakeDir = direction::right;
	}
	if (kbd.KeyIsPressed(0x28) && SnakeDir != direction::up) { // DOWN KEY EVENT
		SnakeDir = direction::down;
	}
	if (kbd.KeyIsPressed(0x25)&& SnakeDir != direction::right) { // LEFT KEY EVENT
		SnakeDir = direction::left;
	}
}

void Snake::DrawSnake(Graphics& gfx)
{
	for (int i = 0; i < SnakePos.size(); i++){
		brd.DrawBox(SnakePos[i],gfx,Colors::Magenta);
	}

}

bool Snake::CheckGameOver(Border & bounds,Poison& poison)
{
	if (SnakePos.size() == 0) {
		GenSnake();
	}
	for (int i = 0; i < SnakePos.size()-1; i++) {
		if (SnakePos[SnakePos.size() - 1]._x == SnakePos[i]._x && SnakePos[SnakePos.size() - 1]._y == SnakePos[i]._y) {
			return true;
		}
	}
	if (poison.GetIndex((int)GetCurrentPos()._x, (int)GetCurrentPos()._y)) {
		return true;
	}
	if (SnakePos[SnakePos.size() - 1]._x > bounds.GetLoc()._x && SnakePos[SnakePos.size() - 1]._x < bounds.GetLoc()._x + bounds.GetWidth()) {
		if (SnakePos[SnakePos.size() - 1]._y > bounds.GetLoc()._y && SnakePos[SnakePos.size() - 1]._y < bounds.GetLoc()._y + bounds.GetHeight()) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}

Location Snake::GetCurrentPos()
{
	return SnakePos[SnakePos.size() - 1];
}


Snake::~Snake()
{
}
