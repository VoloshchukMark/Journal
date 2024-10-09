#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Marks.h"

#include <iostream>
#include <vector>
#include <list>
//
//using namespace std;

class Student : public Person
{
private:
public:



    Marks* marks = new Marks;

    void displayInfo() override;

    void displayInfoTable();


    Student();
    Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);

    ~Student()override;
};

#endif // STUDENT_H
