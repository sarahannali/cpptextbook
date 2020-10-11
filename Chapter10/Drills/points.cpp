#include "../../std_lib_facilities.h.txt"

struct Point
{
public:
    Point();
    Point(double x, double y);
    double get_x() const { return x; };
    double get_y() const { return y; };
    friend ostream &operator<<(ostream &os, Point &p)
    {
        return os << p.get_x() << ' ' << p.get_y() << '\n';
    }
    friend istream &operator>>(istream &is, Point &p)
    {
        return is >> p.x >> p.y;
    }

private:
    double x;
    double y;
};

Point::Point()
    : x{0.0}, y{0.0}
{
}

Point::Point(double xx, double yy)
    : x{xx}, y{yy}
{
}

void print_points(vector<Point> &p)
{
    for (unsigned int i = 0; i < p.size(); i++)
    {
        cout << p[i];
    }
}

void write_to_file(vector<Point> &p, string &file_name)
{
    ofstream ost{file_name};

    for (unsigned int i = 0; i < p.size(); i++)
    {
        ost << p[i];
    }
}

void read_file(vector<Point> &p, string &file_name)
{
    ifstream ist{file_name};

    double x;
    double y;
    while (ist >> x >> y)
    {
        p.push_back(Point(x, y));
    }
}

bool operator!=(const Point &a, const Point &b)
{
    bool match = true;
    if (a.get_x() != b.get_x())
    {
        match = false;
    }
    if (a.get_y() != b.get_y())
    {
        match = false;
    }
    return match;
}

bool operator!=(const vector<Point> &a, const vector<Point> &b)
{
    bool match = true;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            match = false;
        }
    }
    return match;
}

main()
{
    vector<Point> original_points;
    for (int i = 0; i < 7; i++)
    {
        Point p{0, 0};
        cout << "Please input point #" << i + 1 << "'s X- and Y-values on separate lines:\n";
        cin >> p;
        original_points.push_back(p);
    }

    string file_name = "point_data.txt";
    write_to_file(original_points, file_name);

    vector<Point> processed_points;
    read_file(processed_points, file_name);

    cout << "\nOriginal Points:\n";
    print_points(original_points);

    cout << "\nProcessed Points:\n";
    print_points(processed_points);

    if (original_points != processed_points)
    {
        error("Points do not match.");
    }
    else
    {
        cout << "Points match.";
    }
    
}