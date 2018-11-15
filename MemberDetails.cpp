#include "MemberDetails.h"
#include <string>


//CONSTRUCTORS

//Default constructor for MemberDetails.
MemberDetails::MemberDetails()
{}

//Constructor for Memberdetails class.
MemberDetails::MemberDetails(string membernumber, Date datejoined, string firstname, string lastname):
	member_number_(membernumber), date_joined_(datejoined), first_name_(firstname), last_name_(lastname), current_status_(true)
{}


//GETTERS AND SETTERS

//Getter for member number.
string MemberDetails::MemberNumber() const {
	return member_number_;
}

//Getter for first name.
string MemberDetails::FirstName() const {
	return first_name_;
}

//Getter for last name.
string MemberDetails::LastName() const {
	return last_name_;
}

//Getter for joining date.
Date MemberDetails::JoiningDate() const {
	return date_joined_;
}

//Getter for Member status.
bool MemberDetails::MemberStatus() const {
	return current_status_;
}

//Setter for Member status
void MemberDetails::SetMemberStatus(bool new_status) {
	current_status_ = new_status;
}


//OTHER FUNCITONS

//Function to print the Member Details class.
void MemberDetails::Print(ostream& out_stream) const {
	out_stream << MemberNumber() << "\t\t" << JoiningDate() << "\t\t" << FirstName() << " " << LastName();
}

//Function to return the lowercase equivilant of a string.
string lowercase(string name) {
	string answer;
	for (char& c : name)
	{
		answer += tolower(c);
	}
	return answer;
}

//Function used for overloading the < operator.
//Members are less than if their joining date is before the other.
//If the joining date is the same they are sorted alphabetically by surname first.
//Compares the name as if they were all lowercase.
bool MemberDetails::Less(const MemberDetails& other_member) const {
	//Check if the joining date is less than that of the other members.
	if (JoiningDate() != other_member.JoiningDate()) {
		return JoiningDate() < other_member.JoiningDate();
	} else {
		//If the last names are not equal return if the last name is less than the other one or not.
		string lastname = lowercase(LastName());
		string other_member_lastname = lowercase(other_member.LastName());
		if (lastname != other_member_lastname) {
			return lastname < other_member_lastname;
		//Else return if the first name is less thatn the other one or not.
		} else {
			string firstname = lowercase(FirstName());
			string other_member_firstname = lowercase(other_member.FirstName());
			return firstname < other_member_firstname;
		}
	}
}

//Function to calculate how long (in years) a member has been a member of the society
int MemberDetails::GetMemberLength(Date current_date) {
	return JoiningDate().DifferenceInDate(current_date);
}


//Overloaded Operators for <<, <, >, ==, and <=

ostream & operator<<(ostream& out_stream, const MemberDetails& out_details) {
	out_details.Print(out_stream);
	return out_stream;
}

bool operator<(const MemberDetails& lhs, const MemberDetails& rhs) {
	return lhs.Less(rhs);
}

bool operator>(const MemberDetails& lhs, const MemberDetails& rhs) {
	return rhs.Less(lhs);
}

bool operator==(const MemberDetails& lhs, const MemberDetails& rhs) {
	if (!(lhs < rhs) && !(lhs > rhs)) {
		return true;
	} else {
		return false;
	}
}

bool operator<=(const MemberDetails& lhs, const MemberDetails& rhs) {
	if (lhs < rhs || lhs == rhs) {
		return true;
	} else {
		return false;
	}
}
