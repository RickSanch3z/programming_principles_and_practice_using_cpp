#include <std_lib_facilities.h>

// check is user input is correct. Also used to terminate the game
bool check_user_input(string);
// bot answer will be based on bots previous input if hard mode is selected or random if not or draw
string bot_answer(bool, bool, string);
// get a vector value index
int get_rps_vector_value_index(string);
// return int values: 0) draw; 1) user win; 2) bot win
int compare_answers(string, string);


vector<string> rps_vector = {"Rock", "Scissors", "Paper"};

int main()
{

    int user_score = 0;
    int bot_score = 0;
    int who_won = 0;
    string user_input = " ";
    // initialize bot input
    srand(time(NULL));
    string bot_input = rps_vector[rand() % 3];

    char hard_mode_choice = 'n';
    bool hard_mode = false;
    bool draw = false;
    bool end_game = false;

    cout << "Would you like the hard mode? \"y\" for yes and \"n\" for no.\n";
    cin >> hard_mode_choice;
    if (hard_mode_choice == 'y')
        hard_mode = true;
    else
        hard_mode = false;

    cout << "Please enter \"Rock\", \"Scissors\", or \"Paper\", respecting upper and lower cases.\n";
    cout << "Score is: User(" << user_score << "), Bot(" << bot_score << ").\n";
    do {
        cout << "Please enter your choice: ";
        cin >> user_input;

        if (check_user_input(user_input)) {
            who_won = compare_answers(user_input, bot_input);
            if (who_won == 0)
                draw = true;
            else if (who_won == 1)
                user_score++;
            else
                bot_score++;

            // announce both answer and score
            cout << "User input was: " << user_input << ". || Bot input was: " << bot_input << ".\n";
            cout << "Score is: User(" << user_score << "), Bot(" << bot_score << ").\n";
        } else {
            end_game = true;
        }

        // generate answer for the next round
        bot_input = bot_answer(hard_mode, draw, bot_input);
        draw = false;
    } while (!end_game);

    cout << "Final results are: User(" << user_score << "), Bot(" << bot_score << ").\n";

    return 0;
}

// check is user input is correct. Also used to terminate the game

bool check_user_input(string str)
{
    for (string str_t : rps_vector) {
        if (str_t == str) {
            return true;

        }
    }

    return false;
}

// bot answer will be based on bots previous input if hard mode is selected or random if not or draw
// bot answer based on behavior described here: https://www.youtube.com/watch?v=rudzYPHuewc

string bot_answer(bool h_mode, bool draw, string bot_previous_input)
{
    if (!h_mode || draw) {
        srand(time(NULL));
        return rps_vector[rand() % 3];
    } else {
        return rps_vector[(get_rps_vector_value_index(bot_previous_input) + 1) % 3];
    }
}

// get a vector value index

int get_rps_vector_value_index(string str)
{
    for (int i = 0; i < rps_vector.size(); ++i) {
        if (rps_vector[i] == str)
            return i;
    }
}

// return int values: 0) draw; 1) user win; 2) bot win

int compare_answers(string user_input, string bot_input)
{
    if (user_input == bot_input)
        return 0;

    if (user_input == "Rock") {
        if (bot_input == "Scissors")
            return 1;
        else
            return 2;
    } else if (user_input == "Scissors") {
        if (bot_input == "Paper")
            return 1;
        else
            return 2;
    } else if (user_input == "Paper") {
        if (bot_input == "Rock")
            return 1;
        else
            return 2;
    }
}
