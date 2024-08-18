#include "../Headers/Teacher.h"

#include "../Headers/Person.h"

#include <iostream>


std::string Teacher::getAddress()
{
    return address;
}

void Teacher::setAddress(std::string newAddress)
{
    address = newAddress;
}

void Teacher::displayId(){
    std::cout << "ID: " << getId() << std::endl;
}
void Teacher::displayName(){
    std::cout << "Name: " << getName() << std::endl;
}
void Teacher::displaySurname(){
    std::cout << "Surname: " << getSurname() << std::endl;
}
void Teacher::displayPatronymic(){
    std::cout << "Patronymic: " << getPatronymic() << std::endl;
}
void Teacher::displayAge(){
    std::cout << "Age: " << getAge() << std::endl;
}
void Teacher::displaySex(){
    std::cout << "Sex: " << getSex() << std::endl;
}

Teacher::Teacher()
    :Teacher(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId)
    :Teacher(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName)
    :Teacher(newId, newName, "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname)
    :Teacher(newId, newName, newSurname, "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Teacher(newId, newName, newSurname, newPatronymic, 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Teacher(newId, newName, newSurname, newPatronymic, newAge, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex), address{newAddress} {}
