#include <std_lib_facilities.h>

// return total distance
double total_distance(vector<double>);
// return smallest (index 0) and greatest (index 1) distances
vector<double> s_and_g_distances(vector<double>);

int main()
{
    vector<double> distances;
    vector<double> s_and_g_distances_vector;

    cout << "Please enter the distances between cities: ";
    for (double temp; cin >> temp;)
        distances.push_back(temp);

    cout << "The total distance is: " << total_distance(distances) << '\n';

    s_and_g_distances_vector = s_and_g_distances(distances);
    cout << "The smallest distance is: " << s_and_g_distances_vector[0] << ". The greatest distance is: \
    " << s_and_g_distances_vector[1] << '\n';

    if (distances.size() > 0)
        cout << "The mean distance between two cities is: " << (total_distance(distances) / distances.size()) << ".\n";
    else
        cout << "The mean distance between two cities is: 0\n";
    
    return 0;
}

double total_distance(vector<double> distances)
{
    double r_value = 0.0;

    for (double temp : distances)
        r_value += temp;

    return r_value;
}

vector<double> s_and_g_distances(vector<double> distances)
{
    vector<double> r_vector;
    double min = 0.0;
    double max = 0.0;

    if (distances.size() > 0) {
        min = max = distances[0];

        for (double temp : distances) {
            if (temp > max)
                max = temp;
            else if (temp < min)
                min = temp;
            else;
        }
    }

    r_vector.push_back(min);
    r_vector.push_back(max);

    return r_vector;
}
