#pragma once
#include <vector>
#include "Keyboard.h"
#include "Location.h"
#include "Board.h"
#include "Sound.h"
class Snake
{
public:
	Snake(Board& brd);
	void GenSnake();
	void Update(class Food& apple, class Poison& poison, Sound& SoundFX);
	void Manage(Keyboard& kbd);
	void DrawSnake(Graphics& gfx);
	bool CheckGameOver(class Border& bounds, class Poison& poison);
	Location GetCurrentPos();
	~Snake();
public:
	std::vector<Location> SnakePos;
private:
	enum direction {up,right,down,left};
	direction SnakeDir;
	Board& brd;
	int GrowthCounter = 0;
};

