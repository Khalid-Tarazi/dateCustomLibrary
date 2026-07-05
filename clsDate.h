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

	void setDay(short day) {
		_Day = day;
	}

	short getDay() {
		return _Day;
	}

	__declspec(property(get = getDay, put = setDay)) short day;

	void setMonth(short month) {
		_Month = month;
	}

	short getMonth() {
		return _Month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short month;

	void setYear(short year) {
		_Year = year;
	}

	short getYear() {
		return _Year;
	}

	__declspec(property(get = getYear, put = setYear)) short year;

	void print() {
		cout << dateToString() << endl;
	}

	static clsDate getSystemDate() {
		
		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year;

		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day, month, year);
	}

	static bool isValidDate(clsDate Date) {
		if (Date.day < 1 || Date.day>31)
			return false;
		if (Date.month < 1 || Date.month>12)
			return false;

		if (Date.month == 2) {
			if (isLeapYear(Date.year)) {
				if (Date.day > 29)
					return false;
			}
			else {
				if (Date.day > 28)
					return false;
			}
		}

		short daysInMonth = numberOfDaysInMonth(Date.month,
			Date.year);
		if (Date.day > daysInMonth)
			return false;
		return true;
	}

	bool isValid() {
		return isValidDate(*this);
	}

	static string dateToString(clsDate Date) {
		return to_string(Date.day) + "/" + to_string(Date.month) +
			"/" + to_string(Date.year);
	}

	string dateToString() {
		return dateToString(*this);
	}

	static bool isLeapYear(short year) {

		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	
	bool isLeapYear() {
		return isLeapYear(_Year);
	}

	static short numberOfDaysInYear(short year) {
		return isLeapYear(year) ? 366 : 365;
	}

	short numberOfDaysInYear() {
		return numberOfDaysInYear(_Year);
	}

	static short numberOfHoursInYear(short year) {
		return numberOfDaysInYear(year) * 24;
	}
	
	short numberOfHoursInYear() {
		return numberOfHoursInYear(_Year);
	}
	
	static int numberOfMinutesInYear(short year) {
		return numberOfHoursInYear(year) * 60;
	}

	int numberOfMinutesInYear() {
		return numberOfMinutesInYear(_Year);
	}

	static int numberOfSecondsInYear(short year) {
		return numberOfMinutesInYear(year) * 60;
	}
	
	int numberOfSecondsInYear() {
		return numberOfSecondsInYear(_Year);
	}

	static short numberOfDaysInMonth(short month, short year) {
		if (month < 1 || month > 12) return 0;

		int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return  (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; //ternary inside ternary opearator
	}

	short numberOfDaysInMonth() {
		return numberOfDaysInMonth(_Month, _Year);
	}

	static short numberOfHoursInMonth(short month, short year) {
		return numberOfDaysInMonth(month, year) * 24;
	}
	
	short numberOfHoursInMonth() {
		return numberOfHoursInMonth(_Month, _Year);
	}

	static int numberOfMinutesInMonth(short month, short year) {
		return numberOfHoursInMonth(month, year) * 60;
	}

	int numberOfMinutesInMonth() {
		return numberOfMinutesInMonth(_Month, _Year);
	}

	static int numberOfSecondsInMonth(short month, short year) {
		return numberOfMinutesInMonth(month, year) * 60;
	}

	int numberOfSecondsInMonth() {
		return numberOfSecondsInMonth(_Month, _Year);
	}

	static short dayOfWeekOrder(short Day, short Month, short Year) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short dayOfWeekOrder() {
		return dayOfWeekOrder(_Day, _Month, _Year);
	}

	static string dayShortName(short DayOfWeekOrder) {
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	




	





















};