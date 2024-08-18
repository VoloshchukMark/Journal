#include "../Headers/Person.h"

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
std::string Person::getAddress(){
    return address;
}

void Person::setId(int newId){
    std::cout<<"Meow\n";
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
void Person::setAddress(std::string newAddress){
    address = newAddress;
}

void Person::displayId(){
    std::cout << "ID: " << getId() << std::endl;
}
void Person::displayName(){
    std::cout << "Name: " << getName() << std::endl;
}
void Person::displaySurname(){
    std::cout << "Surname: " << getSurname() << std::endl;
}
void Person::displayPatronymic(){
    std::cout << "Patronymic: " << getPatronymic() << std::endl;
}
void Person::displayAge(){
    std::cout << "Age: " << getAge() << std::endl;
}
void Person::displaySex(){
    std::cout << "Sex: " << getSex() << std::endl;
}
void Person::displayAddress(){
    std::cout << "Address: " << getAddress() << std::endl;
}

Person::Person()
    :Person(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Person::Person(int newId)
    :Person(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName)
    :Person(newId, newName, "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname)
    :Person(newId, newName, newSurname, "Unknown", 0, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Person(newId, newName, newSurname, newPatronymic, 0, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Person(newId, newName, newSurname, newPatronymic, newAge, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :id{newId}, name{newName}, surname{newSurname}, patronymic{newPatronymic}, age{newAge}, sex{newSex}, address{newAddress} {}

