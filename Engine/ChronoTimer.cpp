#include "ChronoTimer.h"



ChronoTimer::ChronoTimer()
{
	a = std::chrono::steady_clock::now();
}

float ChronoTimer::Mark()
{
	auto old = a;
	a = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed = a - old;
	return elapsed.count();
}


ChronoTimer::~ChronoTimer()
{
}
