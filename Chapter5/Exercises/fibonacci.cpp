#include "../../std_lib_facilities.h.txt"

int main()
{
    int max;
    cin >> max;

    int last = 0;
    int next = 1;
    int hold = next;

    while (next < max)
    {
        cout << next << "\n";
        next += last;
        last = hold;
        hold = next;
    }
}