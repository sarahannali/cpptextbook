#include "Books.h"

namespace Books
{
Book::Book(string given_title, string given_author, Date given_copyright_date, string given_isbn, Genre given_genre)
    : title{given_title}, author{given_author}, copyright_date{given_copyright_date}, isbn{given_isbn}, genre{given_genre}
{
    if (!valid_isbn())
    {
        error("Invalid ISBN");
    }
}

bool Book::valid_isbn()
{
    bool valid = true;
    if (isbn.length() == 4)
    {
        valid = ('0' <= isbn[0] && isbn[0] <= '9');
        valid &= ('0' <= isbn[1] && isbn[1] <= '9');
        valid &= ('0' <= isbn[2] && isbn[2] <= '9');
        valid &= ('a' <= isbn[3] && isbn[3] <= 'z');
    }
    else
    {
        valid = false;
    }
    
    return valid;
}

void Book::check_out()
{
    if (checked_out)
    {
        error("Book is already checked out.");
    }

    checked_out = true;
}

void Book::return_book()
{
    if (!checked_out)
        error("Book was not checked out.");

    checked_out = false;
}

ostream &operator<<(ostream &os, const Book &b)
{
    return os << "Title: " << b.get_title()
              << ", Author: " << b.get_author()
              << ", Copyright Date: " << b.get_copyright_date()
              << ", ISBN: " << b.get_isbn()
              << ", Genre: " << b.get_genre();
}

ostream &operator<<(ostream &os, const Genre &g)
{
    switch (int(g))
    {
    case 1:
        return os << "Fiction";
    case 2:
        return os << "Non-Fiction";
    case 3:
        return os << "Periodical";
    case 4:
        return os << "Biography";
    case 5:
        return os << "Children's";
    default:
        return os << "N/A";
    }
}

bool operator==(const Book& a, const Book& b)
{
    return a.get_isbn() == b.get_isbn();
}

bool operator!=(const Book& a, const Book& b)
{
    return a.get_isbn() != b.get_isbn();
}

} // namespace Books