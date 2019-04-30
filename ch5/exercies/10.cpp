vector<double> sum_first_n(void);

int main()
{
	try {
		vector<double> d_vector;

		d_vector = sum_first_n();
		for (double d : d_vector)
			cout << d << ' ';
		
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
// Function task: ask user the number (n) of elements
// and return a vector containing n - 1 differences between
// adjacent values
// Function parameter(s): empty
// pre-condition: empty
vector<double> sum_first_n(void)
{
	double value = 0;			// read elements here from 'cin'
	vector<double> double_vector;	// vector to hold readed elements
	vector<double> result_vector;
	int n = 0;				// number of elements to sum

	cout << "Please enter the number of values you want to sum:\n";
	cin >> n;
	if (n <= 0)
		throw runtime_error("Number of values to sum should be greather than 0.\n");

	cout << "Please enter some integers (press '|' to stop):\n";
	while (cin >> value) {
		double_vector.push_back(value);
	}

	if (double_vector.size() < n || double_vector.size() == 0)
		throw runtime_error("Insufficient number of elements to sum in the vector or an empty vector.\n");

	if (double_vector.size() == 1) {
		result_vector.push_back(double_vector[0]);

		return result_vector;
	}
	else if (n - 1 == 0) {
		result_vector.push_back(double_vector[1] - double_vector[0]);
		
		return result_vector;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			result_vector.push_back(double_vector[i + 1] - double_vector[i]);
		}

		return result_vector;
	}
}
