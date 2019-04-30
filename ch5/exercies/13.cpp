vector<int> random_vector(int length);
bool value_in_vector(vector<int> v, int value);
vector<int> read_digits(int length);
vector<int> n_of_bac(vector<int> v_to_g, vector<int> user_v);
void bulls_and_cows_game(void);

int main(void)
{
	try {
		bulls_and_cows_game();
	}
	catch (exception & e) {
		cout << "error: " << e.what() << '\n';
	}
	catch (...) {
		cout << "Other error.\n";
	}
}

// Function name: random_vector
// Function task: return a vector with a given length and containing random integer (different) values between 0 and 9
// Function parameter(s):
//		length: length of the vector, type int
// Function return type: vector<int>
// pre-condition: length of the vector should be between 1 and 10
vector<int> random_vector(int length)
{	
	vector<int> result_v;
	int random_value = 0;

	if (length > 10 || length < 1)
		throw runtime_error("Incorrect length of the vector in 'random_vector' function.\n");

	while (result_v.size() != length) {
		random_value = randint(9);
		if (!value_in_vector(result_v, random_value))
			result_v.push_back(random_value);
	}

	return result_v;
}

// Function name: value_in_vector
// Function task: return 'true' if a given value is present in the vector, otherwise return false
// Function parameter(s):
//		v: vector to proceed on, type vector<int>
//		value: value to search in vector, type int
// Funciton return type: bool
// pre-condition: empty
bool value_in_vector(vector<int> v, int value)
{
	for (int i = 0; i < v.size(); i++) {
		if (value == v[i])
			return true;
	}

	return false;
}

// Function name: raad_digits
// Function task: read a given number of integers and return them in one vector
// Function parameter(s):
//		length: number of elements to read, type int.
// Function return type: vector<int>
// pre-condition: length of the vector should be between 1 and 10
vector<int> read_digits(int length)
{
	vector<int> result_vector;
	int value;

	if (length > 10 || length < 1)
		throw runtime_error("Incorrect length of the vector in 'random_vector' function.\n");

	while ((result_vector.size() != length) && cin >> value) {
		if (value >= 10 || value < 0)
			throw runtime_error("From 'read_digits': Values should be between 0 and 10.\n");

		result_vector.push_back(value);
	}

	if (result_vector.size() != length)
		throw runtime_error("From 'read_digits': Wrong value type for the vector.\n");

	return result_vector;
}

// Function name: n_of_bac
// Function task: take two vectors and return a vector that holds number of occurrences of a given element 
// from one vector at the same index from another vector (Bull). And number of occurrences of a given element of one 
// vector in another vector at different index position (Cow).
// Function parameter(s):
//		v_to_g: first vector, type int
//		user_v: second vector, type int
// Function return type: vector int, index 0 holds Bulls, index 1 holds Cows
// pre-condition: two vectors should have the same length
vector<int> n_of_bac(vector<int> v_to_g, vector<int> user_v)
{
	vector<int> nofbac = { 0, 0 };

	if (v_to_g.size() != user_v.size())
		throw runtime_error("From 'n_of_bac': vector of differents sizes.\n");

	for (int i = 0; i < v_to_g.size(); i++) {
		if (v_to_g[i] == user_v[i])
			nofbac[0]++;
		else if (value_in_vector(user_v, v_to_g[i]))
			nofbac[1]++;
		else;
	}

	return nofbac;
}


// Function name: bulls_and_cows_game
// Function task: main function to start and run the game
// Function parameter(s): empty
// Function return type: empty
// pre-condition: empty
void bulls_and_cows_game(void)
{
	vector<int> vector_to_guess;
	vector<int> user_v;
	vector<int> nofbac;
	bool replay = true;
	bool won = false;
	string replay_s = "";
	int nd = 4;	// number of digits to guess
	int seed = 0;

	cout << "Give an integer (seed) for a randomizer.\n";
	if (cin >> seed)
		srand(seed);
	else
		throw runtime_error("Wrong type of seed was given.\n");

	while (replay) {
		cout << "Computer made a vector it's your turn to guess.\n";
		vector_to_guess = random_vector(nd);
		
		// print computer generated numbers. For test purposes only
		for (int x : vector_to_guess)
			cout << x << ' ';
		cout << '\n';

		while (!won) {
			cout << "Give " << nd << " digits each between 0 and 9.\n";
			user_v = read_digits(nd);
			nofbac = n_of_bac(vector_to_guess, user_v);

			if (nofbac[0] == nd) {
				cout << "You won!\n";
				won = true;
			}
			else {
				cout << "Number of bulls: " << nofbac[0] << '\n';
				cout << "Number of cows: " << nofbac[1] << '\n';
			}
		}

		cout << "Want to replay? Write 'yes' or 'no'.\n";
		cin >> replay_s;
		if (replay_s == "yes") {
			replay = true;
			won = false;
		}
		else if (replay_s == "no")
			replay = false;
		else
			throw runtime_error("From 'bulls_and_cows_game': wrong answer.\n");	
	}
}
