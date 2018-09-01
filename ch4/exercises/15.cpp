/*
 * Print n first primes.
 */

#include <std_lib_facilities.h>

// test if integer is a prime number
bool is_prime(int);

// vector for holding primes
vector<int> primes;

int main()
{
    int n = 0; // user input
    int n_var = 0; // actual primes number

    cout << "Please enter a number of first primes to print: ";
    cin >> n; // ask user to enter a maximum limit to test through
    primes.push_back(2); // the smallest prime number is 2
    n_var++;

    for (int i = 3; n_var < n; ++n_var) { // 0 and 1 is not primes, and 2 is already added
        for (; !is_prime(i); ++i); // skip next non-primes

        primes.push_back(i++);
    }

    // print primes from 1 to max limit included
    if (n == 0)
        cout << "No primes to print.\n";
    else {
        cout << n << " first primes are:\n";
        for (int i = 0; i < primes.size(); ++i) {
            cout << primes[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}

bool is_prime(int val)
{
    for (int i = 0; i < primes.size(); ++i) {
        if ((val % primes[i]) == 0) // if tested value is divided without reminder by smaller primes then value is not a prime
            return false;
    }

    return true;
}
