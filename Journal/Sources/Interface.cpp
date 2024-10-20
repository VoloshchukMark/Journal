#include "../rang.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

#include "Interface.h"
#include "BubbleSort.h"



int Interface::startMenu(){
    system("cls");
    std::cout << "MyJournal 0.3.4 \n" << std::endl;
    std::cout << "(Type '/?' for 'user manual';" << std::endl;

    Sleep(500);

    std::string decition;
    std::cout << std::endl;
    std::cout << rang::fg::green << rang::style::underline << "Welcome!" << rang::fg::reset << rang::style::reset << std::endl;
    std::cout << "1.Students information \n2.View grades \n3.Teacher info \n0.Exit \n>";
    std::getline(std::cin, decition);

    if(decition == "1"){
        studentInfo();
    }else if(decition == "2"){
        selectSubject();
    }else if(decition == "0"){
        return 0;
    }else {
        system("cls");
    }
    startMenu();
}

void sortStudents();
void compareById();
void compareByName();
void bubbleSort();

int Interface::studentInfo() {
    if(shouldLoad){loadStudents();}
    system("cls");
    std::cout << "=======================================================================================================================" << std::endl;
    std::cout << " ID " << std::setw(5) << "|| Full name " << std::setw(50) << " || Age " << std::setw(10) << " || Sex " << std::setw(16) << " || Address " << std::endl;
    std::cout << "----++------------------------------------------------------++--------++----------++-----------------------------------" << std::endl;
    for(Student selectedStudent : baseOfStudents){
        std::cout << " " << selectedStudent.getId() << std::setw(6 - std::to_string(selectedStudent.getId()).size()) << "|| " << selectedStudent.getName() << " " << selectedStudent.getSurname() << " ";
        std::cout << selectedStudent.getPatronymic() << std::setw(54 - (selectedStudent.getName().size() + selectedStudent.getSurname().size() + selectedStudent.getPatronymic().size())) << " || " << selectedStudent.getAge();
        std::cout << std::setw(10 - std::to_string(selectedStudent.getAge()).size()) << " || " << selectedStudent.getSex();
        std::cout << std::setw(12 - selectedStudent.getSex().size()) << " || " <<selectedStudent.getAddress() << std::endl;
    }
    std::cout << "=======================================================================================================================" << std::endl << std::endl;
    Sleep(100);
    std::cout << "Choose an action:\n1.View student information \n2.Add student information \n3.Erase student information \n4.Sort list\n5.Back\n>";

    std::string decition;
    std::getline(std::cin, decition);
    if(decition == "1"){
        viewStudent();
    }else if(decition == "2"){
        createStudent();
    }else if(decition == "3"){
        eraseStudent();
    }else if(decition == "4"){
        sortStudents();
    }else if(decition == "5"){
        shouldLoad = true;
        return 0;
    }else{
        system("cls");
    }
    studentInfo();
}

void Interface::saveStudents(){
    std::ofstream savingStudents("./data/students.txt", std::ios::trunc);
    for(int i = 0; i < baseOfStudents.size(); i++){
        savingStudents<<(i + 1)<<" "<<baseOfStudents[i].getName()<<" "<<baseOfStudents[i].getSurname()<<" "
                      <<baseOfStudents[i].getPatronymic()<<" "<<baseOfStudents[i].getAge()<<" "
                      <<baseOfStudents[i].getSex()<<" ' "<<baseOfStudents[i].getAddress()<<"' >"<<std::endl;

    }
}

void Interface::selectSubject(){
    clearAllBases();
    system("cls");
    importSubjects();
    for(Subject thatOneSubject : baseOfSubjects){
        std::cout << thatOneSubject.getIdSubject() << "." << thatOneSubject.getName() << std::endl;
    }
    std::cout << "0.Go back \n\nChoose the subject: \n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(!decition.empty()){
        if(decition == "0"){return;}
        for(Subject thatOneSubject : baseOfSubjects){
            if(thatOneSubject.getIdSubject() == stoi(decition)){
                gradesInfo(stoi(decition), 1);
                return;
            }
        }
    }
    std::cout << "Error! No such Subject ID!";
    std::cin.get();
    clearAllBases();
    return;
}

void Interface::gradesInfo(int idSubject, int newPage){
    int page = newPage;
    clearAllBases();
    loadStudents();
    importGrades();
    importSubjects();
    system("cls");
    std::cout << rang::style::bold << "================|\0" << rang::style::underline << " " << baseOfSubjects[idSubject - 1].getName() << rang::style::reset << rang::style::bold << "|";
    for(int i = 0; i < 100 - baseOfSubjects[idSubject - 1].getName().size(); i++){
        std::cout << "=";
    }
    std::cout << rang::style::reset << "\n";
    std::cout << rang::style::underline;
    std::cout << "ID " << std::setw(5) << "|| Full name " << std::setw(38) << " || Home work " << std::setw(46) << " || Test " << std::setw(19) << " ||Semest.||" << std::endl;
    for(Student thatOneStudent : baseOfStudents){
//        std::cout << "---++------------------------------------++-------------------------------------------------++--------------++-------++" << std::endl;
        std::cout << " " << thatOneStudent.getId() << std::setw(4 - std::to_string(thatOneStudent.getId()).size()) << "||";
        std::cout << " " << thatOneStudent.getName() << " " << thatOneStudent.getSurname() << " " << thatOneStudent.getPatronymic()
                  <<std::setw(35 - (thatOneStudent.getName().size() + thatOneStudent.getSurname().size() + thatOneStudent.getPatronymic().size()))
                  <<"||";
        for(Grades thatOneListOfGrades : baseOfGrades){
            if(thatOneListOfGrades.getIdSubject() == idSubject && thatOneListOfGrades.getIdGrades() == thatOneStudent.getId()){
                std::vector<double> homeWorkGrades = thatOneListOfGrades.getHomeWorkGrades();
                for(int i = (page * 10) - 10; i < (page * 10); i++){
                    std::cout << " " << homeWorkGrades[i] << std::setw(11 - std::to_string(homeWorkGrades[i]).size()) << " |";
                }
                std::cout << "|";
                std::vector<double> testGrades = thatOneListOfGrades.getTestGrades();
                for(int i = (page * 3) - 3; i < (page * 3); i++){
                    std::cout << " " << testGrades[i] << std::setw(11 - std::to_string(testGrades[i]).size()) << " |";
                }
                std::cout << "|";
                std::vector<double> semesterGrades = thatOneListOfGrades.getSemesterGrades();
                std::cout << "   " << semesterGrades[page - 1] << std::setw(12 - std::to_string(semesterGrades[page - 1]).size()) << " |";
                std::cout << "|\n";
            }
        }

//        std::cout << "\n---++------------------------------------++-------------------------------------------------++--------------++-------++" << std::endl;
    }
    std::cout << rang::style::reset;
    std::cout << rang::style::bold << "=======================================================================================================================\n" << rang::bg::reset;
    std::cout << "(Enter the 'arrows' to navigate through pages)\n< " << page << " >\n\n";
    std::cout << "Choose an action:\n1.Edit grades \n2.Change subject \n0.Back \n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(decition == "<"){
        if(page == 1){
            gradesInfo(idSubject, page);
            return;
        }
        clearAllBases();
        gradesInfo(idSubject, page - 1);
        return;
    }else if(decition == ">"){
        if(baseOfGrades[0].getHomeWorkGrades().size() == (page * 10)){
            gradesInfo(idSubject, page);
            return;
        }
        clearAllBases();
        gradesInfo(idSubject, page + 1);
        return;
    }else if(decition == "1"){
        std::cout << "Enter ID of grades you want to edit: ";
        std::string idDecition;
        std::getline(std::cin, idDecition);
        editGrades(idSubject, stoi(idDecition));
        return;
    }else if(decition == "2"){
        selectSubject();
        return;
    }else if(decition == "0"){
        clearAllBases();
        return;
    }
    gradesInfo(idSubject, newPage);
}

void Interface::editGrades(int idSubject, int idGrades){
    for(Grades thatOneGrades : baseOfGrades){
        if(thatOneGrades.getIdGrades() == idGrades && thatOneGrades.getIdSubject() == idSubject){
            std::vector<double> homeWorkGrades = thatOneGrades.getHomeWorkGrades();
            std::vector<double> testGrades = thatOneGrades.getTestGrades();
            std::vector<double> semesterGrades = thatOneGrades.getSemesterGrades();
ahah:       system("cls");
            displayGradesToEdit("Home work", homeWorkGrades);
            displayGradesToEdit("Test", testGrades);
            displayGradesToEdit("Semester", semesterGrades);

            std::cout << "\nEnter type (!/?/#) and a coordinate of grade you want to edit (split it by 'space'): ";
            std::string insertion;
            std::getline(std::cin, insertion);
            if(insertion.empty()){std::cout << "Error! Entered nothing!\n"; std::cin.get(); goto ahah;}
            std::stringstream separator(insertion);
            std::string index, coordinate;
            separator>>index>>coordinate;
            std::cout << "[" << index << "]" << std::endl;
            if(index != "!" && index != "?" && index != "#"){std::cout << "No such index!\n"; std::cin.get(); goto ahah;}
            std::cout << "Insert new value: ";
            std::string newValue;
            std::getline(std::cin, newValue);
            if(index == "!"){
                homeWorkGrades = changeGrade(homeWorkGrades, stoi(coordinate), stod(newValue));
            }else if(index == "?"){
                testGrades = changeGrade(testGrades, stoi(coordinate), stod(newValue));
            }else if(index == "#"){
                semesterGrades = changeGrade(semesterGrades, stoi(coordinate), stod(newValue));
            }
            system("cls");
            displayGradesToEdit("Home work", homeWorkGrades);
            displayGradesToEdit("Test", testGrades);
            displayGradesToEdit("Semester", semesterGrades);
            std::cout << "\nChanges are completed! \n\nChoose an action: \n1.Continue to change \n2.Save all and back to grages list \n3.Cancel all changes\n>";
            std::string decition;
            std::getline(std::cin, decition);
            if(decition == "1"){}
            else if(decition == "2"){
                for(Grades anotherOneGrade : baseOfGrades){
                    if(anotherOneGrade.getIdGrades() == idGrades && anotherOneGrade.getIdSubject() == idSubject){
                        baseOfGrades[(idGrades - 1) + ((idSubject - 1) * baseOfGrades.back().getIdGrades())].setGrades('h', homeWorkGrades);
                        baseOfGrades[(idGrades - 1) + ((idSubject - 1) * baseOfGrades.back().getIdGrades())].setGrades('t', testGrades);
                        baseOfGrades[(idGrades - 1) + ((idSubject - 1) * baseOfGrades.back().getIdGrades())].setGrades('s', semesterGrades);
                    }
                }
                saveGrades();
                gradesInfo(idSubject, 1);
                return;
            }
            else if(decition == "3"){
                gradesInfo(1, 1);
                return;
            }
            goto ahah;

        }
    }
    std::cin.get();
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
            loadingStudents>>newId>>newName>>newSurname>>newPatronymic>>newAge>>newSex;
//            std::cout << "Basic data was successfuly imported!\n";
            loadingStudents>>check;
            if(check == "'"){
                std::string wholeAddress;
                loadingStudents>>check;
                while(check != "'"){
                    newAddress += (check + " ");
                    loadingStudents>>check;
                }
            }
//            std::cout << "Address was successfuly imported!\n";
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
    baseOfStudents.clear();
    loadStudents();
    system("cls");
    std::ofstream creatingStudent("data/students.txt", std::ios::app);
    std::string newName, newSurname, newPatronymic, newSex, newAddress, check;
    int newId, newAge;
    if(creatingStudent.is_open()){
       newId = (baseOfStudents.back().getId()) + 1;
       std::cout << baseOfStudents.back().getName() << std::endl;
       std::cout << newId << std::endl;
       std::string uncheckedNewName, uncheckedNewSurname, uncheckedNewPatronymic, uncheckedNewAge, uncheckedNewSex, uncheckedNewAddress;

       system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the first name: ";
       std::getline(std::cin, uncheckedNewName);
       if(uncheckedNewName == "<"){goto cncl;}
       newName = nsp_check(uncheckedNewName);
       system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the last name: ";
       std::getline(std::cin, uncheckedNewSurname);
       if(uncheckedNewSurname == "<"){goto cncl;}
       newSurname = nsp_check(uncheckedNewSurname);
       system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the patronymic: ";
       std::getline(std::cin, uncheckedNewPatronymic);
       if(uncheckedNewPatronymic == "<"){goto cncl;}
       newPatronymic = nsp_check(uncheckedNewPatronymic);

        system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the age: ";
       std::getline(std::cin, uncheckedNewAge);
       if(uncheckedNewAge == "<"){goto cncl;}
       newAge = age_check(uncheckedNewAge);

       system("cls");
       std::cout << "(Write '<' to go back to the list)\nChoose the sex (" << rang::style::underline << "Male/Female/Other" << rang::style::reset << "): ";
       std::getline(std::cin, uncheckedNewSex);
       if(uncheckedNewSex == "<"){goto cncl;}
       newSex = sex_check(uncheckedNewSex);

       system("cls");
       std::cout << "(Write '<' to go back to the list)\nWrite down the address (Be careful, this information will not be processed!)\n>";
       std::getline(std::cin, uncheckedNewAddress);
       if(uncheckedNewAddress == "<"){goto cncl;}
       newAddress = address_check(uncheckedNewAddress);

       system("cls");
       creatingStudent<<newId<<" "<<newName<<" "<<newSurname<<" "<<newPatronymic<<" "<<newAge<<" "<<newSex<<" "<<newAddress<<" >"<<std::endl;
       creatingStudent.close();
a1:    std::cout << "The information was successfully recorded!\n";
       Sleep(300);
       std::cout << "Back to students information...";
       std::cin.get();
cncl: shouldLoad = true;
       return;
    }
}

void Interface::eraseStudent() {
    baseOfStudents.clear();
    loadStudents();
    importGrades();
    std::cout << "Enter the ID of the student whose data you want to erase (Write '<' to cancel): ";
    std::string doomedStudent;
    std::getline(std::cin, doomedStudent);
    if(doomedStudent.empty()){std::cout << "Error! Empty insertion! Back to the list..."; std::cin.get(); return;}
    if(doomedStudent == "<"){return;}
    if (!containsOnlyDigits(doomedStudent)) {
        std::cout << "Error! ID consist only from digits!";
        std::cin.get();
        baseOfGrades.clear();
        return;
    }

    int studentIdToErase = std::stoi(doomedStudent);
    for (auto it = baseOfStudents.begin(); it != baseOfStudents.end(); ++it) {
        if (it->getId() == studentIdToErase) {
            std::cout << "You sure you want to erase data about student " << it->getName() << " " << it->getSurname() << "?\n";
            std::cout << "1.Yes \n2.Back \n>";
            std::string decision;
            std::getline(std::cin, decision);
            if (decision == "1") {
                eraseGrades(stoi(doomedStudent));
                baseOfStudents.erase(it);
                saveStudents();
                std::cout << "Student info has been deleted successfully! \nBack to the student list...";
                shouldLoad = true;
                std::cin.get();
                baseOfGrades.clear();
                return;
            } else if (decision == "2") {
                baseOfGrades.clear();
                return;
            } else {
                std::cout << "Wrong insertion!\n\n";
                std::cin.get();
                baseOfGrades.clear();
                return;
            }
        }
    }
    std::cout << "Student wasn't found!\n";
    std::cin.get();
}


void Interface::sortStudents(){
    bool increase = true;
s:  system("cls");
    std::cout << "Sort by (";
    if(increase){
        std::cout << rang::style::underline << "Increase" << rang::style::reset;
    }else{ std::cout << rang::style::underline << "Decrease" << rang::style::reset;}
    std::cout << "): \n1.ID \n2.Name \n3.Surname \n4.Age \n5.Sex \n6.Address \n7.Switch sort direction \n8.Back \n\n>";
    std::string decition;
    std::getline(std::cin, decition);
    system("cls");
    if(decition.empty()) {std::cout << "Error! Empty insertion! Back to the list..."; std::cin.get(); return;}
    if(!containsOnlyDigits(decition)) {std::cout << "Error! Insertion must contain only digits! Back to the list..."; std::cin.get(); return;}
    if(decition == "1" && increase){
        bubbleSortInc(baseOfStudents, "i");
        shouldLoad = false;
        return;
    }else if(decition == "1" && !increase){
        bubbleSortDec(baseOfStudents, "i");
        shouldLoad = false;
        return;
    }else if(decition == "2" && increase){
        bubbleSortInc(baseOfStudents, "n");
        shouldLoad = false;
        return;
    }else if(decition == "2" && !increase){
        bubbleSortDec(baseOfStudents, "n");
        shouldLoad = false;
        return;
    }else if(decition == "3" && increase){
        bubbleSortInc(baseOfStudents, "sn");
        shouldLoad = false;
        return;
    }else if(decition == "3" && !increase){
        bubbleSortDec(baseOfStudents, "sn");
        shouldLoad = false;
        return;
    }else if(decition == "4" && increase){
        bubbleSortInc(baseOfStudents, "ag");
        shouldLoad = false;
        return;
    }else if(decition == "4" && !increase){
        bubbleSortDec(baseOfStudents, "ag");
        shouldLoad = false;
        return;
    }else if(decition == "5" && increase){
        bubbleSortInc(baseOfStudents, "s");
        shouldLoad = false;
        return;
    }else if(decition == "5" && !increase){
        bubbleSortDec(baseOfStudents, "s");
        shouldLoad = false;
        return;
    }else if(decition == "6" && increase){
        bubbleSortInc(baseOfStudents, "ad");
        shouldLoad = false;
        return;
    }else if(decition == "6" && !increase){
        bubbleSortDec(baseOfStudents, "ad");
        shouldLoad = false;
        return;
    }else if(decition == "7" && increase){
        increase = false;
        goto s;
    }else if(decition == "7" && !increase){
        increase = true;
        goto s;
    }else if(decition == "8"){
        return;
    }
    goto s;
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
    std::string checkedNewAddress = ("' " + uncheckedNewAddress + " '");
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
        return address_check(otherUncheckedNewAddress);
    }
    return checkedNewAddress;
}

std::string Interface::selectStudent(std::string selectedId){
    loadStudents();
    for(Student eachStudent : baseOfStudents){
        if(eachStudent.getId() == stoi(selectedId)){
            delete selectedStudent;
            selectedStudent = new Student(eachStudent);
            std::cout << "Student has been selected!\n";
            Sleep(1000);
            return "1";
        }
    }
    std::cout << "Student wasn't found((((";
    baseOfStudents.clear();
    std::cin.get();
    return 0;
}

void viewStudentSubjects();
void Interface::viewStudent(){
    clearAllBases();
    std::string selection;
    std::cout << "Enter ID of the student you want to check: ";
    std::getline(std::cin, selection);
    if(selection.empty()){std::cout << "Error! Entered nothing!\n"; std::cin.get(); return;}
    std::string result = selectStudent(selection);
    if(result == "1"){
a2:     baseOfGrades.clear();
        baseOfSubjects.clear();
        importGrades();
        importSubjects();
        int checkConnect = connectGradesToStudent(selectedStudent);
        if(checkConnect == 0){return;}
        system("cls");
        selectedStudent->displayInfo();
        for(Subject thisSubject : baseOfSubjects){
            std::cout << "*" << thisSubject.getName() << std::endl;
        }
        std::cout << "\n";
        std::cout << "Action: \n1.View grades \n2.Edit student \n0.Back \n\n>";
        std::string decition;
        std::getline(std::cin, decition);
        if(!decition.empty()){
            if(decition == "1"){
                baseOfGrades.clear();
                baseOfSubjects.clear();
                viewStudentSubjects();
            }else if(decition == "0"){
                selectedGrades->clearData();
                selectedSubject->clearData();
                clearAllBases();
                shouldLoad = true;
                return;
            }
        }else{
            std::cout << "Wrong insertion!\n";
            std::cin.get();
            baseOfGrades.clear();
            baseOfSubjects.clear();
            goto a2;
        }
    }else{return;}
    goto a2;
}
void Interface::viewStudentSubjects(){
a3: baseOfGrades.clear();
    baseOfSubjects.clear();
    importGrades();
    importSubjects();
    int checkConnect = connectGradesToStudent(selectedStudent);
    if(checkConnect == 0){return;}
    system("cls");
    selectedStudent->displayInfo();
//    selectedStudent->displayId();
//    std::cout << selectedStudent->getId();
    for(Subject thisSubject : baseOfSubjects){
        std::cout << thisSubject.getIdSubject() << "." << thisSubject.getName() << std::endl;
    }
    std::cout << "\n";
    std::cout << "Action: \n*View grades \n*Edit student \n0.Back \n\nEnter subject ID: \n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(!decition.empty()){
        for(Subject thisSubject : baseOfSubjects){
            if(thisSubject.getIdSubject() == stoi(decition)){
                baseOfGrades.clear();
                viewGrades(thisSubject.getName(), thisSubject.getIdSubject(), selectedStudent->getId());
                return;
            }
            else if(decition == "0"){
                baseOfGrades.clear();
                baseOfSubjects.clear();
                return;
            }
        }
    }
    std::cout << "Wrong insertion!\n";
    std::cin.get();
    baseOfGrades.clear();
    baseOfSubjects.clear();
    goto a3;
}

void Interface::viewGrades(std::string name, int idSubject, int idGrades){
    importGrades();
    std::cout << baseOfGrades.front().getIdSubject();
    system("cls");
    for(Grades thatOneListOfGrades : baseOfGrades){
        if(thatOneListOfGrades.getIdGrades() == idGrades && thatOneListOfGrades.getIdSubject() == idSubject){
            std::cout << rang::style::bold << rang::style::underline << "Subject: " << name << rang::style::reset << std::endl;
            thatOneListOfGrades.displayAllGrades();
            std::cin.get();
            return;
        }
    }
    std::cin.get();
}


void Interface::importGrades()
{
    std::ifstream importingGrades("./data/grades.txt");
//    std::cout << "File found!\n";
    Grades gradesItterator;
    std::string itterator;
    importingGrades>>itterator;
    while(!importingGrades.eof()){
        gradesItterator.setIdSubject(std::stoi(itterator));
//        std::cout << "ID of Subject found!\n";
        importingGrades>>itterator;
        gradesItterator.setIdGrades(stoi(itterator));
//        std::cout << "ID found!\n";
        importingGrades>>itterator;
        while(itterator != ">"){
            if(itterator == "!"){
                importingGrades>>itterator;
//                std::cout << "Importing homework grades is started!\n";
                do{
                    gradesItterator.addHomeWorkGrade(stod(itterator));
                    importingGrades>>itterator;
                } while(itterator != "?");
//                std::cout << "Importing homework grades is complete!\n";
            }
            if(itterator == "?"){
                importingGrades>>itterator;
//                std::cout << "Importing test grades is started!\n";
                do{
                    gradesItterator.addTestGrade(stod(itterator));
                    importingGrades>>itterator;
                } while(itterator != "#");
//                std::cout << "Importing test grades is complete!\n";
            }
            if(itterator == "#"){
                importingGrades>>itterator;
//                std::cout << "Importing semester grades is started!\n";
                do{
                    gradesItterator.addSemesterGrade(stod(itterator));
                    importingGrades>>itterator;
                } while(itterator != ">");
//                std::cout << "Importing semester grades is complete!\n";
            }
        }
        importingGrades>>itterator;
        gradesItterator.setGeneralGrade(0.0);
        baseOfGrades.push_back(gradesItterator);
        gradesItterator.clearData();
    }
    return;
}

void Interface::saveGrades(){
    std::ofstream savingGrades("./data/grades.txt", std::ios::trunc);
    for(Grades thatOneListOfGrades : baseOfGrades){
        savingGrades<<thatOneListOfGrades.getIdSubject()<<" "<<thatOneListOfGrades.getIdGrades()<<" ! ";
        std::vector<double> thatOneBaseOfHomeWorkGrades = thatOneListOfGrades.getHomeWorkGrades();
        for(double homeworkGrades : thatOneBaseOfHomeWorkGrades){
            savingGrades<<homeworkGrades<<" ";
        }
        savingGrades<<"? ";
        std::vector<double> thatOneBaseOfTestGrades = thatOneListOfGrades.getTestGrades();
        for(double testGrades : thatOneBaseOfTestGrades){
            savingGrades<<testGrades<<" ";
        }
        savingGrades<<"# ";
        std::vector<double> thatOneBaseOfSemesterGrades = thatOneListOfGrades.getSemesterGrades();
        for(double semesterGrades : thatOneBaseOfSemesterGrades){
            savingGrades<<semesterGrades<<" ";
        }
        savingGrades<<">"<<std::endl;
    }
    savingGrades.close();
//    std::cout << "Saving Grades is completed!\n";
//    std::cin.get();
}

void Interface::eraseGrades(int idDoomedGrades){
//    std::cout << "Start erasing!\n";
    std::cout << "Doomed Grades ID is: " << idDoomedGrades << std::endl;
    for (auto it = baseOfGrades.begin(); it != baseOfGrades.end(); ++it){
        std::cout << "Checking Grades with ID of: " << it->getIdGrades() << std::endl;
        if(it->getIdGrades() == idDoomedGrades){
            std::cout << "Erasing Grades with ID of: " << it->getIdGrades() << std::endl;
            it = baseOfGrades.erase(it);
            it = baseOfGrades.begin();
        }
    }
    for (auto it = baseOfGrades.begin(); it != baseOfGrades.end(); ++it){
        if(it->getIdGrades() > idDoomedGrades){
            it->setIdGrades(it->getIdGrades() - 1);
        }
    }

    saveGrades();
}

void Interface::sortGrades(){
    baseOfGrades.clear();
    importGrades();
    importSubjects();
    for(int i = 0; i < baseOfGrades.size() - 1; i++){
//        std::cout << i << " " << baseOfGrades.size() << std::endl;
        for(int j = (i + 1); j < baseOfGrades.size(); ++j){
//            std::cout << "Shy dontcha work?\n";
            if(baseOfGrades[i].getIdGrades() > baseOfGrades[j].getIdGrades()){
                std::swap(baseOfGrades[i], baseOfGrades[j]);
//                std::cout << "puk\n";
            }
        }
    }
    for(int i = 0; i < baseOfGrades.size() - 1; i++){
        for(int j = i; j < baseOfGrades.size() - 1; j++){
            if(baseOfGrades[j].getIdSubject() > baseOfGrades[j+1].getIdSubject()){
                std::swap(baseOfGrades[j], baseOfGrades[j+1]);
            }
        }
    }
    saveGrades();
}

void Interface::displayGradesToEdit(std::string nameOfGradesList, std::vector<double> gradesForEdit){
    std::cout <<rang::style::underline << nameOfGradesList << " grades(";
    if(nameOfGradesList == "Home work"){ std::cout << "!";}
    else if(nameOfGradesList == "Test"){ std::cout << "?";}
    else if(nameOfGradesList == "Semester"){ std::cout << "#";}
    std::cout << "):" << rang::style::reset << std::endl;
    for(double grade : gradesForEdit){
        std::cout << grade;
        if(std::to_string(grade).size() > 8){ std::cout << std::setw(14 - std::to_string(grade).size()); }
        else{ std::cout << std::setw(13 - std::to_string(grade).size()); }
//                std::cout << "{" << std::to_string(grade).size() << "]\n";
    }
    std::cout << "\n" << std::setw(0);
    if(gradesForEdit[0] > 9){ std::cout << " ";}
    for(size_t i = 0; i < gradesForEdit.size(); i++){
        std::cout << "^" << std::setw(5);
    }
    std::cout << "\n" << std::setw(0);
    if(gradesForEdit[0] > 9){ std::cout << " ";}
    for(size_t i = 0; i < gradesForEdit.size(); i++){
        std::cout << i << std::setw(5);
    }
    std::cout << "\n\n";
}

int Interface::connectGradesToStudent(Student* selectedStudent){
    int idStudent = selectedStudent->getId();
    for(Grades selectGrades : baseOfGrades){
        if(selectGrades.getIdGrades() == idStudent){
            selectedGrades = new Grades(selectGrades);
            return 1;
        }
    }
    system("cls");
    std::cout << "Error! This student don't have any grades! Back to the list.\n";
    std::cin.get();
    return 0;
}

std::vector<double> Interface::changeGrade(std::vector<double> insertedGrades, int coordinate, double newValue){
    insertedGrades[coordinate] = newValue;
    return insertedGrades;
}

void Interface::importSubjects(){
    std::ifstream importingSubjects("./data/subjects.txt");
    if(!importingSubjects.is_open()){std::cout << "File wasn't found!\n"; std::cin.get(); return;}
    Subject subjectsitterator;
    int idSubject;
    std::string itterator, newSubjectName, newTeacherName, newDescription;
    importingSubjects>>itterator;
    while(!importingSubjects.eof()){
        idSubject = stoi(itterator);
        subjectsitterator.setIdSubject(idSubject);
        importingSubjects>>itterator;
        if(itterator == "'"){
            importingSubjects>>itterator;
            do{
                newSubjectName += itterator + " ";
                importingSubjects>>itterator;
            }while(itterator != "'");
        }
        subjectsitterator.setName(newSubjectName);
        newSubjectName.clear();
        importingSubjects>>itterator;
        int newIdTeacher = std::stoi(itterator);
        subjectsitterator.setIdTeacher(newIdTeacher);
        importingSubjects>>itterator;
        if(itterator == "'"){
            importingSubjects>>itterator;
            do{
                newTeacherName += itterator + " ";
                importingSubjects>>itterator;
            }while(itterator != "'");
        }
        subjectsitterator.setTeacher(newTeacherName);
        newTeacherName.clear();
        if(itterator == "'"){
            importingSubjects>>itterator;
            do{
                newDescription += itterator + " ";
                importingSubjects>>itterator;
            }while(itterator != "'");
        }
        subjectsitterator.setDescription(newDescription);
        newDescription.clear();
        baseOfSubjects.push_back(subjectsitterator);
        importingSubjects>>itterator;
        subjectsitterator.clearData();
    }

}



bool Interface::containsOnlyDigits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void Interface::clearAllBases(){
    baseOfGrades.clear();
    baseOfStudents.clear();
    baseOfSubjects.clear();
    return;
}


Interface::Interface(){}

Interface::~Interface(){
    baseOfGrades.clear();
    baseOfStudents.clear();
    baseOfSubjects.clear();
    delete selectedStudent;
    delete selectedGrades;
    delete selectedSubject;
    std::cout << rang::fg::blue << "Destructor of Interface class was called!" << rang::fg::reset << std::endl;
}


