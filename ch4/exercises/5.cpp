/*
Primitive calculator.
*/
#include <std_lib_facilities.h>

int main()
{
    double op1 = 0.0;
    double op2 = 0.0;
    char operator_v = ' ';
    
    // inform user how to proceed and use program
    cout << "Please enter two operands and operator separated by whitespace (op1 op2 operator).\n"
            "Valid operators are: +, -, *, /.\nInvalid values for operand should terminate the program.\n";
    
    while (cin >> op1 >> op2 >> operator_v) { // take two operands and an operator as input
        switch(operator_v) {                  // check operator and select coherent case
        case '+':
            cout << "The sum of " << op1 << " and " << op2 << " is: " << (op1 + op2) << '\n';
            break;
        case '-':
            cout << "The difference of " << op1 << " and " << op2 << " is: " << (op1 - op2) << '\n';
            break;
        case '*':
            cout << "The product of " << op1 << " and " << op2 << " is: " << (op1 * op2) << '\n';
            break;
        case '/':
            if (op2 == 0) {                   // check if we dividing by zero
                cout << "You can't divide by zero.\n";
                break;
            }
            else {
                cout << "The division of " << op1 << " and " << op2 << " is: " << (op1 / op2) << '\n';
                break;
            }
        default:                              // wrong operator case
            cout << "Wrong operator.\n";
            break;
        }
        
            cout << "\nPlease enter two operands and operator separated by whitespace (op1 op2 operator).\n"
            "Valid operators are: +, -, *, /.\nInvalid values for operand should terminate the program.\n";
    }

    
    return 0;
}
