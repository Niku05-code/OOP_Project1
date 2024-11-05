#pragma once
#include <string>

class Date
{
private:
    std::string day;
    std::string month;
    int year;
public:
    Date() = default;
    Date(std::string day, std::string month, int year);

    ~Date() = default;

    Date& operator=(const Date& other);

    const std::string &getDay() const;

    const std::string &getMonth() const;

    const int &getYear() const;

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};
