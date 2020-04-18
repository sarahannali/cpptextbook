#include "Patrons.h"

namespace Patrons
{
Patron::Patron(string given_name, int given_card_number, double given_fees)
    : name{given_name}, card_number{given_card_number}, fees{given_fees}
{
    
}

void Patron::set_fee(double given_fee)
{
    fees = given_fee;
}

bool fees_owed(const Patron &p)
{
    return p.get_fees() != 0.0;
}

ostream &operator<<(ostream &os, const Patron &p)
{
    return os << "Name: " << p.get_name()
              << ", Card Number: " << p.get_card_number()
              << ", Fees: " << p.get_fees();
}

bool operator==(const Patron &a, const Patron &b)
{
    return a.get_name() == b.get_name();
}

} // namespace Patrons