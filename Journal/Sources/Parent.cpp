#include "../Headers/Parent.h"

#include "../Headers/Person.h"

#include <iostream>


std::string Parent::getWork()
{
    return work;
}

void Parent::setWork(std::string newWork)
{
    work = newWork;
}

void Parent::displayId(){
    std::cout << "ID: " << getId() << std::endl;
}
void Parent::displayName(){
    std::cout << "Name: " << getName() << std::endl;
}
void Parent::displaySurname(){
    std::cout << "Surname: " << getSurname() << std::endl;
}
void Parent::displayPatronymic(){
    std::cout << "Patronymic: " << getPatronymic() << std::endl;
}
void Parent::displayAge(){
    std::cout << "Age: " << getAge() << std::endl;
}
void Parent::displaySex(){
    std::cout << "Sex: " << getSex() << std::endl;
}
void Parent::displayWork(){
    std::cout << "Work: " << getWork() << std::endl;
}

Parent::Parent()
    :Parent(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Parent::Parent(int newId)
    :Parent(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName)
    :Parent(newId, newName, "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname)
    :Parent(newId, newName, newSurname, "Unknown", 0, "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Parent(newId, newName, newSurname, newPatronymic, 0, "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Parent(newId, newName, newSurname, newPatronymic, newAge, "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex), address{newAddress} {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newWork)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex), address{newAddress}, work{newWork} {}

