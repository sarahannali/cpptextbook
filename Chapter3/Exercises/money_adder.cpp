#include "C:\Users\asara\OneDrive\Desktop\GitHub\cpptextbook\std_lib_facilities.h.txt"

int main()
{
    int pennies;
    int nickels;
    int dimes;
    int quarters;

    cout << "How many pennies do you have? ";
    cin >> pennies;
    cout << "How many nickels do you have? ";
    cin >> nickels;
    cout << "How many dimes do you have? ";
    cin >> dimes;
    cout << "How many quarters do you have? ";
    cin >> quarters;

    cout << "\n\nYou have " + std::to_string(pennies);
    if (pennies > 1){
        cout << " pennies.";
    }
    else {
        cout << " penny.";
    }
    
    cout << "\nYou have " + std::to_string(nickels) + " nickel";
    if (nickels > 1){
        cout << "s.";
    }
    else{
        cout << ".";
    }

    cout << "\nYou have " + std::to_string(dimes) + " dime";
    if (dimes > 1){
        cout << "s.";
    }
    else{
        cout << ".";
    }

    cout << "\nYou have " + std::to_string(quarters) + " quarter";
    if (quarters > 1){
        cout << "s.";
    }
    else{
        cout << ".";
    }

    double totalCents = pennies + (nickels * 5) + (dimes * 10) + (quarters * 25);
    double dollars = totalCents / 100;

    cout << "\n\nYou have $" + std::to_string(dollars);

    return 0;
}