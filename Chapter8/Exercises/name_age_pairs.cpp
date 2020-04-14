#include "../../std_lib_facilities.h.txt"

// void print_vector(string s, const vector<int>& v)
// {
//     cout << s << ": ";
//     for (int i : v)
//     {
//         cout << '\n' << i;
//     }
// }

void print_vector(string vector_name, const vector<string> &v)
{
    cout << vector_name << ": ";

    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\t';
    }

    cout << '\n';
}

int main()
{
    string input;

    cout << "List each name, followed by the enter key. Use 'q' to end input." << '\n';

    vector<string> names;

    while (cin >> input)
    {
        if (input != "q")
        {
            names.push_back(input);
        }
        else
            break;
    }

    vector<string> ages;

    for (unsigned int i = 0; i < names.size(); i++)
    {
        cout << "What is " << names[i] << "'s age? ";
        cin >> input;
        ages.push_back(input);
    }

    vector<string> temp_names = names;
    vector<string> new_ages;
    sort(names.begin(),names.end());

    for (unsigned int i = 0; i < names.size(); i++)
    {
        for (unsigned int j = 0; j < temp_names.size(); j++)
        {
            if (temp_names[j] == names[i])
            {
                new_ages.push_back(ages[j]);
            }
        }
    }

    print_vector("ages", new_ages);
    print_vector("names", names);

    return 0;
}