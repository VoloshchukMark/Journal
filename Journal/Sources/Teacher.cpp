#include "../rang.hpp"
#include "../Headers/Teacher.h"
#include "../Headers/Person.h"
#include "../Headers/Interface.h"

#include <iostream>

void Teacher::updateInfo(int newId, std::string newName,std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newShortName){
    Person::updateInfo(newId, newName, newSurname, newPatromymic, newAge, newSex, "");
    shortName = new std::string(newShortName);
}

void Teacher::displayInfo(){
    std::cout << "================================" << std::endl;
    this->displayName();
    this->displaySurname();
    this->displayPatronymic();
    this->displayShortName();
    this->displaySex();
    this->displayAge();
    std::cout << "================================" << std::endl;
}

void Teacher::setShortName(std::string& newShortName){
    shortName = new std::string(newShortName);
}
std::string Teacher::getShortName(){
    return* shortName;
}
void Teacher::displayShortName(){
    std::cout << "Short name: " << getShortName() << std::endl;
}




Teacher::Teacher()
    :Teacher(0, "None", "None", "None", 0, "None", "None", "None") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress, std::string newShortName)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress) {
        shortName = new std::string(newShortName);
        if(showConDesMessages) std::cout << rang::fg::cyan << "Constructor of Teacher class was called!" << rang::fg::reset << std::endl;
    }


Teacher::~Teacher() {
    delete shortName;
    if(showConDesMessages) std::cout << rang::fg::blue << "Destructor of Teacher class was called!" << rang::fg::reset << std::endl;
    }
