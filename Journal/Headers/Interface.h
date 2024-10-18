#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Student.h"
#include "Subject.h"


//bool compareByName(const Student& a, const Student& b) {
//    return a.getName() < b.getName();
//}


class Interface
{
public:
    bool shouldLoad = true;
    std::vector<Student> baseOfStudents;
    Student* selectedStudent = new Student();
    std::string selectStudent(std::string selectedId);

    void saveStudents();
    void loadStudents();
    void createStudent();
    void eraseStudent();
    void sortStudents();
    std::string nsp_check(std::string item);
    int age_check(std::string uncheckedNewAge);
    std::string sex_check(std::string uncheckedNewSex);
    std::string address_check(std::string uncheckedNewAddress);

    std::vector<Marks> baseOfMarks;
    Marks* selectedMarks = new Marks();
    void importMarks();
    void saveMarks();
    void eraseMarks(int idDoomedMarks);
    int connectMarksToStudent(Student* selectedStudent);

    std::vector<Subject> baseOfSubjects;
    Subject* selectedSubject = new Subject();
    void importSubjects();
    void saveSubjects();


    int startMenu();
    int studentInfo();
    void viewStudent();
    void viewStudentSubjects();
    void gradesInfo();
    void viewGrades(std::string name, int idSubject, int idMarks);
    static void teacherInfo();

    static void userManual();

    bool containsOnlyDigits(const std::string& str);

    Interface();
    ~Interface();
};

//bool compareById(const Student& a, const Student& b) {
//    return a.getId() < b.getId();
//}

#endif // INTERFACE_H
