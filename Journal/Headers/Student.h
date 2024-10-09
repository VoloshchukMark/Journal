#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Marks.h"

#include <iostream>
#include <vector>
#include <list>
//
//using namespace std;

class Student :public Person
{
private:
public:



    Marks marks;

    void displayInfo() override;


    Student();
    Student(int newId);
    Student(int newId, std::string newName);
    Student(int newId, std::string newName, std::string newSurname);
    Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic);
    Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge);
    Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex);
    Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);

    ~Student()override {}
};

#endif // STUDENT_H
