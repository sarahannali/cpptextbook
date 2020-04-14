#include "../../std_lib_facilities.h.txt"

void print_vector(string s, const vector<int>& v)
{
    cout << s << ": ";
    for (int i : v)
    {
        cout << '\n' << i;
    }
}

vector<int> fibonacci(int x, int y, vector<int>& v, int total_length)
{
    v.push_back(x);
    v.push_back(y);

    int to_calculate = total_length - 2;

    for(int i = 0; i < to_calculate; i++)
    {
        int num = v[i] + v[i+1];
        v.push_back(num);
    }

    return v;
}

main()
{
    vector<int> v = {};
    vector<int> fibonacci_vector = fibonacci(1, 2, v, 5);
    print_vector("vector1", fibonacci_vector);
}