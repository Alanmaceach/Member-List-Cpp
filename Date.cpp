#ifndef DATE_H
#define DATE_H


#include "Date.h"


//Constructor for Date class.
Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year)
{}

//Default constructor for Date class.
Date::Date()
{}


//Getters for month, day and year.

int Date::Month() const {
	return month_;
}

int Date::Day() const {
	return day_;
}

int Date::Year() const {
	return year_;
}


//Function to print date in the form DD/MM/YYYY.
void Date::PrintDate(ostream& out_stream) const {
	out_stream << Day() << "/" << Month() << "/" << Year();
}

//Fucntion to check if two dates are equal.
bool Date::Equal(const Date& rhs) const {
	if (Month() != rhs.Month() || Day() != rhs.Day() || Year() != rhs.Year()) {
		return false;
	} else {
		return true;
	}
}

//Function to check if one date is less than the other.
bool Date::Less(const Date& rhs) const {
	//First check if year is not equal.
	if (Year() != rhs.Year()) {
		return Year() < rhs.Year();
	//Then if the years are equal check if the months are equal.
	} else if (Month() != rhs.Month()) {
		return Month() < rhs.Month();
	//Then if year and month are equal check if the days are equal.
	} else if (Day() != rhs.Day()) {
		return Day() < rhs.Day();
	} else {
		return false;
	}
}

//Function to check the difference in years between two dates.
int Date::DifferenceInDate(const Date& current_date) const {
	int year_difference = current_date.Year() - Year();
	if ((current_date.Month() < Month() || (current_date.Month() == Month() && current_date.Day() < Day()))) {
		year_difference--;
	}
	return year_difference;
}

//Taken from lab 4 last semester.
//Function to check if function is a leap year or not.
//Returns true if function is a leap year.
//Returns false if fucntion is not a leap year.
bool IsLeapYear(int year) {
	//If the year is divisable by 100 it is a leap year if it is also divisable by 400.
	//If not only a leap year if it is also divisable by 4.
	if (year % 100 == 0) {
		return year % 400 == 0;
	} else {
		return year % 4 == 0;
	}
}

//Function to check a date is a valid one.
//Returns true if its valid.
//Returns false if its not valid.
bool Date::IsValidDate(int founding_year) const {
	//If the month is not valid return false.
	if (Month() > 12 || Month() < 1) {
		return false;
	}
	//If the month is April, June, September, November check if Day is between 1-30.
	if (Month() == 4 || Month() == 6 || Month() == 9 || Month() == 11) {
		if (Day() > 30 || Day() < 1) {
			return false;
		}
	//Else if the month is Feburary check if its a leap year.
	} else if (Month() == 2) {
		//If its a leap year check if the day is between 1-29.
		if (IsLeapYear(Year())) {
			if (Day() > 29 || Day() < 1) {
				return false;
			}
		//If it is not a leap year check if the number of days are between 1-28.
		} else {
			if (Day() > 28 || Day() < 1) {
				return false;
			}
		}
	}
	//Else for any other month check if the number of days is between 1-31.
	else {
		if (Day() < 1 || Day() > 31) {
			return false;
		}
	}
	if (Year() < founding_year) {
		return false;
	}
	//If the above is correct then the date is valid enough return true.
	return true;
}



//Overload of the << opertator for the Date class using the print function.
ostream& operator<<(ostream& out_stream, const Date& out_date) {
	out_date.PrintDate(out_stream);
	return out_stream;
}

//Overload of the == operator for the Date class.
bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.Equal(rhs);
}

//Overload the Less than operator for the Date class.
bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.Less(rhs);
}

//Overload of the != operator for the Date class.
bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}

#endif // !DATE_H