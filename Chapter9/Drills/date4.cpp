#include "../../std_lib_facilities.h.txt"

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m, int)
{
    Month new_m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
    m = new_m;
    return m;
}

class Date
{
private:
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d);
    void add_day(int n);
    int year() const {return y;}; // must or operator function won't want to call this because you passed-by-const and it doesn't know if the member function will change the variable
    Month month() const {return m;};
    int day() const {return d;};
};

Date::Date(int yy, Month mm, int dd)
{
    if ((dd >= 1 && dd <= 31) && (int(mm) >= 1 && int(mm) <= 12))
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
        m++;
        d -= 31;
    }
}

ostream &operator<<(ostream &os, const Date &d)
{
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}

main()
{
    Date today{2004, Month::may, 31};
    Date err{2004, Month(13), -5};
    cout << err;
    cout << today;
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << tomorrow;
}