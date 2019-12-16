#include<iostream>
#ifndef time_h
#define time_h

class Time
{
	friend void tick(Time &t);
public:
	Time(int = 0, int = 0, int = 0);

	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	int getHour();
	int getMinute();
	int getSecond();

	void printUniversal();
	void printStandard();
private:
	int hour;
	int minute;
	int second;
};

#endif#pragma once
