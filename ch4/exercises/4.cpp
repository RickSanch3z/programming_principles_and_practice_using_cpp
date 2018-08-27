/*
Number guessing game.
User input number between 1 and 100 and program use questions to find the number.
*/
#include <std_lib_facilities.h>

int main()
{
    int user_number = 0;
    int min = 1;
    int max = 1000;
    int less_more = 0; // used to alter questions: less or more?
    string answer = " ";

    // ask user to enter number to guess
    cout << "Please enter the integer number between " << min << " and " << max << ": ";
    cin >> user_number;
    cout << '\n';
    cout << "Answer with \"y\" to yes or \"n\" to no.\n";

    for (int i = 0; i < 10; ++i) {
        if ((max - min) != 1 && max != min) { // if they differ by one execute an alternative case
            if ((less_more % 2) == 0) {
                cout << "Is the number you are thinking of less than " << ((min + max) / 2) << "?\n";
                cin >> answer;
                less_more++;

                if (answer == "y") {
                    max = (min + max) / 2 - 1;
                    min = min;
                } else if (answer == "n") {
                    max = max;
                    min = (min + max) / 2;
                }
            } else {
                cout << "Is the number you are thinking of more than " << ((min + max) / 2) << "?\n";
                cin >> answer;
                less_more++;

                if (answer == "y") {
                    max = max;
                    min = (min + max) / 2 + 1;
                } else if (answer == "n") {
                    max = (min + max) / 2;
                    min = min;
                }
            }
        } else if (max != min) { // alternative case
            cout << "Is the number you are thinking of more than " << min << "?\n";
            cin >> answer;

            if (answer == "y")
                min = max;
            else if (answer == "n")
                max = min;
        }
    }

    if (min == max)
        cout << "Your number is: " << min << '\n';
    else
        cout << "Sorry, I'm failed to guess. Your number was: " << user_number<< '\n';

    return 0;
}
