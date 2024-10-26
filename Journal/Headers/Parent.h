#ifndef PARENT_H
#define PARENT_H

#include "Person.h"

#include <iostream>
#include <vector>


class Parent :public Person
{
private:
    std::string* work;
public:

    std::string getWork();
    void setWork(std::string newWork);
    void displayWork();

    void updateInfo(int newId, std::string newName, std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newAddress, std::string newWork);

    void displayInfo() override;

    Parent(const Parent& other)
    :Person(other) {
        work = new std::string(*other.work);
    }
    Parent& operator=(const Parent& other) {
        if (this == &other) return *this;
        Person::operator=(other);
        *work = *other.work;
        return *this;
    }
    Parent(Parent&& other) noexcept : Person(std::move(other)), work{other.work} {
        other.work = nullptr;
    }
    Parent& operator=(Parent&& other) noexcept {
        if (this != &other) {
            Person::operator=(std::move(other));
            work = other.work;
            other.work = nullptr;
        }
        return *this;
    }

    Parent();
    Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newWork);

    ~Parent();
};

#endif // PARENT_H
