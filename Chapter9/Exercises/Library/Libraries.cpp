#include "Libraries.h"

namespace Libraries
{
void Library::add_book(const Book &b)
{
    books.push_back(b);
}

void Library::add_patron(const Patron &p)
{
    patrons.push_back(p);
}

void Library::available_books()
{
    cout << "Available Books:" << '\n';
    for (unsigned i = 0; i < books.size(); i++)
    {
        if (!books[i].get_checked_out())
        {
            cout << "BOOK " << i + 1 << ": \n\t" << books[i] << '\n';
        }
    }
}

void Library::checkout_book(const Book b, const Patron p, const Date d)
{
    if (!valid_patron(p))
        error("Invalid patron.");
    if (!available_book(b))
        error("Book not available.");

    for (unsigned i = 0; i < books.size(); i++)
    {
        if (b.get_title() == books[i].get_title())
        {
            books[i].check_out();
            Transaction transaction{b, p, d};
            transactions.push_back(transaction);
            cout << "Checking Out: " << books[i].get_title() << '\n';
        }
    }
}

void Library::view_transactions()
{
    for (unsigned i = 0; i < transactions.size(); i++)
    {
        cout << "TRANSACTION " << i+1 << ":" << transactions[i] << '\n';
    }
}

bool Library::valid_patron(const Patron &p)
{
    bool valid = false;
    unsigned int i = 0;
    while (i < patrons.size())
    {
        if (patrons[i] == p && p.get_fees() == 0)
        {
            valid = true;
        }

        i++;
    }

    return valid;
}

bool Library::available_book(const Book &b)
{
    bool valid = false;
    unsigned int i = 0;
    while (i < books.size())
    {
        if (books[i] == b)
        {
            valid = true;
        }

        i++;
    }

    return valid;
}

ostream &operator<<(ostream &os, const Library &l)
{
    return os << "Total Books: " << l.total_books()
              << ", Total Patrons: " << l.total_patrons();
}

ostream &operator<<(ostream &os, const Transaction &t)
{
    return os << "\n\tBook: " << t.book
              << "\n\tPatron: " << t.patron
              << "\n\tDate of Transaction: " << t.date;
}
} // namespace Libraries