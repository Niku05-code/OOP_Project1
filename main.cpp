#include <fstream>
#include "Student.h"
#include <iostream>
#include <vector>

int main()
{
    std::ifstream fin("student.txt");
    std::vector<Student> students;

    if (!fin) {
        std::cerr << "Eroare la deschiderea fisierului!" << std::endl;
        return 1;
    }

    Student student1;
    while (fin >> student1)
    {
        students.push_back(student1);
    }

    fin.close();

    for(auto student : students) {
        std::cout << student;
        std::cout << std::endl;
    }

    studentStatus(students, Status::ENROLLED);
    std::cout << std::endl;

    // student1 = students[0];
    // student1.addGrade(5, student1);
    // student1.modifyGrade(1, 3);
    // student1.removeGrade(0);
    // std::cout << std::endl;
    // students[0] = student1;

    //std::cout << students[0] << std::endl;

    sortStudents(students);
    for(auto student : students) {
        std::cout << student;
        std::cout << std::endl;
    }


    return 0;
}