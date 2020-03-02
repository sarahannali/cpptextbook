#include "../../std_lib_facilities.h.txt"

int ctok(char temp, double d) // converts Celsius to Kelvin
{
    if ((temp == 'c' && d < -273.15) || (temp == 'k' && d < 0))
    {
        error("Lower than lowest recorded temperature.");
        return 0;
    }
    if (temp == 'k')
    {
        int c = d - 273.15;
        return c;
    }
    if (temp == 'c')
    {
        int k = d + 273.15;
        return k;
    }
    return 0;
}

int main()
{
    double c = 0;
    char temp = 'a';            // declare input variable
    cin >> c >> temp;           // retrieve temperature to input variable
    double ans = ctok(temp, c); // convert temperature
    if (temp == 'k')            // print out temperature
    {
        cout << ans << 'c';
    }
    else
    {
        cout << ans << 'k';
    }
}