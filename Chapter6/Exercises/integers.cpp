#include "../../std_lib_facilities.h.txt"

static const string msg_to_big = "Your input is too large.";
static const string msg_digit = "Input must be an integer.";

static const vector<string> terms = {"one", "ten", "hundred", "thousand"};

bool input_checker(const string& input){
    if (input.length() > terms.size()){
        cerr << "input_checker(): " << msg_to_big << '\n';
        return false;
    }

    for (char c : input){
        if (c < '0' || c > '9'){
            cerr << "input_chekcer(): " << msg_digit << '\n';
            return false;
        }
    }

    return true;
}

vector<int> input_parser(const string& input){
    vector<int> parse;

    for (char c : input){
        parse.push_back(c - '0');
    }

    return parse;
}

void composer(const vector<int>& digits){
    int idx = digits.size() - 1;
    for (int d : digits){
        cout << d << ' ' << terms[idx] << ( d != 1 ? "s " : " ");
        idx--;
    }
}

int main(){
    try{
        string input;
        vector<int> digits;

        while(cin >> input){
            if (input_checker(input)){
                digits = input_parser(input);
                composer(digits);
            }
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