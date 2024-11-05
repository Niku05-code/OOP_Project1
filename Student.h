#pragma once
#include "Date.h"
#include "Status.h"

class Student
{
private:
    char* givenName;
    char* familyName;
    int studentId;
    std::vector<int> grades;
    Status status;
    Date dateOfBirth;

public:
    Student() = default;

    Student(const char* GivenName, const char* FamilyName, int StudentId, std::vector<int> Grades, Status statusValue, Date DateOfBirth);

    Student& operator=(const Student& other);

    // ~Student();

    const char* getGivenName() const;
    const char* getFamilyName() const;
    const Status& getStatus() const;

    double averageGrade() const;
    int ageInYears() const;

    void addGrade(int grade, Student student);
    void modifyGrade(int index, int newGrade);
    void removeGrade(int index);


    friend std::istream& operator>>(std::istream& in, Student& student);
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

void studentStatus(std::vector<Student>& students, Status status);
void sortStudents(std::vector<Student>& students);