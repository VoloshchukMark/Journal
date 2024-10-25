#include "../Headers/Subject.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


int Subject::getIdSubject(){
    return* idSubject;
}
std::string Subject::getName(){
    return* name;
}
std::string Subject::getTeacher(){
    return* teacher;
}
int Subject::getIdTeacher(){
    return* idTeacher;
}
std::string Subject::getDescription(){
    return* description;
}


void Subject::setIdSubject(int newIdSubject){
    idSubject = new int(newIdSubject);
}
void Subject::setName(std::string newName){
    name = new std::string(newName);
}
void Subject::setTeacher(std::string newTeacher){
    teacher = new std::string(newTeacher);
}
void Subject::setIdTeacher(int newIdTeacher){
    idTeacher = new int(newIdTeacher);
}
void Subject::setDescription(std::string newDescription){
    description = new std::string(newDescription);
}


void Subject::displayName(){
    std::cout << "Name:        " << getName() << std::endl;
}
void Subject::displayTeacher(){
    std::cout << "Teacher:     " << getTeacher() << std::endl;
}
void Subject::displayDescription() {
    std::cout << "Description: ";
    if (description->size() > 80) {
        std::stringstream wholeDescription(*description);
        std::string word;
        std::string line;

        while (wholeDescription >> word) {
            if (line.size() + word.size() + 1 > 80) {
                std::cout << line << std::endl;
                std::cout << "             ";
                line.clear();
            }
            if (!line.empty()) {
                line += " ";
            }
            line += word;
        }

        if (!line.empty()) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << *description << std::endl;
        }
}


void Subject::displayInfo(){
    std::cout << "==============================================================================================" << std::endl;
    this->displayName();
    this->displayTeacher();
    this->displayDescription();
    std::cout << "==============================================================================================" << std::endl;
}

void Subject::clearData(){
    delete idSubject;
    delete name;
    delete idTeacher;
    delete teacher;
    delete description;
    idSubject = new int();
    name = new std::string();
    idTeacher = new int();
    teacher = new std::string();
    description = new std::string();
}

Subject::Subject(const Subject& other)
    : idSubject(new int(*other.idSubject)),
      name(new std::string(*other.name)),
      idTeacher(new int(*other.idTeacher)),
      teacher(new std::string(*other.teacher)),
      description(new std::string(*other.description)) {}

Subject& Subject::operator=(const Subject& other) {
    if (this == &other) return *this;
    *idSubject = *other.idSubject;
    *name = *other.name;
    *idTeacher = *other.idTeacher;
    *teacher = *other.teacher;
    *description = *other.description;
    return *this;
}


Subject::Subject()
    :Subject(0, "None", 0, "None", "None") {}
Subject::Subject(int newIdSubject, std::string newName, int newIdTeacher, std::string newTeacher, std::string newDescription) {
    idSubject = new int(newIdSubject);
    name = new std::string(newName);
    idTeacher = new int(newIdTeacher);
    teacher = new std::string(newTeacher);
    description = new std::string(newDescription);
}

Subject::~Subject(){
    delete idSubject;
    delete name;
    delete idTeacher;
    delete teacher;
    delete description;
}
