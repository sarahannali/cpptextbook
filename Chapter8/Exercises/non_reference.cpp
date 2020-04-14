#include "../../std_lib_facilities.h.txt"

void non_ref_func(const int f) // still does copy reference
{
    cout << f;
    cout << f + 2;

    // f += 1; can't occur b/c const
    // cout << f;
}

main()
{
    non_ref_func(2);
}