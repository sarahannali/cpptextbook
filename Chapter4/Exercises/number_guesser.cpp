// Write a program to play a numbers guessing game.
// The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is
// (e.g., “Is the number you are thinking of less than 50?”).
// Your program should be able to identify the number after asking no more than seven questions.
// Hint: Use the < and <= operators and the if-else construct.

#include "../cpptextbook/std_lib_facilities.h.txt"

int main()
{
    cout << "Think off a number between 1 and 100...\n";

    cout << "Enter 'l' for larger and 's' for smaller. Enter 'c' for correct.\n\n";

    char response;

    double num = 50;
    double diff = 50;
    int guess;

    cout << "50? ";

    while (cin >> response)
    {
        switch (response)
        {

        case 'c':
            cout << "Thanks for playing!";
            break;

        case 'l':
            guess = num + (diff / 2);
            diff = guess - num;

            if (diff < 1)
            {
                guess = num + 1;
            }

            num = guess;

            cout << "\n"
                 << guess << "? ";

            break;

        case 's':
            guess = num - (diff / 2);
            diff = num - guess;

            if (diff < 1)
            {
                guess = num - 1;
            }

            num = guess;

            cout << "\n"
                 << guess << "? ";

            break;

        default:
            cout << "Please enter an accepted input (l, s, or c)";
            break;
        }
    }

    return 0;
}