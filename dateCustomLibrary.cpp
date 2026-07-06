#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;

int main() {
	
	clsDate date1;
	date1.print();

	clsDate date2("4/7/2026");
	date2.print();

	clsDate date3(4, 7, 2026);
	date3.print();

	clsDate date4(250, 2026);
	date4.print();
	
	//-----------

	date1.increaseDateByOneMonth();
	date1.print();

	date3.printYearCalendar();
	cout << date2.isValid() << endl;

	cout << "My age in days: " <<
		clsDate::calculateMyAgeInDays(clsDate(4, 8, 1989));

	//-----------

	//I can try any method ony my own.

	//-----------

	clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
	Period1.print();

	cout << "\n";

	clsPeriod Period2(clsDate(3, 1, 2022), clsDate(5, 1, 2022));
	Period2.print();


	//You can check like this
	cout << Period1.isOverLapWith(Period2) << endl;


	//Also you can call the static method and send period 1 and period 2
	cout << clsPeriod::isOverlapPeriods(Period1, Period2) << endl;

	system("pause>0");
	return 0;
}