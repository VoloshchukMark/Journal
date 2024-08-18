#include "../Headers/Student.h"

#include "../Headers/Person.h"

#include <iostream>


std::string Student::getAddress()
{
    return address;
}

void Student::setAddress(std::string newAddress)
{
    address = newAddress;
}

void Student::displayId(){
    std::cout << "ID: " << getId() << std::endl;
}
void Student::displayName(){
    std::cout << "Name: " << getName() << std::endl;
}
void Student::displaySurname(){
    std::cout << "Surname: " << getSurname() << std::endl;
}
void Student::displayPatronymic(){
    std::cout << "Patronymic: " << getPatronymic() << std::endl;
}
void Student::displayAge(){
    std::cout << "Age: " << getAge() << std::endl;
}
void Student::displaySex(){
    std::cout << "Sex: " << getSex() << std::endl;
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
Student::Student(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex), address{newAddress} {}

