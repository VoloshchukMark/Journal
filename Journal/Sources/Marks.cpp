#include "Marks.h"

#include <iostream>

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
    general = 0;
    int counter = 0;
    for(double mark: home_work){
        general += mark;
        counter++;
    }
    for(double mark: test){
        general += mark;
        counter++;
    }
    for(double mark: semester){
        general += mark;
        counter++;
    }
    general /= counter;
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
