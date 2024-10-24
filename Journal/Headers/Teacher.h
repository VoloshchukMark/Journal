#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "Subject.h"

#include <iostream>
#include <vector>

class Teacher :public Person
{
private:
    std::string* shortName;
public:
    void displayInfo() override;

    void updateInfo(int newId, std::string newName,std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newShortName);


    void setShortName(std::string& newShortName);
    std::string getShortName();
    void displayShortName();

    Teacher(const Teacher& other)
    :Person(other) {
        shortName = new std::string(*other.shortName);
    }
    Teacher& operator=(const Teacher& other) {
        if (this == &other) return *this;
        Person::operator=(other);
        *shortName = *other.shortName;
        return *this;
    }
    Teacher(Teacher&& other) noexcept : Person(std::move(other)), shortName{other.shortName} {
        other.shortName = nullptr;
    }
    Teacher& operator=(Teacher&& other) noexcept {
        if (this != &other) {
            Person::operator=(std::move(other));
            shortName = other.shortName;
            other.shortName = nullptr;
        }
        return *this;
    }



    Teacher();
    Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newShortName);

    ~Teacher();
};

#endif // TEACHER_H
