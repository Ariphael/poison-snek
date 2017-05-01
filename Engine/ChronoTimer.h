#pragma once
#include <chrono>
class ChronoTimer
{
public:
	ChronoTimer();
	float Mark();
	~ChronoTimer();
private:
	std::chrono::steady_clock::time_point a;
};

