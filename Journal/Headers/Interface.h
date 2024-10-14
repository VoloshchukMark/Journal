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

    std::vector<Marks> baseOfMarks;
    Marks* selectedMarks = new Marks();
    void importMarks();
    void connectMarksToStudent(Student* selectedStudent);


    static int startMenu();
    static void studentInfo();
    static void viewGrades();
    static void teacherInfo();

    static void userManual();


    Interface();
    ~Interface();
};

#endif // INTERFACE_H
