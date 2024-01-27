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

struct Profile_struct {
	string name;
	string YOB;
	string hobbies;
	string bio;
	string loctaion_city;

};


void Checking_Profile(const Profile_struct profile, string &bio_choise);
void Creating_Profile(Profile_struct& profile, string &bio_choise);
void Sign_up(Sign_Up_struct& sign_up_info);
void Sign_in(Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info);

int main() {
	string bio_choise ;
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;
	Profile_struct profile;
	char menu_choise;

	cout << "\t\t\t\t\t\tWelcome to Update World!\n";

	Sign_up(sign_up_info);
	Sign_in(Sign_in_info, sign_up_info);
	Creating_Profile(profile, bio_choise);
	cout << "Profile has been succesfully Created!";

	cout << "\nMain Menu \n1.Check Profile\nYour Choise: ";
	cin >> menu_choise;
	switch (menu_choise)
	{
	case '1':
		Checking_Profile(profile, bio_choise);
		break;
	}
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
	cout << "Sign Up Succsefully Please Enter Log in to youe page...\n";
}


void Sign_in(Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info) {
	while (true)
	{
		cout << "Enter Your User Name: ";
		getline(cin, Sign_in_info.user_name);

		cout << "Enter Your Password: ";
		getline(cin, Sign_in_info.password);
		if (sign_up_info.user_name != Sign_in_info.user_name) {
			cout << "User Name is Not Matching\n";
		}

		if (sign_up_info.password != Sign_in_info.password) {
			cout << "Password is Not Matching\n";
		}

		if (sign_up_info.user_name == Sign_in_info.user_name && sign_up_info.password == Sign_in_info.password) {
			system("cls");
			cout << "You Have Succsesfully Loged in\n";
			cout << "TO Continue the App you Should Creat Profile. Press Enter...";
			break;
		}
	}
	

}


void Creating_Profile(Profile_struct& profile, string &bio_choise) {

	while (true)
	{
		cin.ignore();
		cout << "Enter Your Full Name: ";
		getline(cin, profile.name);

		bool input_name = true;
		for (char letter : profile.name) {
			if (!isalpha(letter) && !isspace(letter)) {
				input_name = false;
				cout << "Name Can Be Just Alphabets";
				cout << endl;
				Creating_Profile(profile, bio_choise);
				break;
			}

		}
		if (input_name) {
			break;
		}
	}

	while (true)
	{
		cout << "Enter Your Location: ";
		getline(cin, profile.loctaion_city);

		bool input_name = true;
		for (char letter : profile.loctaion_city) {
			if (!isalpha(letter) && !isspace(letter)) {
				input_name = false;
				cout << "location Can Be Just Alphabets";
				cout << endl;
				break;
			}

		}
		if (input_name) {
			break;
		}
	}

	cout << "Do you want to enter your bio (Y/y): ";
	getline(cin, bio_choise);

	if (bio_choise == "Y" || bio_choise == "y") {
		cout << "Enter Your bio: ";
		getline(cin, profile.bio);
	}
	else {

	}

	

		cout << "Enter Your Hobbie: ";
		getline(cin, profile.hobbies);

	
	


	while (true)
	{
		cout << "Enter Your Year of Birth: ";
		getline(cin, profile.YOB);

		bool input_Year = true;
		for (char DOB : profile.YOB) {
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

	cout << "Profile has been created...";
	cin.clear();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");

}

void Checking_Profile(const Profile_struct profile, string &bio_choise) {

	cout << "Your Full name is " << profile.name;
	cout << endl;

	cout << "Your Location is " << profile.loctaion_city;
	cout << endl;

	cout << "Your Year of Birth is " << profile.YOB;
	cout << endl;

	if (bio_choise == "y" || bio_choise == "Y") {
		cout << "Your Bio is " << profile.bio;
		cout << endl;
	}
}