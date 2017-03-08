#include "nextdate.h"
#include <algorithm>
#include <iterator>

Date::Date() {
    _year = 1812;
    _month = 1;
    _day = 1;
}

Date::Date(int year, int month, int day) {
    _year = year;
    _month = month;
    _day = day;
}

Date Date::nextdate() {
    YearType ytype;
    MonthType mtype;
    DayType dtype;

    if (_year < 1812 || _year > 2012)
        return Date();
    if (_month < 1 || _month > 12)
        return Date();
    if (_day < 1 || _day > 31)
        return Date();


    int MType_1[] = {1, 3, 5, 7, 8, 10, 12};
    int MType_2[] = {4, 6, 9, 11};
    int MType_3[] = {2};

    if ((_year % 400 == 0) || ((_year % 4 == 0) && (_year % 100 != 0)))
        ytype = YEAR_LEAP;
    else
        ytype = YEAR_COMMON;


    if (std::find(std::begin(MType_1), std::end(MType_1), _month) != std::end(MType_1))
        mtype = MONTH_31DAYS;
    else if (std::find(std::begin(MType_2), std::end(MType_2), _month) != std::end(MType_2))
        mtype = MONTH_30DAYS;
    else
        mtype = MONTH_FEB;


    if (_day <= 28)
        dtype = DAY_COMMON;
    else if (_day <= 29)
        dtype = DAY_29DAY;
    else if (_day <= 30)
        dtype = DAY_30DAY;
    else
        dtype = DAY_31DAY;

    
    if (ytype == YEAR_LEAP && mtype == MONTH_FEB && _day > 29)
        return Date();
    if (ytype == YEAR_COMMON && mtype == MONTH_FEB && _day > 28)
        return Date();


    if (_month == 12 && _day == 31)
        return Date(_year + 1, 1, 1);
    else if (mtype == MONTH_31DAYS && dtype == DAY_31DAY)
        return Date(_year, _month + 1, 1);
    else if (mtype == MONTH_30DAYS && dtype == DAY_30DAY)
        return Date(_year, _month + 1, 1);
    else if (ytype == YEAR_COMMON && mtype == MONTH_FEB && _day == 28)
        return Date(_year, _month + 1, 1);
    else if (ytype == YEAR_LEAP && mtype == MONTH_FEB && _day == 29)
        return Date(_year, _month + 1, 1);
    else
        return Date(_year, _month, _day + 1);
}
