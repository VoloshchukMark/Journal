#include "../External-libraries/rang.hpp"
#include "Marks.h"

#include <iostream>

void Marks::setIdMarks(int newIdMarks){
    idMarks = new int(newIdMarks);
}
void Marks::setIdSubject(int newIdSubject){
    idSubject = new int(newIdSubject);
}

int Marks::getIdMarks(){
    return* idMarks;
}
int Marks::getIdSubject(){
    return* idSubject;
}
std::vector<double> Marks::getHomeWorkGrades() const{
    return home_work;
}
std::vector<double> Marks::getTestGrades() const{
    return test;
}
std::vector<double> Marks::getSemesterGrades() const{
    return semester;
}

void Marks::clearData(){
    home_work.clear();
    test.clear();
    semester.clear();
    idMarks = new int();
    general = new double();
}


void Marks::addHomeWorkMark(double newMark){
    home_work.push_back(newMark);
}

void Marks::addTestMark(double newMark){
    test.push_back(newMark);
}

void Marks::addSemesterMark(double newMark){
    semester.push_back(newMark);
}

void Marks::calculateGeneralMark(){
    if (general == nullptr) {
        general = new double(0.0);
    } else {
        *general = 0.0;
    }

    int counter = 0;
    for(double mark: home_work){
        *general += mark;
        counter++;
    }
    for(double mark: test){
        *general += mark;
        counter++;
    }
    for(double mark: semester){
        *general += mark;
        counter++;
    }
    *general /= counter;
}

void Marks::displayIdMarks(){
    std::cout << "ID of grades: " << *this->idMarks << std::endl;
}
void Marks::displayIdSubject(){
    std::cout << "ID of subject: " << *this->idSubject << std::endl;
}

void Marks::displayHomeWorkMark(){
    std::cout << "Grades for homework: ";
    for(double mark : home_work){
        std::cout << mark << " ";
    }
    std::cout << "\n";
}
void Marks::displayTestMark(){
    std::cout << "Grades for tests: ";
    for(double mark : test){
        std::cout << mark << " ";
    }
    std::cout << "\n";
}
void Marks::displaySemesterMark(){
    std::cout << "Grades for semester: ";
    for(double mark : semester){
        std::cout << mark << " ";
    }
    std::cout << "\n";
}
void Marks::displayGeneralMark(){
    std::cout << "General grade: " << *this->general << std::endl;
}
void Marks::displayAllMarks(){
    this->displayHomeWorkMark();
    this->displayTestMark();
    this->displaySemesterMark();
    this->displayGeneralMark();
    std::cout << std::endl;
}

void Marks::setGeneralMark(double newGeneralMark){
    delete general;
    general = new double(newGeneralMark);
}

Marks::Marks(const Marks& other) {
        idMarks = new int(*(other.idMarks));
        home_work = other.home_work;
        test = other.test;
        semester = other.semester;
        general = new double(*(other.general));
        idSubject = new int(*other.idSubject);
    }

Marks& Marks::operator=(const Marks& other) {
        if (this != &other) {
            delete idMarks;
            delete general;

            idMarks = new int(*(other.idMarks));
            home_work = other.home_work;
            test = other.test;
            semester = other.semester;
            general = new double(*(other.general));
        }
        return *this;
}


Marks::Marks()
    :Marks(0, 0.0, 0) {}
Marks::Marks(int newIdMarks, double newGeneral, int newIdSubject){
    idMarks = new int(newIdMarks);
    general = new double(newGeneral);
    idSubject = new int(newIdSubject);
    std::cout << rang::fg::cyan <<"Constructor of Marks class was called!" << rang::fg::reset << std::endl;

    }

Marks::~Marks() {
    home_work.clear();
    test.clear();
    semester.clear();
    delete general;
    std::cout << rang::fg::blue << "Destructor of Marks class was called!" << rang::style::reset << std::endl;
    }
