#include <std_lib_facilities.h>
#include <vector>
int disliked_words_test(string, vector<string>);

// check passing unit string if valid unit present in string vector
bool check_unit(string, vector<string>);

// return the conversion ratio from input string unit to meters
// Not flexible. Adapted only to this drill exercise and to "bool check_unit(string, vector<string>)"
double conversion_to_meters(string);

int main()
{
    double d1 = 0.0;
    double d2 = 0.0;
    double min = std::numeric_limits<double>::max();
    double max = -std::numeric_limits<double>::max();
    double sum = 0.0;
    int n_of_values = 0;
    string unit = " ";
    string max_unit = " ";
    string min_unit = " ";
    vector<string> units_v = {"cm", "m", "in", "ft"};
    vector<double> values_in_m;

    cout << "Please enter value and units of distance (value unit).\nEnter '|' to exit the program.\nUnits are 'cm', 'm', 'in', 'ft': ";
    while (cin >> d1 >> unit) {
        if (check_unit(unit, units_v)) {
            if ((d1 * conversion_to_meters(unit)) > max) { // compare values in meter units
                values_in_m.push_back(max = d1 * conversion_to_meters(unit)); // convert values to meters units and store in max and push it into vector
                max_unit = unit; // keep track of the max value unit
                sum += max; // sum valid values
                ++n_of_values; // keep track of numbers of valid values
                cout << d1 << " the largest so far.\n";
            } else if ((d1 * conversion_to_meters(unit)) < min) {
                //                min = d1 * conversion_to_meters(unit);
                values_in_m.push_back(min = d1 * conversion_to_meters(unit));
                min_unit = unit;
                sum += min;
                ++n_of_values;
                cout << d1 << " the smallest so far.\n";
            } else {
                values_in_m.push_back(d1 * conversion_to_meters(unit));
                sum += d1 * conversion_to_meters(unit);
                ++n_of_values;
            }
        } else {
            cout << "Please enter the correct unit type.\n";
        }


        cout << "Please enter value and units of distance (value unit).\nEnter '|' to exit the program.\nUnits are 'cm', 'm', 'in', 'ft': ";
    }

    sort(values_in_m);
    if (min != std::numeric_limits<double>::max())
        cout << "The smallest value is: " << (min / conversion_to_meters(min_unit)) << " " << min_unit << ".\n";

    if (max != -std::numeric_limits<double>::max())
        cout << "The largest value is: " << (max / conversion_to_meters(max_unit)) << " " << max_unit << ".\n";

    cout << "Total number of valid values is: " << n_of_values << ".\n";
    cout << "The values in meters are:\n";
    for (double temp : values_in_m)
        cout << temp << " ";

    cout << "\nThe sum of valid values in meters is: " << sum << ".\n";


    return 0;
}

bool check_unit(string unit, vector<string> units_v)
{
    for (string temp : units_v)
        if (unit == temp)
            return true;

    return false;
}

double conversion_to_meters(string unit)
{
    double cm_to_m = 0.01;
    double m_to_m = 1.0;
    double in_to_m = cm_to_m * 2.54;
    double ft_to_m = in_to_m * 12;

    if (unit == "cm")
        return cm_to_m;
    else if (unit == "m")
        return m_to_m;
    else if (unit == "in")
        return in_to_m;
    else if (unit == "ft")
        return ft_to_m;
    else
        return -std::numeric_limits<double>::max();
}
