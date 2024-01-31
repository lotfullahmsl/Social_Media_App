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

void Sign_up(Sign_Up_struct& sign_up_info);
void Sign_in(Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info);
void Creating_Profile(Profile_struct& profile, string& bio_choise);
void Checking_Profile(const Profile_struct profile, string &bio_choise);
void Main_menu(Profile_struct& profile, string& bio_choise, string idea, Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info);
void Editing_Profile(Profile_struct& profile, string& bio_choise);
void Post_Array(Profile_struct& profile, string& bio_chois, string idea);
void Watching_Post(Profile_struct& profile,  string idea);
void Sign_Out(Sing_in_struct Sign_in_info, Sign_Up_struct sign_up_info);


int main() {
	string bio_choise, idea ;
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;
	Profile_struct profile;
	

	cout << "\t\t\t\t\t\t(Welcome to Update World)\n";
	cout << "Please Register to Access the App.\n\n";

	Sign_up(sign_up_info);
	Sign_in(Sign_in_info, sign_up_info);
	Creating_Profile(profile, bio_choise);
	cout << "\nPress Enter To Continue...";
	Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);

}


void Sign_up(Sign_Up_struct& sign_up_info) {
	do {
		while (true)
		{
			cout << "Your Full Name: ";
			getline(cin, sign_up_info.name);

			bool input_name = true;
			for (char letter : sign_up_info.name) {
				if (!isalpha(letter) && !isspace(letter)) {
					input_name = false;
					cout << "Please Enter Only Letters in the Name Field.";
					cout << endl;
	
					break;
				}

			}
			if (input_name) {
				break;
			}
		}
		if (sign_up_info.name.empty()) {
			cout << "The Name Field is Required.\n";
		}
	} while (sign_up_info.name.empty());

	do {
		cout << "Your User Name: ";
		getline(cin, sign_up_info.user_name);
		if (sign_up_info.user_name.empty()) {
			cout << "User Name Field is Required\n";
		}
	} while (sign_up_info.user_name.empty());

	do {
		cout << "Your Password: ";
		getline(cin, sign_up_info.password);
		if (sign_up_info.password.empty()) {
			cout << "Password is Required\n";
		}
	} while (sign_up_info.password.empty());
	
	do {
		while (true)
		{
			cout << "Enter Your Year of Birth: ";
			getline(cin, sign_up_info.Year_of_Birth);

			bool input_Year = true;
			for (char DOB : sign_up_info.Year_of_Birth) {
				if (!isdigit(DOB)) {
					input_Year = false;
					cout << "Please Enter the Year in Numeric Format Only. \nDigits Must Be Entered Without Spaces.";
					cout << endl;
					break;

				}

			}
			if (sign_up_info.Year_of_Birth.empty()) {
				cout << "Year of Birth is Required!\n";
			}
			if (input_Year) {
				break;
			}
			

		}
	} while (sign_up_info.Year_of_Birth.empty());

		cout << "Press Enter To Continue to the log in Page...";
		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "Sign Up Successfully! Please Log in to Your Page.\n";
		
	}
		
	

void Sign_in(Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info) {
	while (true)
	{

		do {
			cout << "Your User Name: ";
			getline(cin, Sign_in_info.user_name);
			if (Sign_in_info.user_name.empty()) {
				cout << "User Name is Required\n";
			}
		} while (Sign_in_info.user_name.empty());

		do {
			cout << "Your Password: ";
			getline(cin, Sign_in_info.password);
			if (Sign_in_info.password.empty()) {
				cout << "Password is Required\n";
			}
		} while (Sign_in_info.password.empty());
		if (sign_up_info.user_name != Sign_in_info.user_name) {
			cout << "Incorrect User Name\n";
		}

		if (sign_up_info.password != Sign_in_info.password) {
			cout << "Incorrect Password\n";
		}

		if (sign_up_info.user_name == Sign_in_info.user_name && sign_up_info.password == Sign_in_info.password) {
			system("cls");
			cout << "Login Successful! Welcome to Update World.\n";
			cout << "To Continue Using the App, Please Create Your Profile.";
			break;
		}
	}
	

}


void Creating_Profile(Profile_struct& profile, string &bio_choise) {
	do {
		while (true)
		{
			
			cout << "\nYour Full Name: ";
			getline(cin, profile.name);
			bool input_name = true;
			for (char letter : profile.name) {
				if (!isalpha(letter) && !isspace(letter)) {
					input_name = false;
					cout << "Please Enter Only Letters in the Name Field.";
					cout << endl;
					break;
				}

			}
			if (input_name) {
				break;
			}
		}
		if (profile.name.empty()) {
			cout << "Name Field is Required\n";
			
		}
	} while (profile.name.empty());

	do {
		while (true)
		{
			cout << "Enter Your Location: ";
			getline(cin, profile.loctaion_city);

			bool input_name = true;
			for (char letter : profile.loctaion_city) {
				if (!isalpha(letter) && !isspace(letter)) {
					input_name = false;
					cout << "Please Enter Only Letters in the Location Field.";
					cout << endl;
					break;
				}

			}
			if (input_name) {
				break;
			}
		}
		if (profile.loctaion_city.empty()) {
			cout << "For Your Security You Should Add Your Location\n";
		}
	} while (profile.loctaion_city.empty());

	do {
		cout << "Do you want to enter your bio (y/n): ";
		getline(cin, bio_choise);
		if (bio_choise.empty()) {
			cout << "Please Press Y or any other Key!\n";
		}
	} while (bio_choise.empty());
	if (bio_choise == "Y" || bio_choise == "y") {
		do {
			cout << "Enter Your bio: ";
			getline(cin, profile.bio);
			if (profile.bio.empty()) {
				cout << "You Chosed To Add Bio. Now You Cant Change Your Decision!\n";
			}
		} while (profile.bio.empty());
	}
	else {

	}
	do {
		cout << "Enter Your Hobbie: ";
		getline(cin, profile.hobbies);

		if (profile.hobbies.empty()) {
			cout << "\nFor Better Experince Please Add Your Hobbies";
		}

	} while (profile.hobbies.empty());
	do {
		while (true)
		{
			cout << "Enter Your Year of Birth: ";
			getline(cin, profile.YOB);

			bool input_Year = true;
			for (char DOB : profile.YOB) {
				if (!isdigit(DOB)) {
					input_Year = false;
					cout << "Please Enter the Year in Numeric Format Only. \nDigits Must Be Entered Without Spaces.";
					cout << endl;
					break;

				}
			}

			if (input_Year) {
				break;
			}


		}
		if (profile.YOB.empty()) {
			cout << "Age is Required!\n";
		}
	} while (profile.YOB.empty());
	system("cls");
	cout << "Profile has been Succsefully Created\n";
	cin.clear();
	

}

void Checking_Profile(Profile_struct profile, string &bio_choise) {
	string idea;
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;
	system("cls");
	cout << endl;
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

	cout << "your hobbies are " << profile.hobbies;
	cout << endl;
	cout << "Press Enter To Continue...";
	Main_menu (profile, bio_choise, idea, Sign_in_info, sign_up_info);

}

void Main_menu(Profile_struct& profile, string& bio_choise, string idea, Sing_in_struct& Sign_in_info, Sign_Up_struct& sign_up_info) {
	string menu_choise;

	do {
		
		cin.ignore();
		cout << "\nMain Menu \n1.Check Profile\n2.Editing Profile \n3.Creat a Post \n4.Watching Post \n5.Log out \n6.Exit the Program\nYour Choise: ";
		getline(cin, menu_choise);

		if (menu_choise == "1") {
			Checking_Profile(profile, bio_choise);
			break;
		}
		else if (menu_choise == "2") {
			Editing_Profile(profile, bio_choise);
			break;
		}
		else if (menu_choise == "3") {
			Post_Array(profile, bio_choise, idea);
			break;
		}
		else if (menu_choise == "4") {
			Watching_Post(profile, idea);
			break;
		}
		else if (menu_choise == "5") {
			Sign_Out(Sign_in_info, sign_up_info);
		}
		else if (menu_choise == "6") {
			cout << "\nProgram Exited\n";

			exit;
		}
		else if (menu_choise.empty()) {

			cout << "Please Make a choise\n";
			cout << "Press Enter...";
		}

		
	} while (menu_choise.empty());
	

}

void Editing_Profile(Profile_struct& profile, string& bio_choise) {
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;
	string idea;
	Creating_Profile(profile, bio_choise);
	Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);

}

void Post_Array(Profile_struct& profile, string& bio_chois, string idea) {
	string bio_choise = "";
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;

	cout << "Tell us what's new in your world! \nYour idea: ";
	getline(cin, idea);
	if (idea.empty()) {
		cout << "Empty Post!\n";
		Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);
	}
	cout << "you have did a post!";
	Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);
	
}

void Watching_Post(Profile_struct& profile, string idea) {
	Sign_Up_struct sign_up_info;
	Sing_in_struct Sign_in_info;
	string bio_choise = "";
	bool e_post = true;
	for (char empty_post : idea) {
		if (isspace(empty_post)) {
			e_post = false;
			cout << "\nYou havent make any post\n";
			cout << "Press Enter...";
			Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);
			break;
		}
	}
	if (idea.empty()) {
		cout << "\nYou havent make any post\n";
		cout << "Press Enter...";
		Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);
		}
	 {
		cout << "You have Posted: " << idea << endl;
		cout << "Author of the Post is: " << profile.name << endl;
		cout << "Press Enter...";
		Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);
	}
}
void Sign_Out(Sing_in_struct Sign_in_info, Sign_Up_struct sign_up_info) {
	string idea;
	string bio_choise;
	Profile_struct profile;
	while (true)
	{

		do {
			cout << "Your User Name: ";
			getline(cin, Sign_in_info.user_name);
			if (Sign_in_info.user_name.empty()) {
				cout << "User Name is Required\n";
			}
		} while (Sign_in_info.user_name.empty());

		do {
			cout << "Your Password: ";
			getline(cin, Sign_in_info.password);
			if (Sign_in_info.password.empty()) {
				cout << "Password is Required\n";
			}
		} while (Sign_in_info.password.empty());
		if (sign_up_info.user_name != Sign_in_info.user_name) {
			cout << "Incorrect User Name\n";
		}

		if (sign_up_info.password != Sign_in_info.password) {
			cout << "Incorrect Password\n";
		}

		if (sign_up_info.user_name == Sign_in_info.user_name && sign_up_info.password == Sign_in_info.password) {
			system("cls");
			cout << "Login Successful! Welcome to Update World.\n";
			cout << "To Continue Using the App, Please Create Your Profile.\nPress Enter Tp Continue...";
			Main_menu(profile, bio_choise, idea, Sign_in_info, sign_up_info);
			break;
		}
	}
		
	}