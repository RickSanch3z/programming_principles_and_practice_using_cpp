#include <std_lib_facilities.h>

// get min and max from vector of strings
vector<string> get_min_max(vector<string>);

// get mode(s) from vector of strings
vector<string> get_modes(vector<string>);

int main()
{
    vector<string> input_vector;
    vector<string> min_max;
    string input_string = " ";

    cout << "Please enter a series of strings separated by white space.\nTo end program press Control+D.\n";
    while (cin >> input_string) {
        input_vector.push_back(input_string);
    }
    
    min_max = get_min_max(input_vector);
    cout << "The min of the vector is: " << min_max[0] << '\n';
    cout << "The max of the vector is: " << min_max[1] << '\n';
    
    
    cout << "The mode(s) is(are):\n";
    for (string temp : get_modes(input_vector))
        cout << temp << " ";
    
    cout << '\n';

    return 0;
}


vector<string> get_min_max(vector<string> input_vector)
{
    string min = " ";
    string max = " ";
    vector<string> return_vector;
    
    if (input_vector.size() > 1)
        min = max = input_vector[0];
    
    for (string temp : input_vector) {
        if (temp > max)
            max = temp;
        else if (temp < min)
            min = temp;
    }
    
    return_vector.push_back(min);
    return_vector.push_back(max);
    
    return return_vector;
}
vector<string> get_modes(vector<string> input_vector)
{
    int i = 0; // hold an index of the element under test
    int j = 1; // hold an index for the elements to compare to
    int count = 1; // repeated count time for an element under test
    int max_count = 1; // hold all time maximum count for a repeated element
    vector<string> return_vector;

    // pre-sort elements
    sort(input_vector);

    // main loop to compare element under test against next elements in pre-sorted vector
    while (i < input_vector.size() - 1) {
        // test if next element is equal to element under test, and if so, increment count
        for (; (j < input_vector.size()) && (input_vector[i] == input_vector[j]); ++j) {
            ++count;
        }

        if (count == max_count)
            // check if count equal to all time maximum count, and if so push this element into the vector
            // we can have multiple modes if they all have same maximum number of apparition in the vector
            return_vector.push_back(input_vector[i]);
        else if (count > max_count) {
            // or if number of apparition of this element is greater
            // than max_count, clear the vector and add this element
            return_vector.clear();
            return_vector.push_back(input_vector[i]);
        }

        // if count is greater than max_count, new max_count take value of count
        if (count > max_count)
            max_count = count;
        
        // reset count
        count = 1;
        
        // index of the next element under test
        i = j++;
    }
    
    // check if we need to add the very last element in the case were every element is unique in the vector
    if (max_count == 1)
        return_vector.push_back(input_vector[input_vector.size() - 1]);
    
    return return_vector;
}
