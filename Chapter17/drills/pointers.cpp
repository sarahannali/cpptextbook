#include <iostream>
#include <vector>

using namespace std;

void print_array(ostream &os, int *a, int n)
{
    for (int i = 0; i < n; i++)
        os << a[i] << ' ';

    cout << endl;
}

void print_vector(ostream &os, vector<int> v)
{
    for (int i : v)
        os << i << ' ';

    cout << endl;
}

int main()
{
    int x = 7;
    int *p1 = &x;

    cout << "p1: " << p1 << " x: " << x << endl;

    int *p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};

    cout << "p2: " << p2 << " y: ";

    print_array(cout, p2, 7);

    cout << endl;

    int *p3 = p2;
    p1 = p2;
    p2 = p3;

    cout << "p1: " << p1 << " p1*: " << *p1 << " p2: " << p2 << " p2*: " << *p2 << endl;

    delete[] p2;

    p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];

    for (int i = 0; i < 10; i++)
    {
        p2[i] = p1[i];
    }

    print_array(cout, p2, 10);

    vector<int> vec1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> vec2;

    for (int i = 0; i < 10; i++)
    {
        vec2.push_back(vec1[i]);
    }

    print_vector(cout, vec2);
}