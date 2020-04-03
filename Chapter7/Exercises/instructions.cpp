
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../../std_lib_facilities.h.txt"

struct Token
{
    char kind;
    double value;
    string name;
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n) : kind(ch), name(n) {} // return name
};

class Token_stream
{
    bool full;
    Token buffer;

public:
    Token_stream() : full(0), buffer(0) {}

    Token get();
    void unget(Token t)
    {
        buffer = t;
        full = true;
    }

    void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 's';
const char power = 'p';
const char help = 'h';

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch)
    {
    case quit:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
    case ',':
        return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.unget();
        double val;
        cin >> val;
        return Token(number, val);
    }
    default:
        if (isalpha(ch) || ch == '#')
        {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
            {
                s += ch;
            }
            cin.unget();
            if (s == "#")
            {
                return Token(let);
            }
            if (s == "exit")
            {
                return Token(quit);
            }
            if (s == "sqrt")
            {
                return Token(square_root);
            }
            if (s == "pow")
            {
                return Token(power);
            }
            if (s == "help" || s == "HELP")
            {
                return Token(help);
            }
            return Token(name, s);
        }
        error("Bad token");
        return 1;
    }
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin >> ch)
        if (ch == c)
            return;
}

struct Variable
{
    string name;
    double value;
    Variable(string n, double v) : name(n), value(v) {}
};

vector<Variable> names;

double get_value(string s)
{
    for (std::size_t i = 0; i < names.size(); ++i)
        if (names[i].name == s)
            return names[i].value;
    error("get: undefined name ", s);
    return 1;
}

void set_value(string s, double d)
{
    for (std::size_t i = 0; i <= names.size(); ++i)
        if (names[i].name == s)
        {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s)
{
    for (std::size_t i = 0; i < names.size(); ++i)
        if (names[i].name == s)
            return true;
    return false;
}

double define_name(string s, double num)
{
    if (is_declared(s))
    {
        error("is_declared(): ", s);
    }
    names.push_back(Variable(s, num));
    return num;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return d;
    }
    case '-':
        return -primary();
    case number:
        return t.value;
    case name:
        return get_value(t.name);
    case square_root:
    {
        double d = expression();
        if (d <= 0)
        {
            error("can't calculate sqrt of ", d);
        }
        return sqrt(d);
    }
    case power:
    {
        double d = expression();
        return d;
    }
    default:
        error("primary expected");
        return 1;
    }
}

double term()
{
    double left = primary();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        case ',':
        {
            int super_script = narrow_cast<int>(term());
            return pow(left, super_script);
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != 'a')
        error("name expected in declaration");
    string name = t.name;
    if (is_declared(name))
        error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ", name);
    double d = expression();
    names.push_back(Variable(name, d));
    return d;
}

void printInstructions()
{
    cout << "\n"
         << "Welcome to the calculator!"
         << "\n"
         << "You can use: + , - , * , / , pow() , sqrt()"
         << "\n"
         << "'>' means input, '=' means output. Use ';' for end of expression."
         << "\n"
         << "Define your own variables with '#'."
         << "\n";
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (true)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                return;
            if (t.kind == help)
                printInstructions();
            ts.unget(t);
            cout << result << statement() << endl;
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

int main()

try
{
    define_name("k", 1000);
    calculate();
    return 0;
}
catch (exception &e)
{
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >> c && c != ';')
        ;
    return 1;
}
catch (...)
{
    cerr << "exception\n";
    char c;
    while (cin >> c && c != ';')
        ;
    return 2;
}