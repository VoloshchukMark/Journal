#ifndef PARENT_H
#define PARENT_H

#include "Person.h"

#include <iostream>
#include <vector>


class Parent :public Person
{
private:
    std::string address;
    std::string work;
public:

    std::string getAddress();
    std::string getWork();

    void setAddress(std::string newAddress);
    void setWork(std::string newWork);

    void displayId();
    void displayName();
    void displaySurname();
    void displayPatronymic();
    void displayAge();
    void displaySex();
    void displayAddress();
    void displayWork();

    Parent();
    Parent(int newId);
    Parent(int newId, std::string newName);
    Parent(int newId, std::string newName, std::string newSurname);
    Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic);
    Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge);
    Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex);
    Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);
    Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newWork);
};

#endif // PARENT_H
