#include "../../std_lib_facilities.h.txt"

struct Date
{
    int y;
    int m;
    int d;
};

void init_day(Date &dd, int y, int m, int d)
{
    if ((d >= 1 && d <= 31) && (m >= 1 && m <= 12))
    {
        dd.y = y;
        dd.m = m;
        dd.d = d;
    }
    else
    {
        error("Invalid date given.");
    }
}

void add_day(Date &dd, int n)
{
    dd.d += n;

    while (dd.d > 31)
    {
        dd.m += 1;
        dd.d -= 31;
    }

    while(dd.m > 12)
    {
        dd.m -= 12;
    }
}

main()
{
    Date today;
    init_day(today, 2004, 5, 30);
    cout << today.m << ", ";
    cout << today.d << ", ";
    cout << today.y;

    // Date err;
    // init_day(err, 2004, 13, -5);
    // cout << today.m << ", ";
    // cout << today.d << ", ";
    // cout << today.y;

    Date tomorrow = today;
    add_day(tomorrow, 1);
    cout << '\n' << tomorrow.m << ", ";
    cout << tomorrow.d << ", ";
    cout << tomorrow.y;
}