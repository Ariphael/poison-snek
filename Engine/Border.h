#pragma once
#include "Board.h"
#include "Location.h"
#include "Graphics.h"
#include "Colors.h"
class Border
{
public:
	Border()=default;
	Border(Location& topleft, Location& bottomright);
	Location GetLoc();
	float GetWidth();
	float GetHeight();
	void DrawBorder(Board& brd, Graphics& gfx);
	~Border();
private:
	Location BorderLoc;
	float width;
	float height;
	Color BorderColor;
};

