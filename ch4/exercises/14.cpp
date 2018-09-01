/*
 * Finding primes from 1 through max using "The Sieve of Erastosthenes" method.
 * Information from: "An Introduction To Prime Numbers Sieves" by 
 * Jonathan Sorenson. Computer Sciences Technical Report #909. January 1990.
 */

#include <std_lib_facilities.h>

int main()
{
    int max = 0;

    cout << "Please enter a maximum limit to test primes through it: ";
    cin >> max;

    vector<int> initial_vector(max + 1);

    // make direct one-to-one relation of indexes of a vector and primes
    // zero and one directly excluded from further computation
    initial_vector[0] = initial_vector[1] = 0;
    // all next primes (indexes) will hold 1 indicating that they are candidates for being prime
    for (int i = 2; i <= max; ++i)
        initial_vector[i] = 1;

    int p = 2;

    // limit our main loop with p*p <= max, with p chanding in the main loop
    // in the case of max 100 maximum prime tested here will be 11 and loop will stop
    // 11 * 11 > 100, 7 * 7 < 100 (7 * 14 = 98 < 100 in the inner for loop).
    // There is no need to test all primes from 1 to max. When we reach 11 * 11 > 100
    // that's mean we've already eliminated all non-primes from 1 to max.
    while (int(pow(p, 2)) <= max) {
        // eliminate all multiples of p, starting with f=p*p and ending with f <= max/p
        for (int f = p; f <= max / p; ++f)
            initial_vector[p * f] = 0;

        do {
            p++;
        } while (!initial_vector[p]);
    }

    // print primes
    cout << "Primes from 1 to " << max << " are:\n";
    for (int i = 0; i < initial_vector.size(); ++i) {
        if (initial_vector[i] == 1)
            cout << i << " ";
    }

    return 0;
}
