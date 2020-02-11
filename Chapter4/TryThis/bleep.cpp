#include "../cpptextbook/std_lib_facilities.h.txt"

int main()
{
    string to_bleep;
    cout << "What word do you dislike? ";
    cin >> to_bleep;

    cout << "What sentence would you like censored? (follow with 'enter' + ^Z + 'enter'): ";

    vector<string> new_sentence;
    for (string word; cin >> word;)
    {
        if (word != to_bleep)
        {
            new_sentence.push_back(word);
        }

        if (word == to_bleep)
        {
            new_sentence.push_back("BLEEP");
        }
    }

    cout << "Censored sentence: ";

    for (int i = 0; i < new_sentence.size(); i++)
    {
        cout << new_sentence[i] << " ";
    }

    return 0;
}