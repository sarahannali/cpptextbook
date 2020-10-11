#include "../../std_lib_facilities.h.txt"

struct Reading
{
public:
    friend ostream &operator<<(ostream &os, const Reading &r)
    {
        return os << r.hour << " " << r.temp << " " << r.type;
    }
    friend istream &operator>>(istream &is, Reading &r)
    {
        return is >> r.hour >> r.temp >> r.type;
    }

private:
    int hour;
    double temp;
    string type;
};

void read_file(vector<double> &t, vector<string> &r, const string &file_name)
{
    ifstream ist{file_name};

    int hour;
    double temp;
    string type;
    while (ist >> hour >> temp >> type)
    {
        t.push_back(temp);
        r.push_back(type);
    }
}

void adjust_vector(vector<double> &a, const vector<string> &b)
{
    for (unsigned int i = 0; i < a.size(); i++)
    {
        if(b[i] == "f")
        {
            a[i] = ((a[i]-32) * (5/9));
        }
    }
}

double find_median(const vector<double> &a)
{
    double median;
    double midpoint = a.size() / 2;

    if (a.size() % 2 == 0)
    {
        median = (a[midpoint - .5] + a[midpoint + .5]) / 2;
    }
    else
    {
        median = (a[midpoint] + a[midpoint])/2;
    }

    return median;
}

main()
{
    vector<double> avg_temps;
    vector<string> types;

    string file_name = "raw_temps.txt";
    read_file(avg_temps, types, file_name);

    adjust_vector(avg_temps, types);

    double total = 0;

    for (unsigned int i = 0; i < avg_temps.size(); i++)
    {
        total += avg_temps[i];
    }

    cout << "The average temperature was: " << (total / avg_temps.size());
    cout << "\nThe median temperature was: " << find_median(avg_temps);
}