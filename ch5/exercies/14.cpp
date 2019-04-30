const vector<vector<string>> days_of_week = { {"Monday", "monday", "Mo", "mo"}, {"Tuesday", "tuesday", "Tu", "tu"},
{"Wednesday", "wednesday", "We", "we"}, {"Thursday", "thursday", "Th", "th"}, {"Friday", "friday", "Fr", "fr"},
{"Saturday", "saturday", "Sa", "sa"}, {"Sunday", "sunday", "Su", "su"} };
const vector<string> days_const = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

vector<vector<int>> dofw(void);
int dofw_position(string day);
vector<int> sum_of_val(vector<vector<int>> v);
void print_values_of_days(vector<vector<int>> v);

int main(void)
{
	vector<vector<int>> days_values;
	vector<int> sum_days;

	cout << "Please enter 'day-name'-'integer value' pair bellow.\nTo end the program give non-integer or non-double value for 'integer value'.\n";

	days_values = dofw();
	print_values_of_days(days_values);
	sum_days = sum_of_val(days_values);

	for (int i = 0; i < sum_days.size() - 1; i++) { // sum_days.size() - 1, because last value contain number of times 'dofw' rejected name-value pair
		cout << "Sum of the values for " << days_const[i] << " is: " << sum_days[i] << ".\n";
	}

	cout << "Number of rejected values: \n";
	cout << days_values[7][0] << '\n';

	return 0;
}

// Function name: dofw (days of the week)
// Function task: take input in the form of days of the week and value pair separated by space.
// Could take multiple pairs on the same line.
// Function parameter(s): empty
// Function return type: vector<vector<int>>, each position of this vector correspond to a day of the week
// and vector at this position hold values for this day
// pre-condition: empty
vector<vector<int>> dofw(void)
{
	string day = "";
	int value = 0;
	vector<vector<int>> dofw_values = { {}, {}, {}, {}, {}, {}, {}, {0} };
	int dofw_index = -1;
	int rejected_v = 0;

	while (cin >> day >> value) {
		dofw_index = dofw_position(day);
		if (dofw_index != -1)
			dofw_values[dofw_index].push_back(value);
		else
			dofw_values[7] = { ++rejected_v };
	}
	return dofw_values;
}

// Function name: dofw_position, days of the week position
// Function task: take a string (name of the day) and return index position if 
// this string correspond to the name in the given vector that holds valid names (days_of_week)
// Function parameter(s):
//		day: name of the day, type string
// Function return type: int, index in the vector (days_of_week)
// pre-condition: empty
int dofw_position(string day)
{
	for (int i = 0; i < days_of_week.size(); i++)
		for (int j = 0; j < days_of_week[i].size(); j++) {
			if (days_of_week[i][j] == day)
				return i;
		}

	return -1;
}

// Function name: sum_of_val
// Function task: find sum of all values in a given vector
// Function parameter(s):
//		v: vector with each position correspodning a given day of the week, and each position holding
//		a vector of values for this day
// Function return type: vector<int>, vector with sum of values for each day (Monday - index 0, etc)
// pre-condition: empty
vector<int> sum_of_val(vector<vector<int>> v)
{
	int sum = 0;
	vector<int> result_v;

	for (int i = 0; i < v.size(); i++) {
		sum = 0;
		for (int x : v[i]) {
			sum += x;
		}
		result_v.push_back(sum);
	}

	return result_v;
}

// Function name: print_values_of_days
// Function task: print values for each day of the week
// Function parameter(s):
//		v: vector with each position correspodning a given day of the week, and each position holding
//		a vector of values for this day
// Function return type: empty
// pre-condition: empty
void print_values_of_days(vector<vector<int>> v)
{
	for (int i = 0; i < v.size() - 1; i++) { // v.size() - 1, because last value contain number of times 'dofw' rejected name-value pair
		cout << "Values for " << days_const[i] << '\n';
		for (int j : v[i])
			cout << j << ' ';
		cout << '\n';
	}
}
