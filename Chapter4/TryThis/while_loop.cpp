#include "../cpptextbook/std_lib_facilities.h.txt"

int main()
{
    // Using while loop:

    // int i = 0;
    
    // while (i < 26){
    //     cout << char('a' + i) << "\t" << (97 + i) << "\n";
    //     i++;
    // }

    // Using for loop:

    for (int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << "\t" << (97 + i) << "\n";
    }
}