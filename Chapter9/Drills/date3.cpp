#include "../../std_lib_facilities.h.txt"

class Date
{
private:
    int y;
    int m;
    int d;
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int year() const {return y;}; // must or operator function won't want to call this because you passed-by-const and it doesn't know if the member function will change the variable
    int month() const {return m;};
    int day() const {return d;};
};

Date::Date(int yy, int mm, int dd)
{
    if ((dd >= 1 && dd <= 31) && (mm >= 1 && mm <= 12))
    {
        y = yy;
        m = mm;
        d = dd;
    }
    else
    {
        error("Invalid date given.");
    }
}

void Date::add_day(int n)
{
    d += n;

    while (d > 31)
    {
        m += 1;
        d -= 31;
    }

    while (m > 12)
    {
        m -= 12;
    }
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}

main()
{
    Date today{2004, 5, 30};
    // Date err{2004, 13, -5};
    // cout << err;
    cout << today;
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << tomorrow;
}