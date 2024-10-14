#include "../rang.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>

#include "Interface.h"


int Interface::startMenu(){
    std::cout << "MyJournal 0.1.3 \n" << std::endl;
    std::cout << "(Type '/?' for 'user manual'; type '/quit' to exit)" << std::endl;

    Sleep(500);

    std::string decition;
    std::cout << std::endl;
    std::cout << rang::fg::green << rang::style::underline << "Welcome!" << rang::fg::reset << rang::style::reset << std::endl;
    std::cout << "1.Student information. \n2.View grades. \n3.Teacher info. \n" << std::endl;
    std::cout << ">";
    std::getline(std::cin, decition);

    if(decition == "/quit"){
        return 0;
    }else if(decition == "1"){
        studentInfo();
        }
     else {
        system("cls");
        startMenu();
    }
}

void Interface::studentInfo() {
    loadStudents();
    system("cls");
    std::cout << "======================================================================================================================" << std::endl;
    std::cout << " ID " << std::setw(5) << "|| Full name " << std::setw(50) << " || Age " << std::setw(10) << " || Sex " << std::setw(15) << " || Adress " << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
    for(Student selectedStudent : baseOfStudents){
        std::cout << " " << selectedStudent.getId() << std::setw(6 - std::to_string(selectedStudent.getId()).size()) << "|| " << selectedStudent.getName() << " " << selectedStudent.getSurname() << " ";
        std::cout << selectedStudent.getPatronymic() << std::setw(54 - (selectedStudent.getName().size() + selectedStudent.getSurname().size() + selectedStudent.getPatronymic().size())) << " || " << selectedStudent.getAge();
        std::cout << std::setw(10 - std::to_string(selectedStudent.getAge()).size()) << " || " << selectedStudent.getSex();
        std::cout << std::setw(11 - selectedStudent.getSex().size()) << " ||" <<selectedStudent.getAddress() << std::endl;
    }
    std::cout << "======================================================================================================================" << std::endl;

    std::cin.get();
    return;
}

void Interface::loadStudents() {
    Student temporaryStudent;
    std::cout << "meow1" << std::endl;
    std::ifstream loadingStudents("./data/students.txt");
    if(!loadingStudents.is_open()){std::cout << "Not opened" << std::endl;}
    std::cout << "meow2" << std::endl;
    if(loadingStudents.peek() != std::ifstream::traits_type::eof()){
        do {
            std::cout << "meow3" << std::endl;
            std::string newName, newSurname, newPatronymic, newSex, newAddress, check;
            int newId, newAge;
            loadingStudents>>newId>>newName>>newSurname>>newPatronymic>>newAge>>newSex>>newAddress;
            std::cout << "meow4" << std::endl;
            temporaryStudent.updateInfo(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress);
            baseOfStudents.push_back(temporaryStudent);
            temporaryStudent.displayInfo();
            loadingStudents>>check;
            if(check == "!") {break;}
        } while(!loadingStudents.eof());
    return;
    } else{
        std::cout << "This file is empty!";}
}

void Interface::importMarks()
{
    std::ifstream importingMarks("./data/marks.txt");
    std::cout << "File found!\n";
    Marks marksItterator;
    int fileID;
    std::string itterator;
    importingMarks>>fileID;
    while(!importingMarks.eof()){
        marksItterator.setIdMarks(fileID);
        std::cout << "ID found!\n";
        importingMarks>>itterator;
        while(itterator != ">"){
            if(itterator == "!"){
                importingMarks>>itterator;
                std::cout << "Importing homework grades is started!\n";
                do{
                    marksItterator.addHomeWorkMark(stod(itterator));
                    importingMarks>>itterator;
                } while(itterator != "?");
                std::cout << "Importing homework grades is complete!\n";
            }
            if(itterator == "?"){
                importingMarks>>itterator;
                std::cout << "Importing test grades is started!\n";
                do{
                    marksItterator.addTestMark(stod(itterator));
                    importingMarks>>itterator;
                } while(itterator != "#");
                std::cout << "Importing test grades is complete!\n";
            }
            if(itterator == "#"){
                importingMarks>>itterator;
                std::cout << "Importing semester grades is started!\n";
                do{
                    marksItterator.addSemesterMark(stod(itterator));
                    importingMarks>>itterator;
                } while(itterator != ">");
                std::cout << "Importing semester grades is complete!\n";
            }
        }
        std::cout << itterator << std::endl;
        std::cout << "Poop\n";
        importingMarks>>fileID;
        std::cout << "but why?\n";
        baseOfMarks.push_back(marksItterator);
        marksItterator.clearData();
        std::cout << "Data of marksItterator was cleared!\n";
    }
    std::cout << "Fucking cycle!!!!\n\n";
}

void Interface::connectMarksToStudent(Student* selectedStudent){
    int idStudent = selectedStudent->getId();
    for(Marks selectedMarks : baseOfMarks){
        if(selectedMarks.getIdMarks() == idStudent){
            std::cout << "Connected!\n";
            std::cout << selectedMarks.getIdMarks() << std::endl;
            return;
        }
    }
    std::cout << "No such student!\n";
    return;
}


Interface::Interface(){}

Interface::~Interface(){
    baseOfMarks.clear();
    baseOfStudents.clear();
    std::cout << rang::fg::blue << "Destructor of Interface class was called!" << rang::fg::reset << std::endl;
}


