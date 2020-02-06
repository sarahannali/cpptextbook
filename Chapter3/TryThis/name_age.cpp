#include "C:\Users\asara\OneDrive\Desktop\GitHub\cpptextbook\std_lib_facilities.h.txt"

int main()
{
    cout << "Please enter your first name and your age in years, separated by a white space: \n";
    string name;
    double age;
    cin >> name >> age;
    int monthsAge = age * 12;
    cout << "Hello, " << name << ", you are " << monthsAge << " months old!\n";
    return 0;
}