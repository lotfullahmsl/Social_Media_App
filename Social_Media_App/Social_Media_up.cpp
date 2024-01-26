#include <iostream>
#include <string>
using namespace std;

struct Sign_Up_struct {
	string name;
	string user_name;
	string password;
	string Year_of_Birth;
};

struct Sing_in_struct {
	string user_name;
	string password;
};

void Sign_up(Sign_Up_struct& sign_up_info);
void Sign_in(Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info);

int main() {
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;
	Sign_up(sign_up_info);
	Sign_in(Sign_in_info, sign_up_info);

}

void Sign_up(Sign_Up_struct& sign_up_info) {
	while (true)
	{
		cout << "Enter Your Full Name: ";
		getline(cin, sign_up_info.name);

		bool input_name = true;
		for (char letter : sign_up_info.name) {
			if (!isalpha(letter) && !isspace(letter)) {
				input_name = false;
				cout << "Name Can Be Just Alphabets";
				cout << endl;
				Sign_up(sign_up_info);
				break;
			}

		}
		if (input_name) {
			break;
		}
	}

	cout << "Enter Your User Name: ";
	getline(cin, sign_up_info.user_name);

	cout << "Enter Your Password: ";
	getline(cin, sign_up_info.password);

	while (true)
	{
		cout << "Enter Your Year of Birth: ";
		getline(cin, sign_up_info.Year_of_Birth);

		bool input_Year = true;
		for (char DOB : sign_up_info.Year_of_Birth) {
			if (!isdigit(DOB)) {
				input_Year = false;
				cout << "Year Should Be Only Digits, \nThere should be no space between digits! ";
				cout << endl;
				break;

			}
		}

		if (input_Year) {
			break;
		}


	}

	cout << "Press Enter To Continue to the log in Page...";
	cin.clear();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	cout << "Log In Succsefully Please Enter Log in to youe page\n";
}
void Sign_in(Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info) {

	cout << "Enter Your User Name: ";
	getline(cin, Sign_in_info.user_name);

	cout << "Enter Your Password: ";
	getline(cin, Sign_in_info.password);

	if (sign_up_info.user_name != Sign_in_info.user_name) {
		cout << "User Name is Not Matching\n";
	}

	if (sign_up_info.password != Sign_in_info.password) {
		cout << "Password is Not Matching";
	}

	if (sign_up_info.user_name == Sign_in_info.user_name && sign_up_info.password == Sign_in_info.password) {
		cout << "Correct!";
	}

}
