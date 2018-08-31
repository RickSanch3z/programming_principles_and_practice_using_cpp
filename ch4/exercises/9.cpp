#include <std_lib_facilities.h>

int main()
{
    int square = 1;
    int c_n_of_grains = 1;
    int t_n_of_grains = 1;
    double d_t_n_of_grains = 1.0;


    for (; t_n_of_grains > 0; ++square) {
        c_n_of_grains *= 2;
        t_n_of_grains += c_n_of_grains;
    }

    --square;   // decrease number of squares because the last one gave the negative result
    c_n_of_grains = 1;
    t_n_of_grains = 1;
    for (int i = 1; i <= square; ++i) {
        if (i == 1) {
        } else {
            c_n_of_grains *= 2;
            t_n_of_grains += c_n_of_grains;
        }
    }
    cout << "The largest number of squares for which we can calculate exact number of grains (int) is: " << square << \
" and the number of grains is: " << t_n_of_grains << '\n';

    c_n_of_grains = 1;
    square = 1;
    for (; d_t_n_of_grains > 0; ++square) {
        c_n_of_grains *= 2;
        d_t_n_of_grains += c_n_of_grains;
    }

    --square;   // decrease number of squares because the last one gave the negative result
    c_n_of_grains = 1;
    d_t_n_of_grains = 1;
    for (int i = 1; i <= square; ++i) {
        if (i == 1) {
        } else {
            c_n_of_grains *= 2;
            d_t_n_of_grains += c_n_of_grains;
        }
    }
    cout << "The largest number of squares for which we can calculate exact number of grains (double) is: " << square << \
" and the number of grains is: " << d_t_n_of_grains << '\n';


    return 0;
}
