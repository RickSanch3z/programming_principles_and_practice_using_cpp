#include <std_lib_facilities.h>

bool is_prime(int);

vector<int> primes;

int main()
{
    int max = 0;
    primes.push_back(2);
    
    cout << "Please enter a maximum limit to test primes through it: ";
    cin >> max;
    
    for (int i = 3; i <= max; ++i) {    // 0 and 1 is not primes, and 2 is already added
        if (is_prime(i))
            primes.push_back(i);
    }
    
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
        if ((val % primes[i]) == 0)
            return false;
    }

    return true;
}
