#include "Border.h"


Border::Border(Location & topleft, Location & bottomright)
	:
	BorderLoc(Location(topleft._x,topleft._y)),
	width(bottomright._x-topleft._x),
	height(bottomright._y-topleft._y),
	BorderColor(Colors::Gray)
{
}

Location Border::GetLoc()
{
	return BorderLoc;
}

float Border::GetWidth()
{
	return width;
}

float Border::GetHeight()
{
	return height;
}

void Border::DrawBorder(Board & brd, Graphics& gfx)
{
	for (int w = (int)BorderLoc._x; w <= (int)BorderLoc._x + (int)width; w++) {
		for (int h = (int)BorderLoc._y; h <= (int)BorderLoc._y + (int)height; h++) {
			if (w == (int)BorderLoc._x || w == (int)BorderLoc._x + (int)width || h == (int)BorderLoc._y || h == (int)BorderLoc._y + (int)height) {
				brd.DrawBox(Location(w, h), gfx, BorderColor);
			}
		}
	}
}

Border::~Border()
{
}
