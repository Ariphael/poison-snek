#include "Location.h"



Location::Location(float x, float y)
	:
	_x(x),
	_y(y),
	_dimension(10)
{
}

float Location::GetPosX()
{
	if (_x >= 80) {
		return 79*_dimension;
	}
	else {
		return _x * _dimension;
	}
}

float Location::GetPosY()
{
	if (_y >= 60) {
		return 59*_dimension;
	}
	else {
		return _y * _dimension;
	}
}

int Location::GetLocLength()
{
	return _dimension;
}

Location Location::operator=(Location &rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	return *this;
}


Location::~Location()
{
}
