#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>

#include "Student.h"

class Interface
{
public:

    std::vector<Student> baseOfStudents;
    void saveStudents();
    void loadStudents();

    void importMarks(int ID, Student* chosenStudent);


    static int startMenu();
    static void studentInfo();
    static void viewGrades();
    static void teacherInfo();

    static void userManual();


    Interface();
};

#endif // INTERFACE_H
