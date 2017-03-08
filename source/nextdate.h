#if !defined(NEXTDATE_H_)
#define NEXTDATE_H_

class Date {

    public:
        Date();
        Date(int, int, int);
        Date nextdate();

        int year() const {
            return _year;
        }
        int month() const {
            return _month;
        }
        int day() const {
            return _day;
        }

        bool operator == (const Date& date) const {
            if ((_year==date.year()) && (_month==date.month()) && (_day==date.day()))
                return true;
            else
                return false;
        }

    private:
        int _year;
        int _month;
        int _day;

};

enum YearType {
    YEAR_LEAP, 
    YEAR_COMMON
};

enum MonthType {
    MONTH_31DAYS, 
    MONTH_30DAYS, 
    MONTH_FEB
};

enum DayType {
    DAY_COMMON, 
    DAY_29DAY, 
    DAY_30DAY, 
    DAY_31DAY
};

#endif
