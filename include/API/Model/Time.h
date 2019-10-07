#pragma once
#ifndef NUKEE_TIME_H
#define NUKEE_TIME_H

class NUKEENGINE_API Time
{
private:
	Time();
	~Time();
public:
	static Time * getSingleton() 
	{
		static Time instance;
		return &instance;
	}
	
	//Game to real time attitude
	double gtr = 0.05;

	//Time of day
	double tod = 0;

	//Year
	int year = 2000;

	//Day of year
	int doy = 1;

	//Week of year
	int woy = 1;

	//Month of year
	int month = 1;

	//Day of month
	int day = 1;

	//Day of week
	int dow = 1;

	//Total game time
	long double totalgt = 0;
	
	//Total game days
	long long unsigned int totalgd = 0;

    int hour;
    int minute;
    int sec;

	void TickMonth();

	void TickDay();

	void TickHour();

	void TickMinute();

	void TickSecond();

	//Ticker
	void Tick();

	static int CalcDayOfYear(int day, int month, int year);

	static int CalcWeekOfYear(int dayofyear);

	void Init();

	void Init(double gtr, int day, int month, int year);
	
	void Init(double gtr, int day, int month, int year, int hour);
	
	void Init(double gtr, int day, int month, int year, int hour, int minute);

	void Init(double gtr, int day, int month, int year, int hour, int minute, int sec);

	void Run();
};

#endif // !NUKEE_TIME_H
