#include "../../std_lib_facilities.h.txt"

static const vector<string> nouns = {"bird", "fish", "C++"};
static const vector<string> verbs = {"rules", "flies", "swims"};
static const vector<string> joiners = {"and", "or", "but"};

bool is_in(string &word, vector<string> list)
{
    for (string item : list)
    {
        if (item == word)
        {
            return true;
        }
    }

    return false;
}

bool noun()
{
    string word;
    cin >> word;

    if (word == "the")
    {
        cin >> word;
        if (is_in(word, nouns))
        {
            return true;
        }
    }

    if (is_in(word, nouns))
    {
        return true;
    }

    return false;
}

bool verb()
{
    string word;
    cin >> word;

    if (is_in(word, verbs))
    {
        return true;
    }

    else
    {
        for (char c : word)
        {
            cin.putback(c);
        }
    }

    return false;
}

bool joiner()
{
    string word;
    cin >> word;

    if (is_in(word, joiners))
    {
        return true;
    }

    else
    {
        for (char c : word)
        {
            cin.putback(c);
        }
    }

    return false;
}

bool period()
{
    string word;
    cin >> word;

    if (word == ".")
    {
        return true;
    }

    return false;
}

bool sentence()
{
    if (!noun())
    {
        return false;
    }

    if (verb())
    {
        if (joiner())
        {
            if (!sentence())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    if (!period())
    {
        return false;
    }

    return true;
}

int main()
{
    try
    {
        while (cin)
        {
            cout << (sentence() ? "OK" : "NOT A SENTENCE") << "\n";
        }

        return 0;
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        keep_window_open("~1");
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open("~2");
        return 2;
    }
}