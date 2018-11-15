#ifndef DATE
#define DATE

#include <iostream>
using namespace std;


//Class for storing dates, includes following functions:
//DifferenceInDate - Calculates difference in dates in years (returns an int)
//PrintDate - Returns an outstream of the date in DD/MM/YY
//Equal - Returns a boolean on whether two dates a equal
//Less - Returns a boolean on whether one date is less than another
//IsValidDate - Confirms a date is a valid calendar date and it is greater than a minimum year
class Date {
private:
	int month_;
	int day_;
	int year_;
public:
	//Constructors
	Date();
	Date(int day, int month, int year);
	//Getters
	int Month() const;
	int Day() const;
	int Year() const;
	//Functions
	int DifferenceInDate(const Date& rhs) const;
	void PrintDate(ostream& out_stream) const;
	bool Equal(const Date& rhs) const;
	bool Less(const Date& rhs) const;
	bool IsValidDate(int minimum_year) const;
};

//Overloaded operators
ostream& operator<< (ostream& out_stream, const Date& out_date);
bool operator== (const Date&, const Date& rhs);
bool operator< (const Date&, const Date& rhs);
bool operator!= (const Date&, const Date& rhs);

#endif