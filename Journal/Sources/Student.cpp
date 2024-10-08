#include "../Headers/Student.h"

#include "../Headers/Person.h"

#include <iostream>


void Student::displayInfo(){
    std::cout << "================================" << std::endl;
    this->displayName();
    this->displaySurname();
    this->displayPatronymic();
    this->displaySex();
    this->displayAge();
    this->displayAddress();
    std::cout << "================================" << std::endl;
}

Student::Student()
    :Student(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Student::Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress) {
        std::cout<< "Constructor of Student class was called!" << std::endl;
        }

Student::~Student() {
    delete marks;
    std::cout << "Destructor of Student class was called!"<< std::endl;
}
