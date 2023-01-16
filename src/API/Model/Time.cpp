#include "API/Model/Time.h"
#include <unistd.h>

NukeTime::NukeTime() {}

NukeTime::~NukeTime() {}

void NukeTime::TickMonth()
{
	if (month == 12)
	{
		year++;
		month = 1;
		woy = 1;
	}
}

void NukeTime::TickDay()
{
	if ((doy == 366 && year % 4 == 0) || (doy == 365 && year % 4))
	{
		doy = 0;
	}
	if (dow == 7)
	{
		dow = 0;
		woy++;
	}
	if (
		(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
		||
		(day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		||
		(day == 28 && month == 2 && year % 4)
		||
		(day == 29 && month == 2 && year % 4 == 0))
	{
		day = 0;
		TickMonth();
	}
	day++;
	dow++;
	doy++;
	totalgd++;
}

void NukeTime::TickHour()
{
	hour++;
	if (hour == 24)
	{
		TickDay();
		hour = 0;
	}
}

void NukeTime::TickMinute()
{
	minute++;
	if (minute == 60)
	{
		TickHour();
		minute = 0;
	}
}

void NukeTime::TickSecond()
{
	sec++;
	if (sec == 60)
	{
		TickMinute();
		sec = 0;
	}
	tod = (sec + minute * 60 + hour * 3600) / 24 * 3600;
}

//Ticker
void NukeTime::Tick()
{
	int toSleep = 1000 * gtr;
#ifdef WIN32
	Sleep(toSleep);
#else
	usleep(toSleep);
#endif
	TickSecond();
}

int NukeTime::CalcDayOfYear(int day, int month, int year)
{
	int dayofy = 0;
	for (int i = 1; i < month; i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			dayofy += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			dayofy += 30;
			break;
		case 2:
			if (year % 4 == 0)
				dayofy += 29;
			else
				dayofy += 28;
			break;
		default:
			break;
		}
	}
	dayofy += day;
	return dayofy;
}

int NukeTime::CalcWeekOfYear(int dayofyear)
{
	return (dayofyear / 7) + 1;
}

void NukeTime::Init()
{
	gtr = 0.05;
	day = 1;
	year = 2000;
	month = 1;
	woy = 1;
}

void NukeTime::Init(double gtr, int day, int month, int year)
{
	this->gtr= gtr;
	this->day = day;
	this->year = year;
	this->month = month;
	woy = 1;
}

void NukeTime::Init(double gtr, int day, int month, int year, int hour)
{
	this->Init(gtr, day, month, year);
	this->hour = hour;
}

void NukeTime::Init(double gtr, int day, int month, int year, int hour, int minute)
{
	this->Init(gtr, day, month, year, hour);
	this->minute = minute;
}

void NukeTime::Init(double gtr, int day, int month, int year, int hour, int minute, int sec)
{
	this->Init(gtr, day, month, year, hour, minute);
	this->sec = sec;
}

void NukeTime::Run()
{
	Tick();
}
