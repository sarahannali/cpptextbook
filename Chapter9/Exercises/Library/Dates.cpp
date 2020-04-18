#include "Dates.h"

namespace Dates
{
Date::Date(int yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if (!is_valid())
        error("Invalid date!");
}

bool Date::is_valid()
{
    if ((d >= 1 && d <= 31) && (int(m) >= 1 && int(m) <= 12))
    {
        return true;
    }

    return false;
}

ostream &operator<<(ostream &os, const Date &d)
{
    return os << '(' << int(d.month())
              << ", " << d.day()
              << ", " << d.year() << ')';
}



} // namespace Dates