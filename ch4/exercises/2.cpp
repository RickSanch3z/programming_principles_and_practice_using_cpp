/* 
Taking input as series of type double values (as temperatures)
and print the average and median values
*/
#include <std_lib_facilities.h>

int main()
{
    // compute mean and median temperatures
    vector<double> temps; // temperatures

    cout << "Enter temperatures values: ";
    for (double temp; cin >> temp;) // read into temp
        temps.push_back(temp); // put temp into vector

    // compute mean temperature:
    double sum = 0;
    for (int x : temps) sum += x;
    cout << "Average temperature: " << (sum / temps.size()) << '\n';

    // compute median temperature:
    sort(temps); // sort temperatures
    if ((temps.size() % 2) == 0) // check is size is even
        cout << "Median temperature: " << ((temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2);
    else
        cout << "Median temperature: " << temps[temps.size() / 2] << '\n';

    return 0;
}
