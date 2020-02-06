#include "C:\Users\asara\OneDrive\Desktop\GitHub\cpptextbook\std_lib_facilities.h.txt"

int main()
{
    // Exercise 4:

    int val1;
    int val2;
    cout << "Please enter two integer values, separated by a whitespace: ";
    cin >> val1 >> val2;

    if (val1 < val2)
    {
        cout << "\nSmaller Number: " + std::to_string(val1) + "\nLarger Number: " + std::to_string(val2);
    }
    else if (val2 < val1)
    {
        cout << "\nSmaller Number: " + std::to_string(val2) + "\nLarger Number: " + std::to_string(val1);
    }
    else
    {
        cout << "\nThey are the same number!";
    }

    cout << "\nThe numbers sum is " + std::to_string(val1 + val2);
    cout << "\nThe numbers difference is " + std::to_string(val1 - val2);
    cout << "\nThe numbers product is " + std::to_string(val1 * val2);
    cout << "\nThe numbers ratio is " + std::to_string(val1 / val2);

    //Exercise 5:

    double val3;
    double val4;
    cout << "\n\nPlease enter two floating point values, separated by a whitespace: ";
    cin >> val3 >> val4;

    if (val3 < val4)
    {
        cout << "\nSmaller Number: " + std::to_string(val3) + "\nLarger Number: " + std::to_string(val4);
    }
    else if (val4 < val3)
    {
        cout << "\nSmaller Number: " + std::to_string(val4) + "\nLarger Number: " + std::to_string(val3);
    }
    else
    {
        cout << "\nThey are the same number!";
    }

    cout << "\nThe numbers sum is " + std::to_string(val3 + val4);
    cout << "\nThe numbers difference is " + std::to_string(val3 - val4);
    cout << "\nThe numbers product is " + std::to_string(val3 * val4);
    cout << "\nThe numbers ratio is " + std::to_string(val3 / val4);

    return 0;
}