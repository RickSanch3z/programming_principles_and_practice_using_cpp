void print_roots_quadratic(double a, double b, double c);

int main()
{
	try {
		print_roots_quadratic(10, 0.5, 0);
		
		return 0;
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		return -1;
	}
}

// Function name: print_roots_quadratic
// Function task: find real roots for quadratic equation with given coefficients
// Function parameter(s):
//		a: coefficient of the power 2, type double
//		b: coefficient of the power 1, type double
//		c: coefficient of the power 0, type double
// pre-conditions: 'a' can't be zero
void print_roots_quadratic(double a, double b, double c)
{	
	double x1 = 0.0;
	double x2 = x1;

	if (a == 0) {
		throw runtime_error("Coefficient 'a', for the power 2, can't be zero.\n");
	}
	if ((b * b - 4.0 * a * c) < 0.0)
		throw runtime_error("This equation has no real roots.\n");

	x1 = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
	x2 = (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
	cout << "Roots of the quadratic equation: " << a << "*x^2 + " << b << "*x + " << c << " = 0, are:\n";
	cout << "x1 = " << x1 << '\n';
	cout << "x2 = " << x2 << '\n';

	return;
}
