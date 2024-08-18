#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

#include <iostream>
#include <vector>

class Teacher :public Person
{
private:
//    vector<Subject> subjects;
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

    Teacher();
    Teacher(int newId);
    Teacher(int newId, std::string newName);
    Teacher(int newId, std::string newName, std::string newSurname);
    Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic);
    Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge);
    Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex);
    Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);
};

#endif // TEACHER_H
