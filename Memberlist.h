#include "MemberDetails.h"

//Class to store a list of members for a society or club .
//Has the following atributes:
// Size - Keeps track of current size of club (including inactive members).
// MaxSize - Maximum size of the array that stores the members.
// Contents - Array that stores all the members.
//Has the following functions:
// FoundingYear - getter for founding year.
// Full - Test to return if the array is full or not.
// Empty - Test to return if the array is empty.
// AddMember - Function to add a new member.
// PrintList - Function to print a list of longstanding members from a date.
// RemoveMember - Function to set a member's status to false.
class MemberList {
private:
	int size_;
	int max_size_;
	int founding_year_;
	MemberDetails* contents_;
public:
	//Constructors
	MemberList();
	MemberList(int size, int founding_year);
	~MemberList();
	//Getter
	int FoundingYear();
	//Tests
	bool Full();
	bool Empty();
	//Other Functions
	void AddMember(MemberDetails member);
	void PrintList(Date current_date);
	bool RemoveMember(string member_number);
};

