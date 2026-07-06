#pragma once
#include "clsDate.h"

class clsPeriod 
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo) {
        
        this->StartDate = StartDate;
        this->EndDate = EndDate;
    }

    static bool isOverlapPeriods(clsPeriod Period1, clsPeriod Period2) {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }

    bool isOverLapWith(clsPeriod Period2) {
        return isOverlapPeriods(*this, Period2);
    }

    void print() {
        cout << "Period Start: ";
        StartDate.print();


        cout << "Period End: ";
        EndDate.print();
    }
};