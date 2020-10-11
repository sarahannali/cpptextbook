#include "../../std_lib_facilities.h.txt"

const int too_low = -129;
const int too_high = 135;

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

void write_to_file(const vector<Reading> &r, const string &file_name)
{
    ofstream ofs {file_name};
    for (unsigned int i = 0; i < r.size(); i++)
    {
        ofs << r[i] << '\n';
    }
}

main()
{
    vector<Reading> readings;
    int total = 5;

    cout << "Please list " << total << " hour, temperature, and type pairs separated by a space\n";
    int entered = 0;

    while(entered < total)
    {
        Reading r;
        cin >> r;
        readings.push_back(r);
        entered++;
    }

    string file_name = "raw_temps.txt";
    write_to_file(readings, file_name);
}