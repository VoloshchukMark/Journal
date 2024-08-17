#include "Person.h"

#include <iostream>



int Person::getId(){
    return id;
}
std::string Person::getName(){
    return name;
}
std::string Person::getSurname(){
    return surname;
}
std::string Person::getPatronymic(){
    return patronymic;
}
int Person::getAge(){
    return age;
}
std::string Person::getSex(){
    return sex;
}

void Person::setId(int newId){
    id = newId;
}
void Person::setName(std::string newName){
    name = newName;
}
void Person::setSurname(std::string newSurname){
    surname = newSurname;
}
void Person::setPatronymic(std::string newPatronymic){
    patronymic = newPatronymic;
}
void Person::setAge(int newAge){
    age = newAge;
}
void Person::setSex(std::string newSex){
    sex = newSex;
}

void Person::displayId(){
    std::cout << "ID: " << getId();
}
void Person::displayName(){
    std::cout << "Name: " << getName();
}
void Person::isplaySurname(){
    std::cout << "Surname: " << getSurname();
}
void Person::displayPatronymic(){
    std::cout << "Patronymic: " << getPatronymic();
}
void Person::displayAge(){
    std::cout << "Age: " << getAge();
}
void Person::displaySex(){
    std::cout << "Sex: " << getSex();
}

Person::Person()
    :Person(0, "Unknown", "Unknown", "Unknown", 0, "Unknown") {}
Person::Person(int newId)
    :Person(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown") {}
Person::Person(int newId, std::string newName)
    :Person(newId, newName, "Unknown", "Unknown", 0, "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname)
    :Person(newId, newName, newSurname, "Unknown", 0, "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Person(newId, newName, newSurname, newPatronymic, 0, "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Person(newId, newName, newSurname, newPatronymic, newAge, "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex)
    :id{newId}, name{newName}, surname{newSurname}, patronymic{newPatronymic}, age{newAge}, sex{newSex} {}
