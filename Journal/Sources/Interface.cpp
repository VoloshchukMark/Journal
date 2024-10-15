#include "../rang.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

#include "Interface.h"


int Interface::startMenu(){
    system("cls");
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
    baseOfStudents.clear();
    Student temporaryStudent;
    std::ifstream loadingStudents("./data/students.txt");
    if(!loadingStudents.is_open()){std::cout << "Not opened" << std::endl;}
    if(loadingStudents.peek() != std::ifstream::traits_type::eof()){
        do {
            std::string newName, newSurname, newPatronymic, newSex, newAddress, check;
            int newId, newAge;
            loadingStudents>>newId>>newName>>newSurname>>newPatronymic>>newAge>>newSex>>newAddress;
            temporaryStudent.updateInfo(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress);
            baseOfStudents.push_back(temporaryStudent);
//            temporaryStudent.displayInfo();
            loadingStudents>>check;
        } while(!loadingStudents.eof());
        baseOfStudents.pop_back();
//        baseOfStudents.back().displayInfo();
//        std::cin.get();
    return;
    } else{
        std::cout << "This file is empty!";}
}

void Interface::createStudent(){
    system("cls");
    std::ofstream creatingStudent("data/students.txt", std::ios::app);
    std::string newName, newSurname, newPatronymic, newSex, newAddress, check;
    int newId, newAge;
    if(creatingStudent.is_open()){
       newId = (baseOfStudents.back().getId()) + 1;
       std::cout << baseOfStudents.back().getName() << std::endl;
       std::cout << newId << std::endl;
       std::string uncheckedNewName, uncheckedNewSurname, uncheckedNewPatronymic, uncheckedNewAge, uncheckedNewSex, uncheckedNewAddress;

       std::cout << "Enter the first name: ";
       std::getline(std::cin, uncheckedNewName);
       newName = nsp_check(uncheckedNewName);
       std::cout << "Enter the last name: ";
       std::getline(std::cin, uncheckedNewSurname);
       newSurname = nsp_check(uncheckedNewSurname);
       std::cout << "Enter the patronymic: ";
       std::getline(std::cin, uncheckedNewPatronymic);
       newPatronymic = nsp_check(uncheckedNewPatronymic);

       std::cout << "Enter the age: ";
       std::getline(std::cin, uncheckedNewAge);
       newAge = age_check(uncheckedNewAge);

       std::cout << "Choose the sex (" << rang::style::underline << "Male/Female/Other" << rang::style::reset << "): ";
       std::getline(std::cin, uncheckedNewSex);
       newSex = sex_check(uncheckedNewSex);

        std::cout << "Write down the address (Be careful, this information will not be processed!)\n>";
        std::getline(std::cin, uncheckedNewAddress);
        newAddress = address_check(uncheckedNewAddress);

        creatingStudent<<newId<<" "<<newName<<" "<<newSurname<<" "<<newPatronymic<<" "<<newAge<<" "<<newSex<<" "<<newAddress<<std::endl;
        std::cout << "The information was successfully recorded!\n";
        std::cin.get();
       }
//    std::cout << baseOfStudents.back().getId();
    return;
}

std::string Interface::nsp_check(std::string item) {
    std::vector<std::string> separatedItem;
    char* charNewItem = new char[item.length() + 1]; //
    std::strcpy(charNewItem, item.c_str());

    char* cleanedItem = strtok(charNewItem, " ,.!?");
    while (cleanedItem != nullptr) {
        separatedItem.push_back(cleanedItem);
        cleanedItem = strtok(nullptr, " ,.!? &#");
    }
    delete[] charNewItem;
    std::string firstItem = separatedItem.front();
    if(separatedItem.size() > 1){
        std::cout << "You have inserted more than one word. We will take only the first one. Do you agree?\n";
        std::cout << "1.Yes \n2.Rewrite\n\n>";
        std::string decition;
        std::cin >> decition;
        if(decition == "1"){
            system("cls");
            return firstItem;
        } else if(decition == "2"){
            system("cls");
            std::string newItem;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter another variant: ";
            std::getline(std::cin, newItem);
            return nsp_check(newItem);
        }

    } else return firstItem;
}
int Interface::age_check(std::string uncheckedNewAge){
    if(containsOnlyDigits(uncheckedNewAge)){
        int checkedAge = std::stoi(uncheckedNewAge);
        return checkedAge;
    }else{
        std::cout << "You have inserted non-integer value!\nTry again: ";
        std::string anotherUncheckedNewAge;
        std::getline(std::cin, anotherUncheckedNewAge);
        return age_check(anotherUncheckedNewAge);
    }
}
std::string Interface::sex_check(std::string uncheckedNewSex){
        if(uncheckedNewSex == "male" || uncheckedNewSex == "Male"){return "Male";}
        else if(uncheckedNewSex == "female" || uncheckedNewSex == "Female"){return "Female";}
        else if(uncheckedNewSex == "other" || uncheckedNewSex == "Other"){return "Other";}
        else{
            std::cout << "Inserted information is wrong!\nTry again (choose between " << rang::style::underline << "Male/Female/Other" << rang::style::reset << "): ";
            std::string anotherUncheckedNewSex;
            std::getline(std::cin, anotherUncheckedNewSex);
            return sex_check(anotherUncheckedNewSex);
        }
}
std::string Interface::address_check(std::string uncheckedNewAddress){
    std::string checkedNewAddress = ('"' + uncheckedNewAddress + '"');
    std::cout << checkedNewAddress << std::endl << "Are you sure?\n";
    std::cout << "1.Yes \n2.Rewrite\n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(decition == "1"){
        return checkedNewAddress;
    }else if(decition == "2"){
        std::cout << "Write down the other address (Be careful, this information will not be processed!)\n>";
        std::string otherUncheckedNewAddress;
        std::getline(std::cin, otherUncheckedNewAddress);
        return address_check(uncheckedNewAddress);
    }
    return checkedNewAddress;
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



bool Interface::containsOnlyDigits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}


Interface::Interface(){}

Interface::~Interface(){
    baseOfMarks.clear();
    baseOfStudents.clear();
    std::cout << rang::fg::blue << "Destructor of Interface class was called!" << rang::fg::reset << std::endl;
}


