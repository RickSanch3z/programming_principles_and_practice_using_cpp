/*
 * Set a name-value pair relation using two vectors. And make different search through them.
 * This file accumulate exercises 19, 20, and 21.
 */
#include <std_lib_facilities.h>

// check if names is already in the vector
// or if it is the terminating name "NoName"
int check_names(string);

// get a score for a given student name
// index 0 for indicating if student found, index 1 for his score if found
vector<int> get_score(string);

// get a list of students for a given score
// vector will be empty if no appropriate students are found
vector<string> get_names(int);

vector<string> names;
vector<int> scores;

int main()
{
    string name = " ";
    int score = 0;
    int c_name = 0;
    vector<int> get_score_vector;
    vector<string> get_names_vector;
    bool exit = false;

    do {
        cout << "Please enter name of the student followed by whitespace and the score: Name score\n";
        cin >> name >> score;

        c_name = check_names(name);

        if (c_name == 2) {
            names.push_back(name);
            scores.push_back(score);
        } else if (c_name == 1) {
            cout << "This name already exists.\n";
        } else {
            // this case executed when student name is "NoName"
            // this will terminate the program and whatever score was for "NoName" it will
            // be set to 0
            names.push_back(name);
            scores.push_back(0);
            exit = true;
        }
    } while (!exit);

    // print all students and their respective scores
    cout << "Now printing student names and relevant score, one student per line: \n";
    for (int i; i < names.size(); ++i)
        cout << names[i] << " : " << scores[i] << '\n';

    // print score for a given student name
    cout << "Please enter the name of the student to get his score: ";
    cin >> name;
    get_score_vector = get_score(name);
    if (get_score_vector[0] == 0) {
        cout << name << " score is: " << get_score_vector[1] << '\n';
    } else
        cout << "Name not found.\n";

    // print students names for a given score
    cout << "Please enter the score to find student(s): ";
    cin >> score;
    get_names_vector = get_names(score);
    if (!get_names_vector.empty()) {
        cout << "Students are: \n";
        for (string temp : get_names_vector)
            cout << temp << '\n';
    } else
        cout << "Score not found.\n";

    return 0;
}

int check_names(string name)
{
    if (name == "NoName")
        return 0; // code to terminate execution

    for (string temp : names) {
        if (temp == name)
            return 1; // code for error, name exist
    }

    return 2; // code to continue normal execution
}

vector<int> get_score(string name)
{
    vector<int> return_vector;

    for (int i = 0; i < names.size(); ++i)
        if (names[i] == name) {
            return_vector.push_back(0); // name is found at index 0
            return_vector.push_back(scores[i]); // score at index 1

            return return_vector;
        }

    return_vector.push_back(1); // code for name not found at index 0

    return return_vector;
}

vector<string> get_names(int score)
{
    vector<string> return_vector;

    for (int i = 0; i < scores.size(); ++i)
        if (scores[i] == score)
            return_vector.push_back(names[i]);

    return return_vector;
}
