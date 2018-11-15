# Question 2 Program Brief

A society keeps a list of members and uses a program to store the list. For each member,
the following information is recorded:

•	Membership number

•	Surname

•	First name

•	The date (day, month, year) that the person joined the society.

•	Whether or not they are still a member.

The program is required to offer three options:

1. Enter (interactively) the details of a member (either a current or past member).
Note that members may be entered in any order. You can assume that the membership number is available from some existing list, so just needs to be entered the program along with the other data.

2. Prompt for the current date, and produce as output a list of people who have been
a member for at least 10 years (and is still a member currently). The list should
be in order of the date that they joined, and split up according to how long they
have been a member (i.e., 50 years+, 40 years+ etc.). If there is more than one
person who joined on the same day, they should be given in alphabetical order of
surname and, if they have the same surname, First name. The list should be produced by sorting the set of members into the order required.

3. Prompt for a membership number and mark that person's membership as not current.

## Main.cpp

The main program, as well as using the below classes, takes advantage of the following functions

•	ValidMemberNumber(membernumber) – Checks if a number is all digits and length 4

•	InputMemberNumber() – Function that takes the input of a member number, repeatedly asks the user for a membernumber until the enter a valid one.

•	InputNumber() – Used for ensuring that the individual parts of date are entered with a integers, takes the string for the type of number that it needs to print so it can ask the user to enter it again.

•	InputDate – Repeatedly asks for a date until the user enters a valid one

Has a switch with four options,

A – Add member,

P – Print list of longstanding members as of a date,

E – Set a member’s status false

A – Checks that the list is not full, if not it takes the details of the new user and adds them to the list

P –Check if the list is empty, if so it alerts the user, else it asks for the current date prints the list of user

E – Asks for member number, deletes the member if found, otherwise alerts the user. 

Q – Quits the program


## Sortlist class
Taken from the computing share drive. Left unchanged. Used to sort arrays using quicksort and return the sorted array.

## Date class

Used to store date values DD/MM/YYYY and perform the following functions on them:

•	DifferenceInDate() - Calculates difference in dates in years (returns an integer)

•	PrintDate() - Returns an outstream of the date in DD/MM/YY

•	Equal() - Returns a Boolean on whether two dates a equal

•	Less() - Returns a Boolean on whether one date is less than another

•	IsValidDate() - Confirms a date is a valid calendar date and it is greater than a minimum year
Overloaded operators 

•	<< - Used the member function PrintDate() to print the date

•	== - Uses the member function Equal()


## Member Details class

Used to store details of members, stores attributes such as First name, Surname, Member number, Member status, Joining date

Has the following functions

•	A default constructor

•	A constructor that takes name, joining date and member number and sets member status to true

•	Getters for First name, Surname, Member number, Member status, Joining date

•	Setter for Member status

•	Print() – Function to print the Member Details class.

•	Less() – /Returns a Boolean if one member is less than another, done by joining date, then alphabetically by surname, regardless of case.

•	GetMemberLength(current_date) – Returns the amount of time (in years, rounded down) that a user has been a member of the society, given the current date.

•	Lowercase() – Not a member function but takes a string and returns it with all character lowercase
Overloaded operators 

•	<< - Used the member function Print() to print the member

•	< - Uses the member function Less()

•	> - The opposite of the < function

•	== - Uses a combination of < and >

•	<= - Needed for quicksort combines < and ==.

## MemberList Class

Used to store an array of members of a society has the following attributes:

Current Size, Maximum Size, Array of Members and founding year.

Has the following functions

•	A default constructor

•	A constructor that takes founding year and max_size

•	A destructor that deletes the pointer array

•	Getter for Founding Year

•	Full() – Returns a Boolean value if the array is full or not

•	Empty() – Returns a Boolean value if the array is empty or every member has a status of false

•	AddMember() – Function takes a Member Details object adds them to the last place in the array, increase the current size of the pointer array counter.

•	PrintDetails(current_date) - Function to print a list of longstanding members as of a current date

•	RemoveMember(member_number) – Function to set the status of a member to false given a member number. Returns true if deleted, otherwise returns false.

