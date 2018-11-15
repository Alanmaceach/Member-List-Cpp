#include "MemberDetails.h"
#include "Memberlist.h"
#include "date.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


//Function to check if member number is valid
bool ValidMemberNumber(string member_number) {
	//The member number must be four digits long
	if (member_number.size() != 4) {
		return false;
// Go through string and if any chars are not digits then return false.
	} else {
		for (char& c : member_number) {
			if (!isdigit(c)) {
				return false;
			}
		}
		//If it goes through whole list without error then return true.
		return true;
	}
}

//Function to input a member number and check that it is valid
string InputMemberNumber() {
	string member_number;
	cout << "Member Number (must be four digits): ";
	//A check needs to be made if member number is valid
	cin >> member_number;
	while (!ValidMemberNumber(member_number)) {
		cout << endl << "Invalid member number please try again" << endl;
		cout << "Member Number: ";
		cin >> member_number;
	}
	return member_number;
}

//function to input integers and confirm the input are integers.
int InputNumber(string type_of_integer)
{
	cout << type_of_integer << ": ";
	int integer;
	cin >> integer;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			cout << "Please enter a number for " << type_of_integer << ": ";
				cin >> integer;
		}
		if (!cin.fail())
			return integer;
	}
}


//Funciton to input a date, making sure it is a valid date before continuing
Date InputDate(int founding_year) {
	int day = InputNumber("Day");
	int month = InputNumber("Month");
	int year = InputNumber("Year");
	Date joining_date(day, month, year);
	//Check if the date is valid if not loop until a valid date is entered
	while (!joining_date.IsValidDate(founding_year)) {
		cout << "Invalid date, please input a valid date" << endl;
		day = InputNumber("Day");
		month = InputNumber("Month");
		year = InputNumber("Year");
		Date new_date(day, month, year);
		joining_date = new_date;
	}
	return joining_date;
}




int main()
{
	//Create a member list with space for 10000 members.
	MemberList Society(10000, 1850);
	//Create a variable for the switch function.
	char choice;
	//Print the menu.
	string menu = "Please input a choice:  \nA - Add a new person to the list.\nP - Print a list of longstanding members.\nE - Change someones status to false.\nQ - Quit.\n";
	cout << menu << endl;
	//Take in the choice.
	cin >> choice;
	//Loop while the user doesnt quit.
	while (choice != 'q' && choice != 'Q')
	{
		//Switch on choice
		switch (choice)
		{
		  //If 'A' Add a new member to the list.
		  case 'a':
		  case 'A': {
			  //If society is full, don't print list
			if (Society.Full()) {
				cout << "List is full, please select another option" << endl;
				break;
			}
			//Input the details for the names.
			string first_name;
			cout << "Please input the new members details." << endl;
			cout << "First name: ";
			cin >> first_name;
			string last_name;
			cout << "Last Name: ";
			cin >> last_name;
			//Input Member number, using a function to confirm its a valid member number.
			string member_number = InputMemberNumber();
			//Input the date, using function to confirm it is a valid date.
			Date joining_date = InputDate(Society.FoundingYear());
			//If the member number and joining date are valid add member to list.
			Society.AddMember(MemberDetails(member_number, joining_date, first_name, last_name));
			cout << "Member Added" << endl;
			break;
		}
		  //If 'P' ask for date and print longstanding members from that date(10+ years)
		  case'p':
		  case'P': {
			//If society is empty don't print the list
			if (Society.Empty()) {
				cout << endl << "List is empty, can't print list" << endl;
				break;
			}
			//Ask user to input date.
			cout << "Please input current date: " << endl;
			Date current_date = InputDate(Society.FoundingYear());
			//Print the list from the user-entered list.
			Society.PrintList(current_date);
			break;
		}
		  //If 'E' ask for a member number and set the member to false
		  case'E':
		  case'e': {
			if (Society.Empty()) {
				cout << endl << "List is empty, can't delete member" << endl;
			} else {
				//Get user to enter member number.
				string member_to_delete = InputMemberNumber();
				//Check to see if user is in list if so set their status to false.
				if (Society.RemoveMember(member_to_delete)) {
					cout << endl << "Member deleted." << endl;
				//If not alert user member is not in list and go back to main menu
				} else {
					cout << endl << "Member not in list." << endl;
				}
			}
			break;
		}
				 //Default choice is invalid, break and print menu again.
		  default: {
			cout << endl << "Invalid choice" << endl;
			break;
		}
		}
		//Reprint menu to give user another choice.
		cout << endl << menu;
		cin >> choice;
	}
	return 0;
}


