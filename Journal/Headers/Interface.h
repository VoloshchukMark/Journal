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
    //Bases and selected objects---------------------------------------------------------------------
    bool shouldLoad = true;
    std::vector<Student> baseOfStudents;
    Student* selectedStudent = new Student();
    std::vector<Grades> baseOfGrades;
    Grades* selectedGrades = new Grades();
    std::vector<Subject> baseOfSubjects;
    Subject* selectedSubject = new Subject();
    std::vector<Teacher> baseOfTeachers;
    Teacher* selectedTeacher = new Teacher();
    std::vector<Parent> baseOfParents;
    Parent* selectedParent = new Parent();

    //Create functions---------------------------------------------------------------------------
    void createStudent();
    std::string nsp_check(std::string item);
    int age_check(std::string uncheckedNewAge);
    std::string sex_check(std::string uncheckedNewSex);
    std::string address_check(std::string uncheckedNewAddress);
    void createBlankGradesForStudent(int idStudent);

    void createSubject();
    std::string info_check(std::string item);

    void createTeacher(std::string shortName);

    void createBlankGrades(int idSubject);
    void createAndAddBlankGrades(int idSubject);
    void removeExistantGradesPage(int idSubject);

    void createParent(int idParent);

    //Edit functions---------------------------------------------------------------------
    void editGrades(int idSubject, int idGrades);
    void displayGradesToEdit(std::string nameOfGradesList, std::vector<double> gradesForEdit);
    int connectGradesToStudent(Student* selectedStudent);
    std::vector<double> changeGrade(std::vector<double> insertedGrades, int coordinate, double newValue);


    //General functions---------------------------------------------------------------------
    void userManual();
    bool containsOnlyDigits(const std::string& str);
    void clearAllBases();

    //Start menu ------------------------------------------------------------------------------
    int startMenu();
    int studentInfo();
    void gradesInfo(int idSubject, int newPage);
    void subjectInfo();

    //View object functions---------------------------------------------------------------------
    void viewStudent();
    void viewStudentSubjects();
    void viewGrades(std::string name, int idSubject, int idGrades);
    void viewSubject();
    void viewTeacher(int idTeacher);
    void viewParent(int idParent);


    //Uhhh, function-selectors, I guess?------------------------------------------------------
    bool selectStudent(std::string selectedId);
    void selectSubject();


    //Template functions-----------------------------------------------------------------------
    template<typename T>
    void editItem(std::vector<T>& baseOfItem);
    template<typename T>
    void sortItems(std::vector<T>& baseOfItems);
    void sortItems(std::vector<Grades>& baseOfItems);
    void sortItems(std::vector<Subject>& baseOfItems);
    template<typename T>
    void saveBasesOfItems(std::vector<T>& baseOfItems);
    template<typename T>
    void loadItems(std::vector<T>& baseOfItems);
    template<typename L>
    void eraseItem(std::vector<L>& baseOfItems, std::string idDoomedItem, std::string typeOfId);

    Interface();
    ~Interface();
};


#endif // INTERFACE_H
