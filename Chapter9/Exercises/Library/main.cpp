#include "Libraries.h"

using Libraries::Library;

int main()
try
{
    Library library;
    Book book1{"Grapes of Wrath", "John Steinbeck", Date{1939, Month::apr, 14}, "112a", Genre::fiction};
    Book book2{"In Cold Blood", "Truman Capote", Date{1965, Month::aug, 16}, "612b", Genre::nonfiction};
    Book book3{"The World According to Garp", "John Irving", Date{1978, Month::jul, 2}, "143c", Genre::fiction};
    Book book4{"The Diary of a Young Girl", "Anne Frank", Date{1947, Month::jun, 25}, "522f", Genre::biography};
    Book book5{"Charlotte's Web", "E. B. White", Date{1952, Month::oct, 15}, "335e", Genre::children};

    library.add_book(book1);
    library.add_book(book2);
    library.add_book(book3);
    library.add_book(book4);
    library.add_book(book5);
    cout << library << '\n' << '\n';
    library.available_books();
    cout << '\n';

    Patron patron1{"Sarah Ali", 14857934, 0.0};
    Patron patron2{"Kevin Tang", 14234567, 0.0};
    Patron patron3{"Zeus", 16425634, 0.0};
    Patron patron4{"Neon", 23453257, 0.0};

    library.add_patron(patron1);
    library.add_patron(patron2);
    library.add_patron(patron3);
    library.add_patron(patron4);

    cout << library << '\n' << '\n';

    library.checkout_book(book1, patron1, Date{2020, Month::jan, 17});
    library.checkout_book(book2, patron2, Date{2020, Month::mar, 1});
    library.checkout_book(book3, patron3, Date{2020, Month::apr, 28});

    cout << '\n';
    library.available_books();
    cout << '\n';
    library.view_transactions();

    // cout << Book2 << '\n';

    // cout << Patron1 << '\n';
    // cout << fees_owed(Patron1) << '\n';
    // Patron1.set_fee(0.73);
    // cout << fees_owed(Patron1) << '\n';
    // cout << Patron1;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
