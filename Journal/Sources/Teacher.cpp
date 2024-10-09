#include "../Headers/Teacher.h"

#include "../Headers/Person.h"

#include <iostream>

void Teacher::displayInfo(){
    std::cout << "================================" << std::endl;
    this->displayName();
    this->displaySurname();
    this->displayPatronymic();
    this->displaySex();
    this->displayAge();
    this->displayAddress();
    std::cout << "================================" << std::endl;
}

void Teacher::addSubject(std::string newName){
    Subject subject(newName, this->getName(), this->getId());
    std::cout << "Write a short desctiption of this subject (up to 50 symbols):\n";
    std::string description;
    std::getline(std::cin, description);
    subject.setDescription(description);
    subjects.push_back(subject);
    std::cout << "Subject was added successfuly!\n";
}

void Teacher::displayInfoOfSubjects(){
    for(Subject &subj : subjects){
        subj.displayInfo();
    }
}

Teacher::Teacher()
    :Teacher(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress) {
        std::cout << "Constructor of Teacher class was called!" << std::endl;
        }

Teacher::~Teacher() {
    std::cout << "Destructor of Teacher class was called!" << std::endl;
    }
