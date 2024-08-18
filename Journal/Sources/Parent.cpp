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

void Parent::displayWork()
{
    std::cout << "Work: " << this->getWork() << std::endl;
}

void Parent::displayInfo(){
    std::cout << "================================" << std::endl;
    this->displayName();
    this->displaySurname();
    this->displayPatronymic();
    this->displaySex();
    this->displayAge();
    this->displayAddress();
    this->displayWork();
    std::cout << "================================" << std::endl;
}


Parent::Parent()
    :Parent(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown", "Unknown") {}
Parent::Parent(int newId)
    :Parent(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName)
    :Parent(newId, newName, "Unknown", "Unknown", 0, "Unknown", "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname)
    :Parent(newId, newName, newSurname, "Unknown", 0, "Unknown", "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Parent(newId, newName, newSurname, newPatronymic, 0, "Unknown", "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Parent(newId, newName, newSurname, newPatronymic, newAge, "Unknown", "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex)
    :Parent(newId, newName, newSurname, newPatronymic, newAge, newSex, "Unknown", "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Parent(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress, "Unknown") {}
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newWork)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress), work{newWork} {}

