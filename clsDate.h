#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate {
	
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate() {
		
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate) {
		
		vector <string> vDate;
		vDate = clsString::split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short day, short month, short year) {

		_Day = day;
		_Month = month;
		_Year = year;
	}

	clsDate(short dateOrderInYear, short year) {

		//This will construct a date by date order in year
		clsDate date1 = getDateFromDayOrderInYear(dateOrderInYear, year);
		_Day = date1.day;
		_Month = date1.month;
		_Year = date1.year;
	}








};