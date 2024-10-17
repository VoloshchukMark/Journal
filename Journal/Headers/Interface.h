#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>

#include "Student.h"
#include "Subject.h"

class Interface
{
public:

    std::vector<Student> baseOfStudents;
    Student* selectedStudent = new Student();
    std::string selectStudent(std::string selectedId);

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
    int connectMarksToStudent(Student* selectedStudent);

    std::vector<Subject> baseOfSubjects;
    Subject* selectedSubject = new Subject();
    void importSubjects();


    int startMenu();
    int studentInfo();
    void viewStudent();
    void viewStudentSubjects();
    void viewGrades(std::string name, int idSubject, int idMarks);
    static void teacherInfo();

    static void userManual();

    bool containsOnlyDigits(const std::string& str);



    Interface();
    ~Interface();
};

#endif // INTERFACE_H
