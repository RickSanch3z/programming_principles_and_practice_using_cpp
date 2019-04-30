constexpr double ABSOLUTE_ZERO_C = -273.15;
constexpr double ABSOLUTE_ZERO_K = 0.0;
constexpr double ABSOLUTE_ZERO_F = -459.67;
double ctok(double c);
double ktoc(double k);
double ctof(double c);
double ftoc(double f);

int main()
{
	try {
		double c = 0;
		double k = 0;
		double f = 0;

		cin >> c;
		if (!cin)
			throw runtime_error("Wrong input.\n");

		k = ctok(c);
		cout << k << '\n';
		cout << ktoc(k) << '\n';
		f = ctof(c);
		cout << f << '\n';
		cout << ftoc(f) << '\n';

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

// Function name: ctok
// Function task: convert degree from Celsius to Kelvin
// Function parameter(s):
//		c: degree in Celsius, type double
// pre-conditions: 'c' should be greather or equal to -273.15
double ctok(double c)
{
	double k = 0.0;
	if (c < ABSOLUTE_ZERO_C)
		throw runtime_error("Degree in Celsius should be greather or equal to -273.15.\n");

	return k = c - ABSOLUTE_ZERO_C;
}

// Function name: ktoc
// Function taks: convert degree from Kelvin to Celsius
// Function parameter(s):
//		k: degree in Kevin, type double
// pre-coditions: 'k' should be equal or greather than 0
double ktoc(double k)
{
	double c = 0.0;
	if (k < ABSOLUTE_ZERO_K)
		throw runtime_error("Degree in Kevin should be greather or equal to 0.\n");

	return c = k + ABSOLUTE_ZERO_C;
}

// Function name: ctof
// Function task: convert degree from Celsius to Fahrenheit
// Function parameter(s):
//		c: degree in Celsius, type double
// pre-conditions: 'c' should be greather or equal to -273.15
double ctof(double c)
{
	double f = 0.0;
	if (c < ABSOLUTE_ZERO_C)
		throw runtime_error("Degree in Celsius should be greather or equal to -273.15.\n");

	return f = c * 9.0 / 5.0 + 32.0;
}

// Function name: ftoc
// Function task: convert degree from Fahrenheit to Celsius
// Function parameter(s):
//		f: degree in Fahrenheit, type double
// pre-conditions: 'f' should be greather or equal to -273.15
double ftoc(double f)
{
	double c = 0.0;
	if (f < ABSOLUTE_ZERO_F)
		throw runtime_error("Degree in Fahrenheit should be greather or equal to -459.67\n");

	return c = (f - 32.0) * 5.0 / 9.0;
}
