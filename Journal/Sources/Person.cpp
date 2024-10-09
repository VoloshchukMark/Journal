#include "../Headers/Person.h"

#include <iostream>



int Person::getId(){
    return *id;
}
std::string Person::getName(){
    return *name;
}
std::string Person::getSurname(){
    return *surname;
}
std::string Person::getPatronymic(){
    return *patronymic;
}
int Person::getAge(){
    return *age;
}
std::string Person::getSex(){
    return *sex;
}
std::string Person::getAddress(){
    return *address;
}

void Person::setId(int& newId){;
    id = new int(newId);
}
void Person::setName(std::string& newName){
    if(name != nullptr){
        delete name;
    }
    name = new std::string(newName);
}
void Person::setSurname(std::string& newSurname){
    if(surname != nullptr){
        delete surname;
    }
    surname = new std::string(newSurname);
}
void Person::setPatronymic(std::string& newPatronymic){
    if(patronymic != nullptr){
        delete patronymic;
    }
    patronymic = new std::string(newPatronymic);
}
void Person::setAge(int& newAge){
    age = new int(newAge);
}
void Person::setSex(std::string& newSex){
    if(sex != nullptr){
        delete sex;
    }
    sex = new std::string(newSex);
}
void Person::setAddress(std::string& newAddress){
    if(address != nullptr){
        delete address;
    }
    address = new std::string(newAddress);
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
void Person::displayInfo(){
    std::cout << "================================" << std::endl;
    this->displayName();
    this->displaySurname();
    this->displayPatronymic();
    this->displaySex();
    this->displayAge();
    this->displayAddress();
    std::cout << "================================\n" << std::endl;
}


Person::Person()
    :Person(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :id{&newId}, name{&newName}, surname{&newSurname}, patronymic{&newPatronymic}, age{&newAge}, sex{&newSex}, address{&newAddress} {}


Person::~Person() {
    delete id;
    delete name;
    delete surname;
    delete patronymic;
    delete age;
    delete sex;
    delete address;
}
