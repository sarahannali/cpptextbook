#include "C:\Users\asara\OneDrive\Desktop\GitHub\cpptextbook\std_lib_facilities.h.txt"

int main()
{
    cout << "Please enter a string, use ^C to quit: ";
    string previous = " "; // previous word; initialized to “not a word”
    string current;        // current word
    while (cin >> current)
    {                            // read a stream of words
        if (previous == current) // check if the word is the same as last
            cout << "repeated word: " << current << '\n';
        previous = current;
    };
    return 0;
}