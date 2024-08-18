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
Student::Student(int newId)
    :Student(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Student::Student(int newId, std::string newName)
    :Student(newId, newName, "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Student::Student(int newId, std::string newName, std::string newSurname)
    :Student(newId, newName, newSurname, "Unknown", 0, "Unknown", "Unknown") {}
Student::Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Student(newId, newName, newSurname, newPatronymic, 0, "Unknown", "Unknown") {}
Student::Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Student(newId, newName, newSurname, newPatronymic, newAge, "Unknown", "Unknown") {}
Student::Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex)
    :Student(newId, newName, newSurname, newPatronymic, newAge, newSex, "Unknown") {}
Student::Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress) {}

