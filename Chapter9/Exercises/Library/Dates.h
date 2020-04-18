#ifndef DATES_H
#define DATES_H

#include "../../../std_lib_facilities.h.txt"

namespace Dates
{
enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

class Date
{
public:
    Date(int yy, Month mm, int dd);
    int year() const { return y; }; // must or operator function won't want to call this because you passed-by-const and it doesn't know if the member function will change the variable
    Month month() const { return m; };
    int day() const { return d; };

private:
    int y;
    Month m;
    int d;
    bool is_valid();
};

ostream &operator<<(ostream &os, const Date &d);
} // namespace Dates

#endif