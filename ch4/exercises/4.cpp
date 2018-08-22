#include <std_lib_facilities.h>

int main()
{
    int user_number = 0;
    int min = 1;
    int max = 100;
    int less_more = 0; // used to alter questions: less or more?
    string answer = " ";

    // ask user to enter number to guess
    cout << "Please enter the integer number between " << min << " and " << max << ": ";
    cin >> user_number;
    cout << '\n';
    cout << "Answer with \"y\" to yes or \"n\" to no.\n";

    for (int i = 0; i < 7; ++i) {
        if (min != max) { // if min and max are equal number is guessed. No need to ask for further questions
            if ((less_more % 2) == 0) {
                cout << "Is the number you are thinking of less than " << ((max + min) / 2) << "?\n";
                cin >> answer;
                less_more++;

                if (answer == "y") {
                    max = ((max + min) / 2) - 1;
                    min = min;
                } else if (answer == "n") {
                    max = max;
                    min = (max + min) / 2;
                }
            } else {
                cout << "Is the number you are thinking of more than " << ((max + min) / 2) << "?\n";
                cin >> answer;
                less_more++;

                if (answer == "y") {
                    max = max;
                    min = ((max + min) / 2) + 1;
                } else if (answer == "n") {
                    max = (max + min) / 2;
                    min = min;
                }
            }
        }
    }

    if (min == max)
        cout << "Your number is: " << min << '\n';
    else
        cout << "Sorry, I'm failed to guess.\n";


    return 0;
}
