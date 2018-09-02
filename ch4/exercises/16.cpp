#include <std_lib_facilities.h>

vector<int> get_modes(vector<int>);

int main()
{
    vector<int> input_vector;
    int integer_value = 0;

    cout << "Please enter a series of integer numbers separated by white space: \n";
    while (cin >> integer_value) {
        input_vector.push_back(integer_value);
    }
    
    cout << "The mode(s) is(are):\n";
    for (int temp : get_modes(input_vector))
        cout << temp << " ";
    
    cout << '\n';

    return 0;
}

vector<int> get_modes(vector<int> input_vector)
{
    int i = 0; // hold an index of the element under test
    int j = 1; // hold an index for the elements to compare to
    int count = 1; // repeated count time for an element under test
    int max_count = 1; // hold all time maximum count for a repeated element
    vector<int> return_vector;

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
    
    if (max_count == 1)
        return_vector.push_back(input_vector[input_vector.size() - 1]);
    
    return return_vector;
}
