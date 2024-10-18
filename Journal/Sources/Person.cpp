#include "../rang.hpp"
#include "../Headers/Person.h"

#include <iostream>



int Person::getId() const{
    return *id;
}
std::string Person::getName() const{
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
void Person::updateInfo(int newId, std::string newName,std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newAddress){
    *id = newId;
    *name = newName;
    *surname = newSurname;
    *patronymic = newPatromymic;
    *age = newAge;
    *sex = newSex;
    *address = newAddress;
}

void Person::displayId(){
    std::cout << "ID: " << getId() << std::endl;
}
void Person::displayName(){
    std::cout << "First name: " << getName() << std::endl;
}
void Person::displaySurname(){
    std::cout << "Second name: " << getSurname() << std::endl;
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

Person::Person(const Person& other) {
        id = new int(*other.id);
        name = new std::string(*other.name);
        surname = new std::string(*other.surname);
        patronymic = new std::string(*other.patronymic);
        age = new int(*other.age);
        sex = new std::string(*other.sex);
        address = new std::string(*other.address);
    }

Person::Person(Person&& other) noexcept : id(other.id), name(other.name), surname(other.surname), patronymic(other.patronymic), age(other.age), sex(other.sex), address(other.address) {
        other.id = nullptr;
        other.name = nullptr;
        other.surname = nullptr;
        other.patronymic = nullptr;
        other.age = nullptr;
        other.sex = nullptr;
        other.address = nullptr;
    }



Person::Person()
    :Person(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Person::Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress){
    id = new int(newId);
    name = new std::string(newName);
    surname = new std::string(newSurname);
    patronymic = new std::string(newPatronymic);
    age = new int(newAge);
    sex = new std::string(newSex);
    address = new std::string(newAddress);
    std::cout << rang::fg::cyan << "Constructor of Person class was called!" << rang::fg::reset << std::endl;
}


Person::~Person() {
    delete id;
    delete name;
    delete surname;
    delete patronymic;
    delete age;
    delete sex;
    delete address;
//    std::cout << rang::fg::cyan << "Destructor of Person class was called!" << rang::fg::reset << std::endl;
}
