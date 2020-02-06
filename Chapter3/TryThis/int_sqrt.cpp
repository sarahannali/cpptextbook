#include "C:\Users\asara\OneDrive\Desktop\GitHub\cpptextbook\std_lib_facilities.h.txt"

int main()
{
    cout << "Please enter an int value: ";
    int n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\nn squared == " << n * n
         << "\nhalf of n == " << ((double)n) / 2
         << "\nsquare root of n == " << sqrt(n)
         << '\n'; // another name for newline (“end of line”) in output
}