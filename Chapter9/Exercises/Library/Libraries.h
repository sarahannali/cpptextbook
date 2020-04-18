// DONE struct for transactions w/ a book, patron, and date
// functions: checkout books
// - when checking out: check if patron and book in library
// - make sure user has no fees
// - no errors = place in transaction vector
// vector for all patrons who owe fees

#ifndef LIBRARY_H
#define LIBRARY_H

#include "../../../std_lib_facilities.h.txt"
#include "Books.h"
#include "Dates.h"
#include "Patrons.h"

using Books::Book;
using Books::Genre;
using Dates::Date;
using Dates::Month;
using Patrons::Patron;

namespace Libraries
{
struct Transaction
{
    Book book;
    Patron patron;
    Date date;
};

class Library
{
public:
    void available_books();
    void view_transactions();
    void add_book(const Book &b);
    void add_patron(const Patron &p);
    void checkout_book(const Book, const Patron, const Date);
    int total_books() const { return books.size(); };
    int total_patrons() const { return patrons.size(); };

private:
    vector<Patron> patrons;
    vector<Book> books;
    vector<Transaction> transactions;
    vector<Patron> owe_fees;
    bool valid_patron(const Patron &p);
    bool available_book(const Book &b);
};

ostream &operator<<(ostream &os, const Library &l);
ostream &operator<<(ostream &os, const Transaction &t);

} // namespace Libraries

#endif