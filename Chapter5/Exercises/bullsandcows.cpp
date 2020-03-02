#include "../../std_lib_facilities.h.txt"

vector<int> create_ans()
{
    vector<int> ans(4);
    ans[0] = randint(10);
    ans[1] = randint(10);
    ans[2] = randint(10);
    ans[3] = randint(10);

    return ans;
}

vector<int> int_to_vec(int n)
{
    if (n > 9999 || n < 0)
    {
        error("number out of range");
    }
    vector<int> v_guess(4);
    v_guess[0] = n / 1000 % 10;
    v_guess[1] = n / 100 % 10;
    v_guess[2] = n / 10 % 10;
    v_guess[3] = n % 10;

    return v_guess;
}

vector<int> check_guess(vector<int> v_guess, vector<int> ans)
{
    vector<int> results(2);
    results[0] = 0;
    results[1] = 0;
    for (int i = 0; i < v_guess.size(); i++)
    {
        if (v_guess[i] == ans[i])
        {
            results[0] += 1;
        }
        else
        {
            for (int j = 0; j < ans.size(); j++)
            {
                if (v_guess[i] == ans[j])
                {
                    results[1] += 1;
                }
            }
        }
    }

    return results;
}

int main()
try {
    int seed;
    cout << "Enter a Number of Seed: ";
    cin >> seed;
    srand(seed);
    vector<int> ans = create_ans();

    int guess;
    cout << "Guess the number! (between 0 and 9999) ";

    while (cin >> guess)
    {
        vector<int> v_guess = int_to_vec(guess);
        vector<int> results = check_guess(v_guess, ans);
        if (results[0] == 4)
        {
            cout << "You Won!";
            break;
        }
        else
        {
            cout << "bulls: " << results[0] << "; cows: " << results[1];
            cout << "\nEnter a new guess: ";
        }
    }
}

catch (exception& e){
    cerr << "Error: " << e.what();
    return 1;
}
catch (...){
    cerr << "Unknown exception!\n";
    return 2;
}