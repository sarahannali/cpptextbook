#include <iostream>
#include <vector>

using namespace std;

void print_array10(ostream &os, int *a)
{
    for (int i = 0; i < 10; i++) os << a[i] << endl;
}

void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; i++) os << a[i] << endl;
}

void print_vector(ostream& os, vector<int> v)
{
    for (int i : v) os << i << endl;
}

int main()
{
    int *ints = new int[10];
    print_array10(cout, ints);

    delete[] ints;

    int *ints_2 = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_array10(cout, ints_2);

    delete[] ints_2;

    int *ints_3 = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_array(cout, ints_3, 11);

    delete[] ints_3;

    int *ints_4 = new int[20] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
    print_array(cout, ints_4, 20);

    delete[] ints_4;

    vector<int> vec_2 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_vector(cout, vec_2);

    vector<int> vec_3 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_vector(cout, vec_3);

    vector<int> vec_4 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
    print_vector(cout, vec_4);

}