#include "../Headers/Parent.h"

#include "../Headers/Person.h"

#include <iostream>


std::string Parent::getWork()
{
    return *work;
}

void Parent::setWork(std::string newWork)
{
    work = new std::string(newWork);
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
Parent::Parent(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newWork)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress) {
        work = new std::string(newWork);
        std::cout << "Constructor of Parent class was called!" << std::endl;
    }

Parent::~Parent() {
    delete work;
    std::cout << "Destructor of Parent class was called!" << std::endl;
    }

