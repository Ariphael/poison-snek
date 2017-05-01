#pragma once
class Location
{
public:
	Location()=default;
	Location(float x, float y);
	float GetPosX(); //Gets the EXACT location. ie. Multiplies _x by _dimension to get the exact location on the window
	float GetPosY(); //^
	int GetLocLength();
	Location operator=(Location &rhs);
	~Location();
public:
	float _x;
	float _y;
	const int _dimension;
};

