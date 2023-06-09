#include "stdafx.h"
#include "clock_header.h"

Clock::Clock(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}
Clock::~Clock()
{

}
void Clock::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;
	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}
void Clock::getTime(int &hours, int& minutes, int& seconds)
{
	hours = hr;
	minutes = min;
	seconds = sec;
}
Clock Clock::operator++()
{
	sec++;
	if (sec > 59)
	{
		sec = 0;
		min++;
		if (min > 59)
		{
			min = 0;
			hr++;
			if (hr > 23)
				hr = 0;
		}
	}

	return *this;
}
bool Clock ::operator<=(const Clock& otherClock) const
{
	return ((hr < otherClock.hr) ||
		(hr == otherClock.hr && min < otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min && sec <= otherClock.sec));
}
bool Clock::operator==(const Clock& otherClock) const
{
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}