#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Colors.h"
#include "MainWindow.h"
class Board
{
public:
	Board()=default;
	Board(int BDO);
	void DrawBox(Location& BoxLoc, Graphics& gfx, Color c)const;
	void DrawGameOver(int x, int y, Graphics& gfx)const;
	~Board();
private:
	int _BoxDimensionOffset;
};

