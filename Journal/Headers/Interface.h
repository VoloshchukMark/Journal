#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Student.h"
#include "Subject.h"
#include "Parent.h"
#include "Teacher.h"
#include "Grades.h"


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

    void createStudent();
    std::string nsp_check(std::string item);
    int age_check(std::string uncheckedNewAge);
    std::string sex_check(std::string uncheckedNewSex);
    std::string address_check(std::string uncheckedNewAddress);

    std::vector<Grades> baseOfGrades;
    Grades* selectedGrades = new Grades();
    void eraseGrades(int idDoomedGrades);
    void displayGradesToEdit(std::string nameOfGradesList, std::vector<double> gradesForEdit);
    int connectGradesToStudent(Student* selectedStudent);
    std::vector<double> changeGrade(std::vector<double> insertedGrades, int coordinate, double newValue);

    std::vector<Subject> baseOfSubjects;
    Subject* selectedSubject = new Subject();

    void saveSubjects();


    int startMenu();
    int studentInfo();
    void viewStudent();
    void viewStudentSubjects();
    void selectSubject();
    void gradesInfo(int idSubject, int newPage);
    void editGrades(int idSubject, int idGrades);
    void viewGrades(std::string name, int idSubject, int idGrades);
    void teacherInfo();

    void userManual();

    bool containsOnlyDigits(const std::string& str);
    void clearAllBases();

    template<typename T>
    void sortItems(std::vector<T>& baseOfItems);
    void sortItems(std::vector<Grades>& baseOfItems);
    template<typename T>
    void saveBasesOfItems(std::vector<T>& baseOfItems);
    template<typename T>
    void loadItems(std::vector<T>& baseOfItems);
    template<typename L>
    void eraseItem(std::vector<L>& baseOfItems, std::string idDoomedItem);

    Interface();
    ~Interface();
};

//bool compareById(const Student& a, const Student& b) {
//    return a.getId() < b.getId();
//}

#endif // INTERFACE_H
