#include <iostream>
#include "Student.h"
#include "Status.h"

Student::Student(const char* GivenName, const char* FamilyName, int StudentId, std::vector<int> Grades, Status StatusValue, Date DateOfBirth)
{
    givenName = new char[strlen(GivenName) + 1];
    strcpy(givenName, GivenName);

    familyName = new char[strlen(FamilyName) + 1];
    strcpy(familyName, FamilyName);

    studentId = StudentId;
    grades = Grades;
    status = StatusValue;
    dateOfBirth = DateOfBirth;
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        std::strcpy(this->familyName, other.familyName);
        std::strcpy(this->givenName, other.givenName);
        this->studentId = other.studentId;
        this->grades = other.grades;
        this->status = other.status;
        this->dateOfBirth = other.dateOfBirth;
    }
    return *this;
}

// Student::~Student()
// {
//     delete[] givenName;
//     delete[] familyName;
// }

const char *Student::getFamilyName() const
{
    return familyName;
}

const char *Student::getGivenName() const
{
    return givenName;
}

const Status &Student::getStatus() const
{
    return status;
}

double Student::averageGrade() const
{
        double sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        double average = (double)sum / grades.size();
        return average;
}

int Student::ageInYears() const
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int age = now->tm_year + 1900 - dateOfBirth.getYear();
    int month = std::stoi(dateOfBirth.getMonth());
    int day = std::stoi(dateOfBirth.getDay());
    if (now->tm_mon + 1 < month || (now->tm_mon + 1 == month && now->tm_mday < day))
        age--;
    return age;
}

void Student::addGrade(int grade, Student student)
{
    grades.push_back(grade);
    std::cout << "Added grade: " << grade << " to " << student.familyName << " " << student.givenName << std::endl;
}

void Student::modifyGrade(int index, int newGrade)
{
    int oldGrade = grades[index];
    grades[index] = newGrade;
    std::cout << "Grade " << oldGrade << " modified with the grade " << newGrade << std::endl;
}

void Student::removeGrade(int index)
{
    int oldGrade = grades[index];
    grades.erase(grades.begin() + index);
    std::cout << "Removed grade: " << oldGrade << std::endl;
}

std::istream& operator>>(std::istream& in, Student& student)
{
    char givenName[100];
    char familyName[100];
    int numGrades;
    int statusInt;
    Status studentStatus;
    std::string day, month;
    int year;
    Date dateOfBirth;

    in >> givenName >> familyName >> student.studentId >> numGrades;

    student.givenName = new char[strlen(givenName) + 1];
    strcpy(student.givenName, givenName);

    student.familyName = new char[strlen(familyName) + 1];
    strcpy(student.familyName, familyName);

    student.grades.resize(numGrades);
    for (int i = 0; i < numGrades; ++i) {
        in >> student.grades[i];
    }

    in >> statusInt;
    student.status = static_cast<Status>(statusInt);

    in >> day >> month >> year;
    student.dateOfBirth = Date(day, month, year);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << "Name: " << student.givenName << " " << student.familyName << std::endl;
    out << "Id: " << student.studentId << std::endl;
    out << "Grades: ";
    for (int i = 0; i < student.grades.size(); ++i) {
        out << student.grades[i] << " ";
    }
    out << std::endl;
    out << "Average Grade: " << student.averageGrade() << std::endl;
    out << "Status: ";
    switch (student.status)
    {
        case Status::ENROLLED:
        {
            out << "ENROLLED" << std::endl;
            break;
        }
        case Status::GRADUATED:
        {
            out << "GRADUATED" << std::endl;
            break;
        }
        case Status::DROPPED_OUT:
        {
            out << "DROPPED_OUT" << std::endl;
            break;
        }
    }
    out << "Date of Birth: " << student.dateOfBirth << std::endl;
    out << "Age: " << student.ageInYears() << std::endl;
    return out;
}

void studentStatus(std::vector<Student>& students, Status status)
{
    std::cout << "Students with status ";
    switch (status)
    {
        case Status::ENROLLED:
        {
            std::cout << "ENROLLED";
            break;
        }
        case Status::GRADUATED:
        {
            std::cout << "GRADUATED";
            break;
        }
        case Status::DROPPED_OUT:
        {
            std::cout << "DROPPED_OUT";
            break;
        }
    }
    std::cout << ":" << std::endl;

    for (auto student : students)
    {
        if (student.getStatus() == status)
            std::cout << student.getFamilyName() << " " << student.getGivenName()<< std::endl;
    }
}

void sortStudents(std::vector<Student>& students)
{
    auto comp = [] (Student& a, Student& b)
    {
        return a.averageGrade() > b.averageGrade();
    };
    std::sort(students.begin(), students.end(), comp);
}