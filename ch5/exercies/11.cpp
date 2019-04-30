void print_largest_fibonacci(void);

int main(void)
{
	print_largest_fibonacci();
}

// Function name: print_largest_fibonacci
// Function task: print largest fibonacci number that fits in an 'int' type
// Function parameter(s): empty
// pre-condition: empty
void print_largest_fibonacci(void)
{
	int fib_1 = 1;
	int fib_2 = 1;
	int fib_3 = 2;
	cout << fib_1 << '\n' << fib_2 << '\n';

	while (fib_3 > fib_1) {
		fib_3 = fib_1 + fib_2;
		fib_1 = fib_2;
		fib_2 = fib_3;
		cout << fib_3 << '\n';
	}

	cout << fib_1;
}
