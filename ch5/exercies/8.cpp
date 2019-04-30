int sum_first_n(void);

int main()
{
	try {
		int sum = 0;

		sum = sum_first_n();
		cout << sum;
		
		return 0;
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		return -1;
	}
	catch (...) {
		cerr << "Other errors.\n";
		return -1;
	}
}

// Function name: sum_first_n
// Function task: ask user the number of first elements to sum
// and read a series of elements
// Function parameter(s): empty
// pre-condition: empty
int sum_first_n(void)
{
	int sum = 0;			// sum of the first n elements
	int value = 0;			// read elements here from 'cin'
	vector<int> int_vector;	// vector to hold readed elements
	int n = 0;				// number of elements to sum

	cout << "Please enter the number of values you want to sum:\n";
	cin >> n;
	if (n <= 0)
		throw runtime_error("Number of values to sum should be greather than 0.\n");

	cout << "Please enter some integers (press '|' to stop):\n";
	while (cin >> value) {
		int_vector.push_back(value);
	}

	if (int_vector.size() < n || int_vector.size() == 0)
		throw runtime_error("Insufficient number of elements to sum in the vector or an empty vector.\n");

	for (int i = 0; i < n; i++)
		sum += int_vector[i];

	return sum;
}
