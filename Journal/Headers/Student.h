#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

#include <iostream>
#include <vector>
#include <list>
#include <functional>
//
//using namespace std;



class Student : public Person
{
public:

    void updateInfo(int newId, std::string newName,std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newAddress);

    void displayInfo() override;

    Student(const Student& other) : Person(other) {}
    Student& operator=(const Student& other) {
        if (this == &other) return *this;
        Person::operator=(other);
        return *this;
    }
    Student(Student&& other) noexcept : Person(std::move(other)) {}
    Student& operator=(Student&& other) noexcept {
        if (this != &other) {
            Person::operator=(std::move(other));
        }
        return *this;
    }

    Student();
    Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);

    ~Student()override;
};

#endif // STUDENT_H
