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
#include "BubbleSort.h"



int Interface::startMenu(){
    system("cls");
    std::cout << "MyJournal 0.2.4 \n" << std::endl;
    std::cout << "(Type '/?' for 'user manual'; type '/quit' to exit)" << std::endl;

    Sleep(500);

    std::string decition;
    std::cout << std::endl;
    std::cout << rang::fg::green << rang::style::underline << "Welcome!" << rang::fg::reset << rang::style::reset << std::endl;
    std::cout << "1.Students information. \n2.View grades. \n3.Teacher info. \n";
    std::cout << ">";
    std::getline(std::cin, decition);

    if(decition == "/quit"){
        return 0;
    }else if(decition == "1"){
        studentInfo();
    }else if(decition == "2"){
        gradesInfo(2);
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

void Interface::gradesInfo(int idSubject){
    loadStudents();
    importMarks();
    importSubjects();
    system("cls");
    std::cout << "================|\0" << rang::style::underline << " " << baseOfSubjects[idSubject - 1].getName() << rang::style::reset << "|";
    for(int i = 0; i < 98 - baseOfSubjects[idSubject - 1].getName().size(); i++){
        std::cout << "=";
    }
    std::cout << "\n";
    std::cout << "-----------------------------------++--------------------------------------------------------------------------------" << std::endl;
    for(Student thatOneStudent : baseOfStudents){
        std::cout << " " << thatOneStudent.getName() << " " << thatOneStudent.getSurname() << " " << thatOneStudent.getPatronymic()
                  <<std::setw(35 - (thatOneStudent.getName().size() + thatOneStudent.getSurname().size() + thatOneStudent.getPatronymic().size()))
                  <<"|| " << std::endl;
        std::cout << "-----------------------------------++--------------------------------------------------------------------------------" << std::endl;
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
       std::cout << "Enter the first name: ";
       std::getline(std::cin, uncheckedNewName);
       newName = nsp_check(uncheckedNewName);
       system("cls");
       std::cout << "Enter the last name: ";
       std::getline(std::cin, uncheckedNewSurname);
       newSurname = nsp_check(uncheckedNewSurname);
       system("cls");
       std::cout << "Enter the patronymic: ";
       std::getline(std::cin, uncheckedNewPatronymic);
       newPatronymic = nsp_check(uncheckedNewPatronymic);

        system("cls");
       std::cout << "Enter the age: ";
       std::getline(std::cin, uncheckedNewAge);
       newAge = age_check(uncheckedNewAge);

       system("cls");
       std::cout << "Choose the sex (" << rang::style::underline << "Male/Female/Other" << rang::style::reset << "): ";
       std::getline(std::cin, uncheckedNewSex);
       newSex = sex_check(uncheckedNewSex);

       system("cls");
       std::cout << "Write down the address (Be careful, this information will not be processed!)\n>";
       std::getline(std::cin, uncheckedNewAddress);
       newAddress = address_check(uncheckedNewAddress);

       system("cls");
       creatingStudent<<newId<<" "<<newName<<" "<<newSurname<<" "<<newPatronymic<<" "<<newAge<<" "<<newSex<<" "<<newAddress<<" >"<<std::endl;
       creatingStudent.close();
a1:    std::cout << "The information was successfully recorded!\n";
       Sleep(300);
       std::cout << "1.Back to students information\n>";
        std::string decition;
        std::getline(std::cin, decition);
        shouldLoad = true;
        if(decition == "1"){
            return;
//        } else if(decition == "2"){
//            std::cout << "Not done yet(\n";
//            std::cin.get();
//            return;
        } else{
            system("cls");
        }
        goto a1;
       }
//    std::cout << baseOfStudents.back().getId();
    return;
}

void Interface::eraseStudent() {
    baseOfStudents.clear();
    loadStudents();
    importMarks();
    std::cout << "Enter the ID of the student whose data you want to erase: ";
    std::string doomedStudent;
    std::getline(std::cin, doomedStudent);
    if (!containsOnlyDigits(doomedStudent)) {
        std::cout << "Error! ID consist only from digits!";
        std::cin.get();
        baseOfMarks.clear();
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
                eraseMarks(stoi(doomedStudent));
                baseOfStudents.erase(it);
                saveStudents();
                std::cout << "Student info has been deleted successfully! \nBack to the student list...";
                shouldLoad = true;
                std::cin.get();
                baseOfMarks.clear();
                return;
            } else if (decision == "2") {
                baseOfMarks.clear();
                return;
            } else {
                std::cout << "Wrong insertion!\n\n";
                std::cin.get();
                baseOfMarks.clear();
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
    int intSelectedId = std::stoi(selectedId);
    for(Student eachStudent : baseOfStudents){
        if(eachStudent.getId() == intSelectedId){
            delete selectedStudent;
            selectedStudent = new Student(eachStudent);
            std::cout << "Student has been selected!\n";
            Sleep(1000);
            return "1";
        }
    }
    std::cout << "Student wasn't found((((";
    std::cin.get();
    return 0;
}

void viewStudentSubjects();
void Interface::viewStudent(){
    std::string selection;
    std::cout << "Enter ID of the student you want to check: ";
    std::getline(std::cin, selection);
    if(selection.empty()){std::cout << "Error! Entered nothing!\n"; std::cin.get(); return;}
    std::string result = selectStudent(selection);
    if(result == "1"){
a2:     importMarks();
        importSubjects();
        int checkConnect = connectMarksToStudent(selectedStudent);
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
        if(decition == "1"){
            baseOfMarks.clear();
            baseOfSubjects.clear();
            viewStudentSubjects();
        }else if(decition == "0"){
            baseOfMarks.clear();
            baseOfSubjects.clear();
            selectedMarks->clearData();
            selectedSubject->clearData();
            return;
        }
        baseOfMarks.clear();
        baseOfSubjects.clear();
        goto a2;
    }else{return;}
    viewStudent();
}
void Interface::viewStudentSubjects(){
    baseOfMarks.clear();
    baseOfSubjects.clear();
    importMarks();
    importSubjects();
    int checkConnect = connectMarksToStudent(selectedStudent);
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
    for(Subject thisSubject : baseOfSubjects){
        if(thisSubject.getIdSubject() == stoi(decition)){
            baseOfMarks.clear();
            viewGrades(thisSubject.getName(), thisSubject.getIdSubject(), selectedStudent->getId());
        }
        else if(decition == "0"){
            baseOfMarks.clear();
            baseOfSubjects.clear();
            return;
        }
    }
}

void Interface::viewGrades(std::string name, int idSubject, int idMarks){
    importMarks();
    std::cout << baseOfMarks.front().getIdSubject();
    system("cls");
    for(Marks thatOneListOfMarks : baseOfMarks){
        if(thatOneListOfMarks.getIdMarks() == idMarks && thatOneListOfMarks.getIdSubject() == idSubject){
            std::cout << rang::style::bold << rang::style::underline << "Subject: " << name << rang::style::reset << std::endl;
            thatOneListOfMarks.displayAllMarks();
            std::cin.get();
            return;
        }
    }
    std::cin.get();
}


void Interface::importMarks()
{
    std::ifstream importingMarks("./data/marks.txt");
//    std::cout << "File found!\n";
    Marks marksItterator;
    std::string itterator;
    importingMarks>>itterator;
    while(!importingMarks.eof()){
        marksItterator.setIdSubject(stoi(itterator));
//        std::cout << "ID of Subject found!\n";
        marksItterator.displayIdSubject();
        importingMarks>>itterator;
        marksItterator.setIdMarks(stoi(itterator));
//        std::cout << "ID found!\n";
        importingMarks>>itterator;
        while(itterator != ">"){
            if(itterator == "!"){
                importingMarks>>itterator;
//                std::cout << "Importing homework grades is started!\n";
                do{
                    marksItterator.addHomeWorkMark(stod(itterator));
                    importingMarks>>itterator;
                } while(itterator != "?");
//                std::cout << "Importing homework grades is complete!\n";
            }
            if(itterator == "?"){
                importingMarks>>itterator;
//                std::cout << "Importing test grades is started!\n";
                do{
                    marksItterator.addTestMark(stod(itterator));
                    importingMarks>>itterator;
                } while(itterator != "#");
//                std::cout << "Importing test grades is complete!\n";
            }
            if(itterator == "#"){
                importingMarks>>itterator;
//                std::cout << "Importing semester grades is started!\n";
                do{
                    marksItterator.addSemesterMark(stod(itterator));
                    importingMarks>>itterator;
                } while(itterator != ">");
//                std::cout << "Importing semester grades is complete!\n";
            }
        }
        importingMarks>>itterator;
        marksItterator.setGeneralMark(0.0);
        baseOfMarks.push_back(marksItterator);
        marksItterator.clearData();
    }
    return;
}

void Interface::saveMarks(){
    std::ofstream savingMarks("./data/marks.txt", std::ios::trunc);
    for(Marks thatOneListOfMarks : baseOfMarks){
        savingMarks<<thatOneListOfMarks.getIdSubject()<<" "<<thatOneListOfMarks.getIdMarks()<<" ! ";
        std::vector<double> thatOneBaseOfHomeWorkGrades = thatOneListOfMarks.getHomeWorkGrades();
        for(double homeworkGrades : thatOneBaseOfHomeWorkGrades){
            savingMarks<<homeworkGrades<<" ";
        }
        savingMarks<<"? ";
        std::vector<double> thatOneBaseOfTestGrades = thatOneListOfMarks.getTestGrades();
        for(double testGrades : thatOneBaseOfTestGrades){
            savingMarks<<testGrades<<" ";
        }
        savingMarks<<"# ";
        std::vector<double> thatOneBaseOfSemesterGrades = thatOneListOfMarks.getSemesterGrades();
        for(double semesterGrades : thatOneBaseOfSemesterGrades){
            savingMarks<<semesterGrades<<" ";
        }
        savingMarks<<">"<<std::endl;
    }
//    std::cout << "Saving Marks is completed!\n";
//    std::cin.get();
}

void Interface::eraseMarks(int idDoomedMarks){
//    std::cout << "Start erasing!\n";
    std::cout << "Doomed marks ID is: " << idDoomedMarks << std::endl;
    for (auto it = baseOfMarks.begin(); it != baseOfMarks.end(); ++it){
        std::cout << "Checking marks with ID of: " << it->getIdMarks() << std::endl;
        if(it->getIdMarks() == idDoomedMarks){
            std::cout << "Erasing marks with ID of: " << it->getIdMarks() << std::endl;
            it = baseOfMarks.erase(it);
            it = baseOfMarks.begin();
        }
    }
    for (auto it = baseOfMarks.begin(); it != baseOfMarks.end(); ++it){
        if(it->getIdMarks() > idDoomedMarks){
            it->setIdMarks(it->getIdMarks() - 1);
        }
    }

    saveMarks();
}

int Interface::connectMarksToStudent(Student* selectedStudent){
    int idStudent = selectedStudent->getId();
    for(Marks selectMarks : baseOfMarks){
        if(selectMarks.getIdMarks() == idStudent){
            selectedMarks = new Marks(selectMarks);
            return 1;
        }
    }
    system("cls");
    std::cout << "Error! This student don't have any grades! Back to the list.\n";
    std::cin.get();
    return 0;
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
        std::cout << "Subject has been imported!" << std::endl;
        importingSubjects>>itterator;
        subjectsitterator.clearData();
    }

}



bool Interface::containsOnlyDigits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

//    template<typename T>
//    void bubbleSort(std::vector<T> container, char mode){
//        for(size_t i = 0; i < container.size(); ++i){
//            for (size_t j = 0; j < container.size() - i - 1; ++j) {
//                bool shouldSwap = false;
//                if(mode == 'i'){
//                    shouldSwap == container[j].getId() > container[j + 1].getId();
//                }else if(mode == 'n'){
//                    shouldSwap == container[j].getName() > container[j + 1].getName();
//                }
//                if(shouldSwap){
//                    std::swap(container[j], container[j + 1]);
//                }
//            }
//        }
//    }




Interface::Interface(){}

Interface::~Interface(){
    baseOfMarks.clear();
    baseOfStudents.clear();
    baseOfSubjects.clear();
    delete selectedStudent;
    delete selectedMarks;
    delete selectedSubject;
    std::cout << rang::fg::blue << "Destructor of Interface class was called!" << rang::fg::reset << std::endl;
}


