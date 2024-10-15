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
    void createStudent();
    std::string nsp_check(std::string item);
    int age_check(std::string uncheckedNewAge);
    std::string sex_check(std::string uncheckedNewSex);
    std::string address_check(std::string uncheckedNewAddress);

    std::vector<Marks> baseOfMarks;
    Marks* selectedMarks = new Marks();
    void importMarks();
    void connectMarksToStudent(Student* selectedStudent);


    int startMenu();
    void studentInfo();
    static void viewGrades();
    static void teacherInfo();

    static void userManual();

    bool containsOnlyDigits(const std::string& str);



    Interface();
    ~Interface();
};

#endif // INTERFACE_H
