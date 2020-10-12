#include "iostream"

using std::cout;

void sizes(char ch, bool i, bool* p)
{
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof (ch) << '\n';
    cout << "the size of int is " << sizeof(bool) << ' ' << sizeof (i) << '\n';
    cout << "the size of int* is " << sizeof(bool*) << ' ' << sizeof (p) << '\n';
}

int main()
{
    bool x = true;
    bool* p = &x;
    sizes('a', x, p);
}