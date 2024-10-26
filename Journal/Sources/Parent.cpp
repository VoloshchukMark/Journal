#include "../rang.hpp"
#include "../Headers/Parent.h"
#include "../Headers/Person.h"

#include <iostream>


std::string Parent::getWork(){
    return *work;
}
void Parent::setWork(std::string newWork){
    work = new std::string(newWork);
}
void Parent::displayWork(){
    std::cout << "Work: ";
    if(this->getWork() == "None "){ std::cout << "[Empty]" << std::endl;}
    else{std::cout << this->getWork() << std::endl;}
}

void Parent::updateInfo(int newId, std::string newName,std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newAddress, std::string newWork){
    Person::updateInfo(newId, newName, newSurname, newPatromymic, newAge, newSex, newAddress);
    work = new std::string(newWork);
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
        std::cout << rang::fg::cyan << "Constructor of Parent class was called!" << rang::fg::reset << std::endl;
    }

Parent::~Parent() {
    delete work;
    std::cout << rang::fg::blue << "Destructor of Parent class was called!" << rang::fg::reset << std::endl;
    }

