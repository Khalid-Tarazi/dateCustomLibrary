#include <iostream>
#include "clsDate.h"
using namespace std;

int main() {
	
	clsDate date1;
	date1.print();

	clsDate date2("4/7/2026");
	date2.print();

	clsDate date3(4, 7, 2026);
	date3.print();

	clsDate date4(250, 2026);
	dete4.print();
	
	//-----------

	date1.increaseDateByOneMonth();
	date1.print();

	//date3.printYearCalendar();
	//cout << date2.isValid() << endl;

	/*cout << "My age in days: " <<
		clsDate::calculateMyAgeInDays(clsDate(4, 8, 1989));*/

	//-----------

	//I can try any method ony my own.




	system("pause>0");
	return 0;
}