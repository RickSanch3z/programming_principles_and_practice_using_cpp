#include <std_lib_facilities.h>

// function to check if string is contained in two vectors defined below.
// And if it is, return integer value of string representation
int check_string_get_value(string);

// initializing two strings. One for spelled digits and for visual representation \
of their integer type
vector<string> spelled_d = {"zero", "one", "two", "three", "four", "five", \
"six", "seven", "eight", "nine"};
vector<string> string_d = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main()
{

    // string for holding operands
    string op1 = " ";
    string op2 = " ";
    // double type for holding double type representation of string operands
    // double type here only for division part
    double dop1 = 0.0;
    double dop2 = 0.0;

    // a char for holding an operator
    char operator_v = ' ';

    cout << "Please enter two operands and operator separated by whitespace (op1 op2 operator).\n"
            "Operands could be spelled digits or numbers between 0 and 9.\n"
            "Valid operators are: +, -, *, /.\nPress Control+D to terminate the program.\n";

    while (cin >> op1 >> op2 >> operator_v) {
        if ((dop1 = check_string_get_value(op1)) > -1 && (dop2 = check_string_get_value(op2)) > -1) {
            switch (operator_v) {
            case '+':
                cout << "The sum of " << op1 << " and " << op2 << " is: " << (dop1 + dop2) << '\n';
                break;
            case '-':
                cout << "The difference of " << op1 << " and " << op2 << " is: " << (dop1 - dop2) << '\n';
                break;
            case '*':
                cout << "The product of " << op1 << " and " << op2 << " is: " << (dop1 * dop2) << '\n';
                break;
            case '/':
                if (dop2 == 0) {
                    cout << "You can't divide by zero.\n";
                    break;
                } else {
                    cout << "The division of " << op1 << " and " << op2 << " is: " << (dop1 / dop2) << '\n';
                    break;
                }
            default:
                cout << "Wrong operator.\n";
                break;
            }
        } else {
            cout << "Wrong operands.\n";
        }
        cout << "Please enter two operands and operator separated by whitespace (op1 op2 operator).\n"
                "Operands could be spelled digits or numbers between 0 and 9.\n"
                "Valid operators are: +, -, *, /.\nPress Control+D to terminate the program.\n";
    }



    return 0;
}

int check_string_get_value(string str)
{
    for (int i = 0; i < spelled_d.size(); ++i) {
        if (spelled_d[i] == str)
            return i;
    }

    for (int i = 0; i < string_d.size(); ++i) {
        if (string_d[i] == str)
            return i;
    }

    // is "str" is not in dictionary
    return -1;
}
