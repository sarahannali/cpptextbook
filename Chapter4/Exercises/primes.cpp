// Create a program to find all the prime numbers between 1 and 100.
// There is a classic method for doing this, called the “Sieve of Eratosthenes.”
// If you don’t know that method, get on the web and look it up.
// Write your program using this method.

#include "../cpptextbook/std_lib_facilities.h.txt"

int main()
{
    int max_num;
    cout << "Primes up to what number? ";
    cin >> max_num;

    int curr_prime = 2;
    vector<int> possible_primes;

    // vector of numbers to start:

    for (int i = 2; i <= max_num; i++)
    {
        possible_primes.push_back(i);
    }

    while (curr_prime <= max_num)
    {
        cout << "\n"
             << curr_prime;

        vector<int> new_possible_primes;

        for (int i = 0; i < possible_primes.size(); i++)
        {
            if (possible_primes[i] % curr_prime != 0)
            {
                new_possible_primes.push_back(possible_primes[i]);
            }
        }

        if (new_possible_primes.size() != 0)
        {
            curr_prime = new_possible_primes[0];
            possible_primes = new_possible_primes;
        }
        else
        {
            break;
        }
    }

    return 0;
}