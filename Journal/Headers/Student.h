#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

#include <iostream>
#include <vector>
//
//using namespace std;

class Student :public Person
{
private:
//    vector<double> marks;
    std::string address;
public:

    std::string getAddress();

    void setAddress(std::string newAddress);

    void displayId();
    void displayName();
    void displaySurname();
    void displayPatronymic();
    void displayAge();
    void displaySex();
    void displayAddress();

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
