#include "C:\Users\asara\OneDrive\Desktop\GitHub\cpptextbook\std_lib_facilities.h.txt"

int main()
{
    string first_name;
    cout << "Please enter the name of the person you want to write to: ";
    cin >> first_name;

    cout << "\nDear " + first_name + ",\n";

    cout << "\n    How are you? I am fine. It is very cold here, my dog is really loving it.\n";

    string friend_name;
    cout << "\nPlease enter the name of another friend: ";
    cin >> friend_name;

    cout << "\nHave you seen " + friend_name + " lately?\n";

    char friend_sex = 0;
    cout << "\nPlease enter an 'm' if " + friend_name + " if male, and an 'f' if they are female: ";
    cin >> friend_sex;

    cout << "\nIf you see " + friend_name + ", tell ";
    if (friend_sex == 'f')
    {
        cout << "her";
    }
    else
    {
        cout << "him";
    }
    cout << " to call me.\n";

    int age;
    cout << "\nWhat is the age of " + first_name + "? ";
    cin >> age;
    if (age < 0 || age > 110)
    {
        simple_error("you're kidding!");
    }

    cout << "\nI hear you just had a birthday and you are " + std::to_string(age) + " years old. ";
    if (age < 12)
    {
        cout << "Next year you will be " + std::to_string(age + 1) + " years old.\n";
    }
    if (age == 17)
    {
        cout << "Next year you will be able to vote!\n";
    }
    if (age > 70)
    {
        cout << "I hope you are enjoying retirement.\n";
    }

    cout << "\nYours sincerely,\n\n    -Sarah";

    return 0;
}