#include <iostream>
#include "Date.h"

Date::Date(std::string Day, std::string Month, int Year)
{
    day = Day;
    month = Month;
    year = Year;
}

Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    return *this;
}

const std::string &Date::getDay() const
{
    return day;
}
const std::string &Date::getMonth() const
{
    return month;
}
const int &Date::getYear() const
{
    return year;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << date.getDay();
    out << "/" << date.getMonth() << "/" << date.getYear();
    return out;
}



