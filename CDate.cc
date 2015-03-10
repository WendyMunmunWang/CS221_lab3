// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate( void ){
	m_year = m_month = m_day = 0;
}

CDate::CDate( int year, int month, int day ){
	setDate( year, month, day );        
}

CDate::CDate( int year, std::string month, int day ){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	setDate(year, monthStr2Num(month), day);
}

bool CDate::isValidDate( int year, int month, int day ){
	// TODO you need to fill in the code here        ********
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
	if ((isValidDay(year, month, day))&&(year>=1)) return true;
	else return false;
}

bool CDate::isValidDate( int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// comment out "return false" below
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	if (isValidDate(year, monthStr2Num(month), day)) return true;
	else return false;
}

int CDate::monthStr2Num(std::string month){
	// TODO you need to fill in the code here        ********
	if (month.compare("January")==0) return 1;
	if (month.compare("February")==0) return 2;
	if (month.compare("March")==0) return 3;
	if (month.compare("April")==0) return 4;
	if (month.compare("May")==0) return 5;
	if (month.compare("June")==0) return 6;
	if (month.compare("July")==0) return 7;
	if (month.compare("August")==0) return 8;
	if (month.compare("September")==0) return 9;
	if (month.compare("October")==0) return 10;
	if (month.compare("November")==0) return 11;
	if (month.compare("December")==0) return 12;
	else return -1;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			// TODO you need to fill in the code here        ********
			if ((1<=day)&&(day<=31)) return true;
			else return false;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			// TODO you need to fill in the code here        ********
			if ((1<=day)&&(day<=30)) return true;
			else return false;
		default:
			// TODO you need to fill in the code here        ********
			return false;
			break; 
	}
	return valid;
}

void CDate::setDate( int year, int month, int day ){
	if( isValidDate( year, month, day ) ){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate( int year, std::string month, int day ){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	setDate(year, monthStr2Num(month), day); 
}

void CDate::print( void ){
	std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
}

