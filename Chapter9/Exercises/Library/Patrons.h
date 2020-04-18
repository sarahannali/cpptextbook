#ifndef PATRONS_H
#define PATRONS_H

#include "../../../std_lib_facilities.h.txt"

namespace Patrons
{
class Patron
{
public:
    Patron(string, int, double);
    void set_fee(double);
    string get_name() const { return name; };
    int get_card_number() const { return card_number; };
    double get_fees() const { return fees; };

private:
    string name;
    int card_number;
    double fees;
};

bool fees_owed(const Patron &p);
ostream &operator<<(ostream &os, const Patron &p);
bool operator==(const Patron &a, const Patron &b);
} // namespace Patrons

#endif