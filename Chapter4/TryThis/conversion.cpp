#include "../cpptextbook/std_lib_facilities.h.txt"

int main()
{
    constexpr double yen_per_dollar = 109.69;
    constexpr double euros_per_dollar = .91;
    constexpr double pounds_per_dollar = .78;

    double amount;
    string type;

    cout << "Please enter the amount of money, a space, and the type of currency ('yen', 'euros', or 'pounds'): ";

    cin >> amount >> type;

    char type_first_letter = type.at(0);

    // Using if statements:

    // if (type == "yen")
    // {
    //     cout << "You have " + std::to_string(amount * yen_per_dollar) + " dollars.";
    // }

    // else if (type == "euros")
    // {
    //     cout << "You have " + std::to_string(amount * euros_per_dollar) + " dollars.";
    // }

    // else if (type == "pounds")
    // {
    //     cout << "You have " + std::to_string(amount * pounds_per_dollar) + " dollars.";
    // }

    // else
    // {
    //     cout << "Sorry, I didn't understand your input :(";
    // }

    // Using switch statements:

    switch (type_first_letter)
    {
        case 'y':
            cout << "You have " + std::to_string(amount * yen_per_dollar) + " dollars.";
            break;
        case 'e':
            cout << "You have " + std::to_string(amount * euros_per_dollar) + " dollars.";
            break;
        case 'p':
            cout << "You have " + std::to_string(amount * pounds_per_dollar) + " dollars.";
            break;
        default:
            cout << "Sorry, I didn't understand your input :(";
            break;
    }

    return 0;
}