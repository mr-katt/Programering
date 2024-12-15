#include <ctime>  // time and localtime
#include <ios>
#include <istream>
#include <ostream>
#include <iomanip>
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	this->year = y;
	this->month = m;
	this->day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::next() {
    int days = daysPerMonth[month - 1];

    if (month == 2 && isLeapYear(year)) {
        days = 29;
    }

    if (++day > days) {
        day = 1;
        if (++month > 12) {
            month = 1;
            ++year;
        }
    }
}


std::istream& operator>>(std::istream& is, Date& date) {
    char dash1, dash2;
    if (is >> date.year >> dash1 >> date.month >> dash2 >> date.day) {
        if (dash1 != '-' || dash2 != '-' || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31) {
            is.setstate(std::ios_base::failbit);
        }
    } else {
        is.setstate(std::ios_base::failbit);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << std::setfill('0') << date.getYear() << '-'
       << std::setw(2) << std::setfill('0') << date.getMonth() << '-'
       << std::setw(2) << std::setfill('0') << date.getDay();
    return os;
}

