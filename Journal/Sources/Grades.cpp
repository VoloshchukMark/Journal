#include "../External-libraries/rang.hpp"
#include "Grades.h"

#include <iostream>

void Grades::setIdGrades(int newIdGrades){
    idGrades = new int(newIdGrades);
}
void Grades::setIdSubject(int newIdSubject){
    idSubject = new int(newIdSubject);
}

int Grades::getIdGrades(){
    return* idGrades;
}
int Grades::getIdSubject(){
    return* idSubject;
}
std::vector<double> Grades::getHomeWorkGrades() const{
    return home_work;
}
std::vector<double> Grades::getTestGrades() const{
    return test;
}
std::vector<double> Grades::getSemesterGrades() const{
    return semester;
}



//    void editTestGrades(std::vector<double> insertedGrades, int coordinate);
//    void editSemesterGrades(std::vector<double> insertedGrades, int coordinate);

void Grades::clearData(){
    home_work.clear();
    test.clear();
    semester.clear();
    idGrades = new int();
    general = new double();
}


void Grades::addHomeWorkGrade(double newGrade){
    home_work.push_back(newGrade);
}

void Grades::addTestGrade(double newGrade){
    test.push_back(newGrade);
}

void Grades::addSemesterGrade(double newGrade){
    semester.push_back(newGrade);
}

void Grades::setGrades(char type, std::vector<double> newGrades){
    if(type == 'h'){home_work = newGrades;}
    else if(type == 't'){test = newGrades;}
    else if(type == 's'){semester = newGrades;}
}

void Grades::displayIdGrades(){
    std::cout << "ID of grades: " << *this->idGrades << std::endl;
}
void Grades::displayIdSubject(){
    std::cout << "ID of subject: " << *this->idSubject << std::endl;
}

void Grades::displayHomeWorkGrades(){
    std::cout << "Grades for homework: ";
    for(double grade : home_work){
        std::cout << grade << " ";
    }
    std::cout << "\n";
}
void Grades::displayTestGrades(){
    std::cout << "Grades for tests: ";
    for(double grade : test){
        std::cout << grade << " ";
    }
    std::cout << "\n";
}
void Grades::displaySemesterGrades(){
    std::cout << "Grades for semester: ";
    for(double grade : semester){
        std::cout << grade << " ";
    }
    std::cout << "\n";
}
void Grades::displayGeneralGrades(){
    std::cout << "General grade: " << *this->general << std::endl;
}
void Grades::displayAllGrades(){
    this->displayHomeWorkGrades();
    this->displayTestGrades();
    this->displaySemesterGrades();
    this->displayGeneralGrades();
    std::cout << std::endl;
}

void Grades::setGeneralGrade(double newGeneralGrade){
    delete general;
    general = new double(newGeneralGrade);
}

Grades::Grades(const Grades& other) {
        idGrades = new int(*(other.idGrades));
        home_work = other.home_work;
        test = other.test;
        semester = other.semester;
        general = new double(*(other.general));
        idSubject = new int(*other.idSubject);
    }

Grades& Grades::operator=(const Grades& other) {
        if (this != &other) {
            delete idGrades;
            delete general;

            idGrades = new int(*(other.idGrades));
            home_work = other.home_work;
            test = other.test;
            semester = other.semester;
            general = new double(*(other.general));
        }
        return *this;
}


Grades::Grades()
    :Grades(0, 0.0, 0) {}
Grades::Grades(int newIdGrades, double newGeneral, int newIdSubject){
    idGrades = new int(newIdGrades);
    general = new double(newGeneral);
    idSubject = new int(newIdSubject);
    std::cout << rang::fg::cyan <<"Constructor of Grades class was called!" << rang::fg::reset << std::endl;

    }

Grades::~Grades() {
    home_work.clear();
    test.clear();
    semester.clear();
    delete general;
//    std::cout << rang::fg::blue << "Destructor of Grades class was called!" << rang::style::reset << std::endl;
    }
