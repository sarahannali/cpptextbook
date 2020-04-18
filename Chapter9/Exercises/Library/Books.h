#ifndef BOOKS_H
#define BOOKS_H

#include "../../../std_lib_facilities.h.txt"
#include "Dates.h"

namespace Books
{

using Dates::Date;

enum class Genre
{
    fiction = 1,
    nonfiction,
    periodical,
    biography,
    children
};

class Book
{
public:
    Book(string, string, Date, string, Genre);
    void check_out();
    void return_book();
    string get_title() const { return title; };
    string get_author() const { return author; };
    Date get_copyright_date() const { return copyright_date; };
    string get_isbn() const { return isbn; };
    Genre get_genre() const { return genre; };
    bool get_checked_out() const { return checked_out; };

private:
    string title;
    string author;
    Date copyright_date;
    string isbn;
    Genre genre;
    bool checked_out = false;
    bool valid_isbn();
};

ostream &operator<<(ostream &os, const Book &b);
ostream &operator<<(ostream &os, const Genre &g);
bool operator==(const Book &a, const Book &b);
bool operator!=(const Book &a, const Book &b);
} // namespace Books

#endif