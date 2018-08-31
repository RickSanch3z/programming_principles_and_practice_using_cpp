#include <std_lib_facilities.h>

int main()
{
    int square = 1;
    int c_n_of_grains = 1;
    int t_n_of_grains = 1;
    int limit_grains = 0;
    
    cout << "Please enter the number of grains required, at least.\n";
    cin >> limit_grains;
    if (limit_grains < 1)
        square = 0;
    
    for (; t_n_of_grains < limit_grains; ++square) {
        c_n_of_grains *= 2;
        t_n_of_grains += c_n_of_grains;
    }
    
    cout << "The total number of squares required to get at least " << limit_grains << " of grains are: " << square << " squares.\n";
    
    
    return 0;
}
