#include "../External-libraries/rang.hpp"
#include "Marks.h"

#include <iostream>

void Marks::setIdMarks(int newIdMarks){
        idMarks = new int(newIdMarks);
}

int Marks::getIdMarks(){
    return* idMarks;
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

void Marks::displayHomeWorkMark(){
    std::cout << "Marks for homework: ";
    for(double mark : home_work){
        std::cout << mark << " ";
    }
    std::cout << "\n";
}
void Marks::displayTestMark(){
    std::cout << "Marks for tests: ";
    for(double mark : test){
        std::cout << mark << " ";
    }
    std::cout << "\n";
}
void Marks::displaySemesterMark(){
    std::cout << "Marks for semester: ";
    for(double mark : semester){
        std::cout << mark << " ";
    }
    std::cout << "\n";
}
void Marks::displayGeneralMark(){
    std::cout << "General mark: " << general << std::endl;
}

Marks::Marks(const Marks& other) {
        idMarks = new int(*(other.idMarks));
        home_work = other.home_work;
        test = other.test;
        semester = other.semester;
        general = new double(*(other.general));
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
    :Marks(0, 0.0) {}
Marks::Marks(int newIdMarks, double newGeneral){
    idMarks = new int(newIdMarks);
    general = new double(newGeneral);
    std::cout << rang::fg::cyan <<"Constructor of Marks class was called!" << rang::fg::reset << std::endl;

    }

Marks::~Marks() {
    home_work.clear();
    test.clear();
    semester.clear();
    delete general;
    std::cout << rang::fg::blue << "Destructor of Marks class was called!" << rang::style::reset << std::endl;
    }
