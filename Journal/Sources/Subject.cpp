#include "../Headers/Subject.h"

#include <iostream>

std::string Subject::getName(){
    return name;
}
std::string Subject::getTeacher(){
    return teacher;
}
int Subject::getIdOfTeacher(){
    return idOfTeacher;
}
std::string Subject::getDescription(){
    return description;
}

void Subject::setName(std::string newName){
    name = newName;
}
void Subject::setTeacher(std::string newTeacher){
    teacher = newTeacher;
}
void Subject::setIdOfTeacher(int newIdOfTeacher){
    idOfTeacher = newIdOfTeacher;
}
void Subject::setDescription(std::string newDescription){
    description = newDescription;
}

void Subject::displayName(){
    std::cout << "Name: " << this->getName() << std::endl;
}
void Subject::displayTeacher(){
    std::cout << "Teacher: " << this->getTeacher() << std::endl;
}
void Subject::displayDescrioption(){
    std::cout << "Description: " << this->getDescription() << std::endl;
}
void Subject::displayInfo(){
    std::cout << "------------------------------------" << std::endl;
    this->displayName();
    this->displayTeacher();
    this->displayDescrioption();
    std::cout << "------------------------------------" << std::endl;
}

Subject::Subject()
    :Subject("None", "None", 0) {}
Subject::Subject(std::string newName)
    :Subject(newName, "None", 0) {}
Subject::Subject(std::string newName, std::string newTeacher)
    :Subject(newName, newTeacher, 0) {}
Subject::Subject(std::string newName, std::string newTeacher, int newIdOfTeacher)
    :name{newName}, teacher{newTeacher}, idOfTeacher{newIdOfTeacher}, description{"None"} {}
