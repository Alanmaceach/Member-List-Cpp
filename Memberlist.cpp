#include "Memberlist.h"
#include "sortlisttemplate.h"
#include <string>
using namespace std;

//Default constructor
MemberList::MemberList()
{}

//Constructor that takes the max size of the society and the founding year
MemberList::MemberList(int maxsize, int foundingyear) :
	size_(0),
	founding_year_(foundingyear),
	max_size_(maxsize),
	contents_(new MemberDetails[max_size_])
{}

//Destructor
MemberList::~MemberList(){
	delete[] contents_;
}


//Function to add a member
void MemberList::AddMember(MemberDetails new_member)
{
	contents_[size_] = new_member;
	size_++;
}


//Function to print a list of longstanding members as of a current date
//Don't need to worry about duplicate member numbers as they are determined outside the program.
void MemberList::PrintList(Date CurrentDate)
{
	//Sort list in order of date and alphabettically
	Sortlist<MemberDetails> sorted_list(size_);
	sorted_list.SetArray(contents_);
	sorted_list.Quicksort();
	sorted_list.GetArray(contents_);
	//Get the first element in the array as its the longest standing member
	int max_length = contents_[0].GetMemberLength(CurrentDate);
	//Round it to the nearest 10
	int max_decade = max_length / 10 * 10;
	// If the list is not empty but the longest member is less than 10 years alert the user
	if (max_decade <= 0) { 
		cout << endl << "No Members longer than 10 years" << endl;
	} else {
		//Print the title of the list with the current date
		cout << endl << "Long-standing members at " << CurrentDate << ":" << endl;
		//Start at the longest serving member
		int member_list_index = 0;
		//Boolean to check if the X+ years title has been printed.
		bool title_already_printed;
		//For loops that starts at the largest decade
		for (int i = max_decade; i >= 0; i = i - 10)
		{
			//For each decade set the title printed to false
			title_already_printed = false;
			//Loop through checking if the member is in the right decade, and that the index doesn't go over the size of the society
			while (contents_[member_list_index].GetMemberLength(CurrentDate) / 10 * 10 > i && member_list_index < size_)
			{
				//Check the members status
				if (contents_[member_list_index].MemberStatus())
				{
					//Title hasn't beed printed, print it and the headings
					if (!title_already_printed)
					{
						cout << endl << i + 10 << " years+" << endl;
						cout << endl << "Mem No.\t\tDate joined\t\tName" << endl << endl;
						title_already_printed = true;
					}
					//Print out the members details
					cout << contents_[member_list_index] << endl;
				}
				//Add one to check the next member
				member_list_index++;
			}
		}
	}
}

bool MemberList::RemoveMember(string member_number) {
	//Boolean set to false for memberfound
	bool member_deleted = false;
	//Loop through whole array
	for (int i = 0; i < size_; i++) {
		//If a members number is equal to the number to deleted
		if (contents_[i].MemberNumber() == member_number) {
			//Set the status to false and set member deleted
			contents_[i].SetMemberStatus(false);
			member_deleted = true;
		}
	}
	//Return whether or not the member was deleted
	return member_deleted;
}

//Return whether or not the list is full
bool MemberList::Full() {
	return  size_ == max_size_  ? true : false;
}

bool MemberList::Empty() {
	//Loop through list
	for (int i = 0; i < size_; i++) {
		//If a member is found return false
		if (contents_[i].MemberStatus()) {
			return false;
		}
	}
	//Otherwise return true
	return true;
}

//Getter for founding year.
int MemberList::FoundingYear()
{
	return founding_year_;
}



