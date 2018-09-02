/*
 * Find roots of quadratic equation.
 * This solution works even if roots are complex conjugates.
 */

#include <std_lib_facilities.h>
#include <complex>

vector<complex<double>> roots(double, double, double);

int main()
{
    vector<complex<double>> roots_vector;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    cout << "This function will find square roots of quadratic equation "
            "of the form: ax^2 + bx + c\n";
    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    if (a == 0.0) {
        cout << "Constant \"a\" is equal to zero. Can't find roots. It's not a quadratic equation.\n";
    } else {
        roots_vector = roots(a, b, c);

        if (roots_vector[0].real() == 0.0) {
            cout << "Root of the quadratic equation are:\n";
            cout << "x1: " << roots_vector[0].real() << '\n';
            cout << "x2: " << roots_vector[1].real() << '\n';
        } else {
            cout << "Root of the quadratic equation are complex conjugate:\n";
            cout << "x1: " << roots_vector[0].real() << " + " << roots_vector[0].imag() << '\n';
            cout << "x2: " << roots_vector[1].real() << " + " << roots_vector[1].imag() << '\n';
        }
    }

    return 0;
}

vector<complex<double>> roots(double a, double b, double c)
{
    complex<double> x1(0.0, 0.0);
    complex<double> x2(0.0, 0.0);
    vector<complex<double>> return_vector;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        x1.real((-b + sqrt(discriminant)) / (2 * a));
        x2.real((-b + sqrt(discriminant)) / (2 * a));

        return_vector.push_back(x1);
        return_vector.push_back(x2);

        return return_vector;
    } else if (discriminant == 0.0) {
        x1.real(-b / (2 * a));
        x2.real(-b / (2 * a));

        return_vector.push_back(x1);
        return_vector.push_back(x2);

        return return_vector;
    } else {
        x1.real(-b / (2 * a));
        x1.imag(sqrt(abs(discriminant)) / (2 * a));
        x2.real(-b / (2 * a));
        x2.imag(-sqrt(abs(discriminant)) / (2 * a));

        return_vector.push_back(x1);
        return_vector.push_back(x2);

        return return_vector;
    }
}
