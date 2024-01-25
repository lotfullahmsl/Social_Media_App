#include <iostream>
#include <string>
using namespace std;

struct Sign_Up_struct {
	string name;
	string user_name;
	string password;
	string Year_of_Birth;
};

void Sign_up() {
	Sign_Up_struct sign_up_info;
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
				Sign_up();
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
		for (int DOB : sign_up_info.Year_of_Birth) {
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
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {

	Sign_up();
}