#include "nextdate.h"

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
