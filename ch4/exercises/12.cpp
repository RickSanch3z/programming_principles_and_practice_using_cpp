#include <std_lib_facilities.h>

// test if integer is a prime number
bool is_prime(int);

// vector for holding primes
vector<int> primes;

int main()
{
    int max = 0;
    primes.push_back(2);    // the smallest prime number is 2
    
    cout << "Please enter a maximum limit to test primes through it: ";
    cin >> max; // ask user to enter a maximum limit to test through
    
    for (int i = 3; i <= max; ++i) {    // 0 and 1 is not primes, and 2 is already added
        if (is_prime(i))    // test if value is prime. And if it is add to the vector that holds primes
            primes.push_back(i);
    }
    
    // print primes from 1 to max limit included
    cout << "Primes from 1 to " << max << " are:\n";
    for (int i = 0; i < primes.size(); ++i) {
        cout << primes[i] << " ";
    }
    cout << '\n';

    return 0;
}

bool is_prime(int val)
{
    for (int i = 0; i < primes.size(); ++i) {
        if ((val % primes[i]) == 0) // is tested value is divided without reminder by smaller primes then value is not a prime
            return false;
    }

    return true;
}
