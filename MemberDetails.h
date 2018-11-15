#ifndef MEMBERDETAILS_H
#define MEMBERDETAILS_H


#include "date.h"

//Class to store the details of members stores the following attributes
// Member Number, Full Name, Joining Date and their current status.
//Has the following Functions
// Getters for all the attributes
// Setter for the member status
//Print - Returns an ostream with the member details in a string in form "Member_name   Joining Date   Full Name"
//Less - Returns a boolean if one member is less than another, done by joining date, then alphabettically by surname
class MemberDetails {
private:
	string member_number_;
	string first_name_;
	string last_name_;
	Date date_joined_;
	bool current_status_;
public:
	//Constructors
	MemberDetails();
	MemberDetails(string member_number, Date date_joined, string first_name, string last_name);
	//Getters
	string MemberNumber() const;
	string FirstName() const;
	string LastName() const;
	Date JoiningDate() const;
	bool MemberStatus() const;
	//Setters
	void SetMemberStatus(bool new_status);
	//Functions for overloading operators
	void Print(ostream& out_stream) const;
	bool Less(const MemberDetails& other_member) const;
	//Other functions
	int GetMemberLength(Date current_date);
};


//Overloaded functions
ostream& operator << (ostream& out_stream, const MemberDetails& out_date);
bool operator< (const MemberDetails&, const MemberDetails& rhs);
bool operator> (const MemberDetails&, const MemberDetails& rhs);
bool operator== (const MemberDetails&, const MemberDetails& rhs);
bool operator <= (const MemberDetails&, const MemberDetails& rhs);

#endif // !MEMBERDETAILS_H