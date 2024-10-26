#include "../rang.hpp"
#include <../External-Libraries/variant.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <typeinfo>

#include "Interface.h"
#include "BubbleSort.h"



int Interface::startMenu(){
    clearAllBases();
    system("cls");
    std::cout << "MyJournal 0.3.9  \n" << std::endl;
    std::cout << "(Type '/?' for 'user manual';" << std::endl;

    Sleep(500);

    std::string decition;
    std::cout << std::endl;
    std::cout << rang::fg::green << rang::style::underline << "Welcome!" << rang::fg::reset << rang::style::reset << std::endl;
    std::cout << "1.Students information \n2.View grades \n3.Subject info \n0.Exit \n>";
    std::getline(std::cin, decition);

    if(decition == "1"){
        studentInfo();
    }else if(decition == "2"){
        selectSubject();
    }else if(decition == "3"){
        subjectInfo();
    }else if(decition == "0"){
        clearAllBases();
        return 0;
    }else {
        system("cls");
    }
    startMenu();
}

void sortStudents();
void bubbleSort();

int Interface::studentInfo() {
    if(shouldLoad){loadItems(baseOfStudents);}
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
    if(baseOfStudents.empty()){
        std::cout << "Seems like you don't have any student records yet. Would you like to create one? \n1.Yes \n2.Back \n>";
        std::string decition;
        std::getline(std::cin, decition);
        if(decition.empty()){std::cout << "Wrong insertion!\n"; std::cin.get(); studentInfo(); return 0;}
        if(decition == "1"){
            createStudent();
        }else if(decition == "2"){
            return 0;
        }
    }
    else{
        std::cout << "Choose an action:\n1.View student information \n2.Add student information \n3.Erase student information \n4.Sort list\n0.Back\n>";


        std::string decition;
        std::getline(std::cin, decition);
        if(decition == "1"){
            viewStudent();
        }else if(decition == "2"){
            createStudent();
        }else if(decition == "3"){
            eraseItem(baseOfStudents, "", "");
        }else if(decition == "4"){
            sortItems(baseOfStudents);
        }else if(decition == "0"){
            shouldLoad = true;
            return 0;
        }else{
            system("cls");
        }
    }

    studentInfo();
}
void loadItems();
template<typename T>
void Interface::saveBasesOfItems(std::vector<T>& baseOfItems){
    if(typeid(T) == typeid(Student)){
        std::ofstream savingStudents("./data/students.txt", std::ios::trunc);
        for(int i = 0; i < static_cast<int>(baseOfStudents.size()); i++){
            savingStudents<<i+1<<" "<<baseOfStudents[i].getName()<<" "<<baseOfStudents[i].getSurname()<<" "
                          <<baseOfStudents[i].getPatronymic()<<" "<<baseOfStudents[i].getAge()<<" "
                          <<baseOfStudents[i].getSex()<<" ' "<<baseOfStudents[i].getAddress()<<"' >"<<std::endl;

        }
    }else if(typeid(T) == typeid(Grades)){
        std::ofstream savingGrades("./data/grades.txt", std::ios::trunc);
        loadItems(baseOfSubjects);
        int amountOfSubjects = baseOfSubjects.size();
        std::cout << "Amount of subjects " << amountOfSubjects << std::endl;
        std::cin.get();
        baseOfSubjects.clear();
        int amountOfStudents = 0;
        for(Grades thatOneListOfGrades : baseOfGrades){
            if(amountOfStudents < thatOneListOfGrades.getId()){
                amountOfStudents = thatOneListOfGrades.getId();
            }
        }
        for(size_t i = 0; i < static_cast<int>(amountOfSubjects); i++){
            std::cout << "Cicle " << i+1 << std::endl;
            for(size_t j = 0; j < static_cast<int>(amountOfStudents); j++){
                std::cout << j+1 << " " << i+1 << std::endl;
                savingGrades<<i+1<<" "<<j+1<<" ! ";
                std::vector<double> thatOneBaseOfHomeWorkGrades = baseOfGrades[(i*amountOfStudents) + j].getHomeWorkGrades();
                for(double homeworkGrades : thatOneBaseOfHomeWorkGrades){
                    savingGrades<<homeworkGrades<<" ";
                }
                savingGrades<<"? ";
                std::vector<double> thatOneBaseOfTestGrades = baseOfGrades[(i*amountOfStudents) + j].getTestGrades();
                for(double testGrades : thatOneBaseOfTestGrades){
                    savingGrades<<testGrades<<" ";
                }
                savingGrades<<"# ";
                std::vector<double> thatOneBaseOfSemesterGrades = baseOfGrades[(i*amountOfStudents) + j].getSemesterGrades();
                for(double semesterGrades : thatOneBaseOfSemesterGrades){
                    savingGrades<<semesterGrades<<" ";
                }
                savingGrades<<">"<<std::endl;
            }
        }
        savingGrades.close();
        return;
    }else if(typeid(T) == typeid(Subject)){
        int idOfTeacher = 0;
        loadItems(baseOfTeachers);
        std::ofstream savingSubject("./data/subjects.txt", std::ios::trunc);
        if(savingSubject.is_open()){std::cout << "File is open!\n"; std::cin.get();}
        for(int i = 0; i < static_cast<int>(baseOfSubjects.size()); i++){
            idOfTeacher = 0;
            std::string leftName = baseOfSubjects[i].getTeacher();
            if(leftName.back() == ' '){ leftName.pop_back(); }
            for(Teacher thatOneTeacher : baseOfTeachers){
            std::string rightName = thatOneTeacher.getShortName();
            rightName.pop_back();
            std::cout << "[" << leftName << "|" << rightName << "]\n";
                    std::cin.get();
                if(leftName == rightName){
                    idOfTeacher = thatOneTeacher.getId();
                }
            }
            savingSubject<<(i + 1)<<" ' "<<baseOfSubjects[i].getName()<<" ' "<<idOfTeacher<<" ' "<<baseOfSubjects[i].getTeacher()<<" ' "
                          <<baseOfSubjects[i].getDescription()<<" ' "<<std::endl;
        }
        std::cin.get();
        savingSubject.close();
    }else if(typeid(T) == typeid(Teacher)){
        std::ofstream savingTeachers("./data/teachers.txt", std::ios::trunc);
        if(!baseOfTeachers.empty()){
            for(int i = 0; i < baseOfTeachers.size(); i++){
                savingTeachers<<(i + 1)<<" "<<baseOfTeachers[i].getName()<<" "<<baseOfTeachers[i].getSurname()<<" "
                              <<baseOfTeachers[i].getPatronymic()<<" ' "<<baseOfTeachers[i].getShortName()<<" ' "<<baseOfTeachers[i].getAge()<<" "
                              <<baseOfTeachers[i].getSex()<<" >"<<std::endl;

            }
        }
        savingTeachers.close();
    }else if(typeid(T) == typeid(Parent)){
        std::ofstream savingParents("./data/parents.txt", std::ios::trunc);
        if(baseOfParents.empty()){savingParents.close(); return;}
        for(int i = 0; i < baseOfParents.size(); i++){
            savingParents<<i+1<<" "<<baseOfParents[i].getName()<<" "<<baseOfParents[i].getSurname()<<" "
                         <<baseOfParents[i].getPatronymic()<<" "<<baseOfParents[i].getAge()<<" "
                         <<baseOfParents[i].getSex()<<" ' "<<baseOfParents[i].getAddress()<<" ' "<<baseOfParents[i].getWork()<<" ' >"<<std::endl;
        }
    }
}

void Interface::selectSubject(){
    clearAllBases();
    system("cls");
    loadItems(baseOfSubjects);
    if(!baseOfSubjects.empty()){
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
    }else{
        std::cout << "Seems like you don't have any subjects records yet. Would you like to create one? \n1.Yes \n2.Back \n>";
        std::string decition;
        std::getline(std::cin, decition);
        if(decition == "1"){
            createSubject();
        }else if (decition == "2"){
            return;
        }
    }
    selectSubject();
}

void Interface::gradesInfo(int idSubject, int newPage){
    int page = newPage;
    clearAllBases();
    loadItems(baseOfStudents);
    int amountOfStudent = baseOfStudents.size();
    loadItems(baseOfGrades);
    loadItems(baseOfSubjects);
//    sortItems(baseOfGrades);
    system("cls");
    std::cout << rang::style::bold << rang::style::underline << "================[ " << baseOfSubjects[idSubject - 1].getName() << "]";
    for(size_t i = 0; i < 99 - baseOfSubjects[idSubject - 1].getName().size(); i++){
        std::cout << "=";
    }
    std::cout << rang::style::reset << "=";
    std::cout << "\n" << rang::style::underline << "ID " << std::setw(5) << "|| Full name " << std::setw(38) << " || Home work " << std::setw(46)
              << " || Test " << std::setw(18) << " ||Semest.|" << rang::style::reset << "|" << std::endl;
    for(Student thatOneStudent : baseOfStudents){
        std::cout << rang::style::underline;
        std::cout << " " << thatOneStudent.getId() << std::setw(4 - std::to_string(thatOneStudent.getId()).size()) << "||";
        std::cout << " " << thatOneStudent.getName() << " " << thatOneStudent.getSurname() << " " << thatOneStudent.getPatronymic()
                  <<std::setw(35 - (thatOneStudent.getName().size() + thatOneStudent.getSurname().size() + thatOneStudent.getPatronymic().size()))
                  <<"||";
        bool exit = false;
        for(Grades thatOneListOfGrades : baseOfGrades){
            if(thatOneListOfGrades.getIdSubject() == idSubject && thatOneListOfGrades.getId() == thatOneStudent.getId() && !exit){
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
                std::cout << rang::style::reset << "|" << std::endl;
                exit = true;
            }
        }

//        std::cout << "\n---++------------------------------------++-------------------------------------------------++--------------++-------++" << std::endl;
    }
    std::cout << rang::style::reset;
    std::cout << rang::style::bold << "=======================================================================================================================\n" << rang::bg::reset;
    std::cout << "(Enter the 'arrows' to navigate through pages)\n< " << page << " >\n\n";
    std::cout << "Choose an action:\n1.Edit grades \n2.Change subject  \n3.Add new page \n4.Delete last page \n0.Back \n>";
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
        if(static_cast<int>(baseOfGrades[0].getHomeWorkGrades().size()) == static_cast<int>(page * 10)){
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
        if(!containsOnlyDigits(idDecition) || stoi(idDecition) > static_cast<int>(baseOfStudents.size()) || idDecition == "0"){
            std::cout << "Wrong insertion!\n";
            std::cin.get();
        }else{
            editGrades(idSubject, stoi(idDecition));
            return;
        }
    }else if(decition == "2"){
        selectSubject();
        return;
    }else if(decition == "3"){
        createAndAddBlankGrades(idSubject);
    }else if(decition == "4"){
        loadItems(baseOfGrades);
        if((baseOfGrades[amountOfStudent*(idSubject-1)].getHomeWorkGrades().size() == page*10) && page > 1){newPage = newPage - 1;}
        removeExistantGradesPage(idSubject);
    }else if(decition == "0"){
        clearAllBases();
        return;
    }
    gradesInfo(idSubject, newPage);
}

void Interface::subjectInfo(){
    if(shouldLoad){loadItems(baseOfSubjects);}
    if(baseOfSubjects.empty()){loadItems(baseOfSubjects);}
    system("cls");
    std::cout << "=======================================================================================================================" << std::endl;
    std::cout << " ID " << std::setw(5) << "|| Name " << std::setw(38) << " || T ID" << std::setw(10) << " || Teacher " << std::setw(29) << " || Description " << std::endl;
    std::cout << "----++-------------------------------------++------++-----------------------++-----------------------------------------" << std::endl;

    for(Subject selectedSubject : baseOfSubjects){
        std::cout << " " << selectedSubject.getIdSubject() << std::setw(6 - std::to_string(selectedSubject.getIdSubject()).size()) << "|| " << selectedSubject.getName()
                  << std::setw(39 - (selectedSubject.getName().size())) << " || " << selectedSubject.getIdTeacher()
                  << std::setw(8 - std::to_string(selectedSubject.getIdTeacher()).size()) << " || " << selectedSubject.getTeacher()
                  << std::setw(25 - selectedSubject.getTeacher().size()) << " || ";
    std::stringstream descriprion(selectedSubject.getDescription());
    std::string word, wholeWord;
    if(selectedSubject.getDescription().size() > 39){
        int counter = 0;
        descriprion>>word;
        word += " ";
        counter += word.size();
        while(counter < 39){
            wholeWord += word;
            descriprion>>word;
            word += " ";
            counter += word.size();
        }
        std::cout << wholeWord << "...\n";
    }else{ std::cout << selectedSubject.getDescription() << std::endl; }
    }
    std::cout << "=======================================================================================================================" << std::endl << std::endl;

    Sleep(100);

    if(!baseOfSubjects.empty()){
        std::cout << "Choose an action:\n1.View subject information \n2.Add subject information \n3.Erase subject information \n4.Sort list\n0.Back\n>";
        std::string decition;
        std::getline(std::cin, decition);
        if(decition == "1"){
            viewSubject();
        }else if(decition == "2"){
            createSubject();
        }else if(decition == "3"){
            eraseItem(baseOfSubjects, "", "");
        }else if(decition == "4"){
            sortItems(baseOfSubjects);
        }else if(decition == "0"){
            return;
        }
    }else{
        std::cout << "Seems like you don't have any subjects records yet. Would you like to create one? \n1.Yes \n2.Back \n>";
        std::string decition;
        std::getline(std::cin, decition);
        if(decition == "1"){
            createSubject();
        }else if (decition == "2"){
            return;
        }
    }
    subjectInfo();
}

void Interface::viewSubject(){
    selectedSubject = nullptr;
    clearAllBases();
    loadItems(baseOfSubjects);
    std::string selection;
    std::cout << "Enter ID of the subject you want to check: ";
    std::getline(std::cin, selection);
    if(selection.empty()){std::cout << "Error! Entered nothing!\n"; std::cin.get(); return;}
    for(Subject thatOneSubject : baseOfSubjects){
        if(thatOneSubject.getIdSubject() == stoi(selection)){
            selectedSubject = new Subject(thatOneSubject);
        }
    }
    if(selectedSubject == nullptr){
        std::cout << "Wrong insertion! Back to list...\n";
        std::cin.get();
        clearAllBases();
        return;
    }
a3: baseOfSubjects.clear();
    loadItems(baseOfSubjects);
    for(Subject thatOneSubject : baseOfSubjects){
        if(thatOneSubject.getIdSubject() == stoi(selection)){
            selectedSubject = nullptr;
            selectedSubject = new Subject(thatOneSubject);
        }
    }
    system("cls");
    selectedSubject->displayInfo();
    std::cout << "\n";
    std::cout << "Action: \n1.View information about teacher \n2.Edit subject \n0.Back \n\n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(!decition.empty()){
        if(decition == "1"){
            viewTeacher(selectedSubject->getIdTeacher());
        }else if(decition == "2"){
            editItem(baseOfSubjects);
        }else if(decition == "0"){
            selectedGrades->clearData();
            selectedSubject->clearData();
            clearAllBases();
            shouldLoad = true;
            delete selectedSubject;
            selectedSubject = nullptr;
            return;
        }
    }else{
        baseOfGrades.clear();
        baseOfSubjects.clear();
        goto a3;
    }
    goto a3;
}

void Interface::viewTeacher(int idTeacher){
    loadItems(baseOfTeachers);
    for(Teacher thatOneTeacher : baseOfTeachers){
        if(thatOneTeacher.getId() == idTeacher){
            selectedTeacher = new Teacher(thatOneTeacher);
        }
    }
    system("cls");
    selectedTeacher->displayInfo();
    std::cout << "\n";
    std::cout << "Action: \n1.Edit teacher \n0.Back \n\n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(decition == "1"){
        editItem(baseOfTeachers);
    }else if(decition == "0"){
        delete selectedTeacher;
        selectedTeacher = nullptr;
        baseOfTeachers.clear();
        return;
    }
    viewTeacher(idTeacher);
    return;
}

void Interface::viewParent(int idParent){
    selectedParent = nullptr;
    loadItems(baseOfParents);
    for(Parent thatOneParent : baseOfParents){
        if(thatOneParent.getId() == idParent){
            selectedParent = new Parent(thatOneParent);
        }
    }
    system("cls");
    selectedParent->displayInfo();
    std::cout << "\n";
    std::cout << "Action: \n1.Edit parent \n0.Back \n\n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(decition == "1"){
        editItem(baseOfParents);
    }else if(decition == "0"){
        delete selectedParent;
        selectedParent = nullptr;
        baseOfParents.clear();
        return;
    }
    viewParent(idParent);
    return;
}

template<typename T>
void Interface::editItem(std::vector<T>& baseOfItem) {
    system("cls");
    if(typeid(T) == typeid(Student)){
        selectedStudent->displayInfo();
        std::cout << "\nSelect attribute you want to change:\n";
        std::cout << "1.Name \n2.Surname \n3.Patronymic \n4.Age \n5.Sex \n6.Address \n0.Back\n>";
    }
    else if(typeid(T) == typeid(Subject)){
        selectedSubject->displayInfo();
        std::cout << "\nSelect attribute you want to change:\n";
        std::cout << "1.Name \n2.Teacher's name \n3.Description \n0.Back \n>";
    }
    else if(typeid(T) == typeid(Teacher)){
        selectedTeacher->displayInfo();
        std::cout << "\nSelect attribute you want to change:\n";
        std::cout << "1.Name \n2.Surname \n3.Patronymic \n4.ShortName \n5.Age \n6.Sex \n0.Back\n>";;
    }
    else if(typeid(T) == typeid(Parent)){
        selectedParent->displayInfo();
        std::cout << "\nSelect attribute you want to change:\n";
        std::cout << "1.Name \n2.Surname \n3.Patronymic \n4.Age \n5.Sex \n6.Address \n7.Work \n0.Back\n>";;
    }
    std::string decition;
    std::getline(std::cin, decition);
    if(decition.empty()){std::cout << "Insertion cannot be empty!"; std::cin.get(); return;}
    if(decition == "1"){
        system("cls");
        std::cout << "Enter new name: ";
        std::string newName;
        std::getline(std::cin, newName);
        if(typeid(T) != typeid(Subject)){
            newName = nsp_check(newName);
            if(typeid(T) == typeid(Student)){selectedStudent->setName(newName);}
            else if(typeid(T) == typeid(Teacher)){selectedTeacher->setName(newName);}
            else if(typeid(T) == typeid(Parent)){selectedParent->setName(newName);}
        }else if(typeid(T) == typeid(Subject)){
            newName = info_check(newName);
            selectedSubject->setName(newName);
        }
    }else if(decition == "2" && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Enter new surname: ";
        std::string newSurname;
        std::getline(std::cin, newSurname);
        newSurname = nsp_check(newSurname);
        if(typeid(T) == typeid(Student)){selectedStudent->setSurname(newSurname);}
        else if(typeid(T) == typeid(Teacher)){selectedTeacher->setSurname(newSurname);}
        else if(typeid(T) == typeid(Parent)){selectedParent->setSurname(newSurname);}
    }else if(decition == "2" && typeid(T) == typeid(Subject)){
        system("cls");
        std::cout << "Enter new teacher's shortname: ";
        std::string newShortname;
        std::getline(std::cin, newShortname);
        newShortname = info_check(newShortname);
        selectedSubject->setTeacher(newShortname);
        loadItems(baseOfTeachers);
        for(size_t i = 0; i < baseOfTeachers.size(); i++){
            if(baseOfTeachers[i].getId() == selectedSubject->getIdTeacher()){
                baseOfTeachers[i].setShortName(newShortname);
            }
        }
        saveBasesOfItems(baseOfTeachers);
        baseOfTeachers.clear();
    }else if(decition == "3" && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Enter new patronymic: ";
        std::string newPatronymic;
        std::getline(std::cin, newPatronymic);
        newPatronymic = nsp_check(newPatronymic);
        if(typeid(T) == typeid(Student)){selectedStudent->setPatronymic(newPatronymic);}
        else if(typeid(T) == typeid(Teacher)){selectedTeacher->setPatronymic(newPatronymic);}
        else if(typeid(T) == typeid(Parent)){selectedParent->setPatronymic(newPatronymic);}
    }else if(decition == "3" && typeid(T) == typeid(Subject)){
        system("cls");
        std::cout << "Enter new description:\n>";
        std::string newDescription;
        std::getline(std::cin, newDescription);
        newDescription = info_check(newDescription);
        selectedSubject->setDescription(newDescription);
    }else if(decition == "4" && typeid(T) == typeid(Teacher) && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Enter new teacher's shortname: ";
        std::string newShortName;
        std::getline(std::cin, newShortName);
        newShortName = info_check(newShortName);
        selectedTeacher->setShortName(newShortName);
        int idTeacher = selectedTeacher->getId();
        loadItems(baseOfTeachers);
        for(size_t i = 0; i < baseOfTeachers.size(); i++){
            if(baseOfTeachers[i].getId() == selectedTeacher->getId()){
                baseOfTeachers[i].setShortName(newShortName);
            }
        }
        saveBasesOfItems(baseOfTeachers);
        loadItems(baseOfSubjects);
        for(size_t i = 0; i < baseOfSubjects.size(); i++){
            if(baseOfSubjects[i].getIdTeacher() == idTeacher){
                baseOfSubjects[i].setTeacher(newShortName);
            }
        }
        saveBasesOfItems(baseOfSubjects);
        baseOfSubjects.clear();
        baseOfTeachers.clear();
    }else if((decition == "4" && ((typeid(T) == typeid(Student)) || typeid(T) == typeid(Parent)) || (decition == "5" && typeid(T) == typeid(Teacher))) && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Enter new age: ";
        std::string newAge;
        std::getline(std::cin, newAge);
        int intNewAge = age_check(newAge);
        if(typeid(T) == typeid(Student)){selectedStudent->setAge(intNewAge);}
        else if(typeid(T) == typeid(Teacher)){selectedTeacher->setAge(intNewAge);}
        else if(typeid(T) == typeid(Parent)){selectedParent->setAge(intNewAge);}
    }else if((decition == "5" && ((typeid(T) == typeid(Student)) || typeid(T) == typeid(Parent)) || (decition == "6" && typeid(T) == typeid(Teacher))) && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Enter new value of Sex (choose between " << rang::style::underline << "Male/Female/Other" << rang::style::reset << "): ";
        std::string newSex;
        std::getline(std::cin, newSex);
        newSex = sex_check(newSex);
        if(typeid(T) == typeid(Student)){selectedStudent->setSex(newSex);}
        else if(typeid(T) == typeid(Teacher)){selectedTeacher->setSex(newSex);}
        else if(typeid(T) == typeid(Parent)){selectedParent->setSex(newSex);}
    }else if(decition == "6" && (typeid(T) == typeid(Student) || typeid(T) == typeid(Parent)) && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Write down the new address\n>";
        std::string newAddress;
        std::getline(std::cin, newAddress);
        newAddress = address_check(newAddress);
        if(typeid(T) == typeid(Student)){selectedStudent->setAddress(newAddress);}
        else if(typeid(T) == typeid(Parent)){selectedParent->setAddress(newAddress);}
    }else if(decition == "7" && typeid(T) == typeid(Parent) && typeid(T) != typeid(Subject)){
        system("cls");
        std::cout << "Write down the new work \n>";
        std::string newWork;
        std::getline(std::cin, newWork);
        newWork = info_check(newWork);
        selectedParent->setWork(newWork);
    }else if(decition == "0"){
        if(typeid(T) == typeid(Student)){
            loadItems(baseOfStudents);
            for(size_t i = 0; i < baseOfStudents.size(); i++){
                if(baseOfStudents[i].getId() == selectedStudent->getId()){
                    baseOfStudents[i] = *selectedStudent;
                }
            }
        }
        else if(typeid(T) == typeid(Teacher)){
            loadItems(baseOfTeachers);
            for(size_t i = 0; i < baseOfTeachers.size(); i++){
                if(baseOfTeachers[i].getId() == selectedTeacher->getId()){
                    baseOfTeachers[i] = *selectedTeacher;
                }
            }
        }
        else if(typeid(T) == typeid(Subject)){
            loadItems(baseOfSubjects);
            for(size_t i = 0; i < baseOfSubjects.size(); i++){
                if(baseOfSubjects[i].getIdSubject() == selectedSubject->getIdSubject()){
                    baseOfSubjects[i] = *selectedSubject;
                }
            }
        }
        else if(typeid(T) == typeid(Parent)){
            loadItems(baseOfParents);
            for(size_t i = 0; i < baseOfParents.size(); i++){
                if(baseOfParents[i].getId() == selectedParent->getId()){
                    baseOfParents[i] = *selectedParent;
                }
            }
        }
        saveBasesOfItems(baseOfItem);
        return;
    }
    editItem(baseOfItem);
}

//void Interface::editSubject(){
//    system("cls");
//    selectedSubject->displayInfo();
//    std::cout << "\nSelect attribute you want to change:\n";
//    std::cout << "1.Name \n2.Teacher's name \n3.Description \n0.Back \n>";
//    std::string decition;
//    std::getline(std::cin, decition);
//    if(decition == "1"){
//        system("cls");
//        std::cout << "Enter new name: ";
//        std::string newName;
//        std::getline(std::cin, newName);
//        newName = info_check(newName);
//        selectedSubject->setName(newName);
//    }else if(decition == "2"){
//        loadItems(baseOfTeachers);
//        system("cls");
//        std::cout << "Enter new teacher's short name (Example: Voloshchuk M. V.): ";
//        std::string newTeachersName;
//        std::getline(std::cin, newTeachersName);
//        newTeachersName = info_check(newTeachersName);
//        for(auto it = baseOfTeachers.begin(); it != baseOfTeachers.end(); it++){
//            if(selectedSubject->getTeacher() == it->getShortName()){
//                newTeachersName += " ";
//                it->setShortName(newTeachersName);
//            }
//        }
//        selectedSubject->setTeacher(newTeachersName);
//        saveBasesOfItems(baseOfTeachers);
//        baseOfTeachers.clear();
//    }else if(decition == "3"){
//        system("cls");
//        std::cout << "Enter new description of this subject:\n";
//        std::string newDescription;
//        std::getline(std::cin, newDescription);
//        newDescription = info_check(newDescription);
//        selectedSubject->setDescription(newDescription);
//    }else if(decition == "0"){
//        for(auto it = baseOfSubjects.begin(); it != baseOfSubjects.end(); it++){
//            if(it->getIdSubject() == selectedSubject->getIdSubject()){
//                *it = *selectedSubject;
//            }
//        }
//        saveBasesOfItems(baseOfSubjects);
//        return;
//    }
//    editSubject();
//
//}

void Interface::editGrades(int idSubject, int idGrades){
    if(idGrades)
    for(Grades thatOneGrades : baseOfGrades){
        if(thatOneGrades.getId() == idGrades && thatOneGrades.getIdSubject() == idSubject){
            std::vector<double> homeWorkGrades = thatOneGrades.getHomeWorkGrades();
            std::vector<double> testGrades = thatOneGrades.getTestGrades();
            std::vector<double> semesterGrades = thatOneGrades.getSemesterGrades();
ahah:       system("cls");
            displayGradesToEdit("Home work", homeWorkGrades);
            displayGradesToEdit("Test", testGrades);
            displayGradesToEdit("Semester", semesterGrades);

            std::cout << "\n(Enter '<' to go back without changes) \nEnter type (!/@/#) and a coordinate of grade you want to edit (split it by 'space'): ";
            std::string insertion;
            std::getline(std::cin, insertion);
            if(insertion.empty()){std::cout << "Error! Entered nothing!\n"; std::cin.get(); goto ahah;}
            if(insertion == "<"){gradesInfo(idSubject, 1); return;}
            std::stringstream separator(insertion);
            std::string index, coordinate;
            separator>>index>>coordinate;
//            std::cout << "[" << index << "]" << std::endl;
            if(index != "!" && index != "@" && index != "#"){std::cout << "No such index!\n"; std::cin.get(); goto ahah;}
            std::cout << "[" << coordinate << "]\n";
            if(containsOnlyDigits(coordinate)){
                if((index == "!" && stoi(coordinate) > static_cast<int>(homeWorkGrades.size() - 1)) || stoi(coordinate) < 0){
                    std::cout << "Wrong coordinate!\n";
                    std::cin.get();
                    goto ahah;
                }else if((index == "@" && stoi(coordinate) > static_cast<int>(testGrades.size() - 1)) || stoi(coordinate) < 0){
                    std::cout << "Wrong coordinate!\n";
                    std::cin.get();
                    goto ahah;
                }else if((index == "#" && stoi(coordinate) > static_cast<int>(semesterGrades.size() - 1)) || stoi(coordinate) < 0){
                    std::cout << "Wrong coordinate!\n";
                    std::cin.get();
                    goto ahah;
                }
            }else{std::cout << "Wrong coordinate!\n"; std::cin.get(); goto ahah;}
            std::cout << "Insert new value: ";
            std::string newValue;
            std::getline(std::cin, newValue);
            if(index == "!"){
                homeWorkGrades = changeGrade(homeWorkGrades, stoi(coordinate), stod(newValue));
            }else if(index == "@"){
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
                for(size_t i = 0; static_cast<int>(i) < static_cast<int>(baseOfGrades.size()); i++){
                    if(baseOfGrades[i].getId() == idGrades && baseOfGrades[i].getIdSubject() == idSubject){
                        baseOfGrades[i].setGrades('h', homeWorkGrades);
                        baseOfGrades[i].setGrades('t', testGrades);
                        baseOfGrades[i].setGrades('s', semesterGrades);
                    }
                }
                sortItems(baseOfGrades);
                saveBasesOfItems(baseOfGrades);
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

template<typename T>
void Interface::loadItems(std::vector<T>& baseOfItems){
    if(typeid(T) == typeid(Student)){
        baseOfStudents.clear();
        Student temporaryStudent;
        std::ifstream loadingStudents("./data/students.txt");
        if(!loadingStudents.is_open()){std::cout << "Not opened" << std::endl;}
        if(loadingStudents.peek() != std::ifstream::traits_type::eof()){
            do {
                std::string newName, newSurname, newPatronymic, newSex, newAddress, check;
                int newId, newAge;
                loadingStudents>>newId>>newName>>newSurname>>newPatronymic>>newAge>>newSex;
                loadingStudents>>check;
                if(check == "'"){
                    std::string wholeAddress;
                    loadingStudents>>check;
                    while(check != "'"){
                        newAddress += (check + " ");
                        loadingStudents>>check;
                    }
                }
                temporaryStudent.updateInfo(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress);
                baseOfStudents.push_back(temporaryStudent);
                loadingStudents>>check;
            } while(!loadingStudents.eof());
            baseOfStudents.pop_back();
        return;
        } /*else{
//            std::cout << "This file is empty!";}*/
    }
    else if(typeid(T) == typeid(Grades)){
        baseOfGrades.empty();
        std::ifstream importingGrades("./data/grades.txt");
//        std::cout << "File found!\n";
        Grades gradesItterator;
        std::string itterator;
        importingGrades>>itterator;
        while(!importingGrades.eof()){
            gradesItterator.setIdSubject(std::stoi(itterator));
//            std::cout << "ID of Subject found!\n";
            importingGrades>>itterator;
            gradesItterator.setIdGrades(stoi(itterator));
//            std::cout << "ID found!\n";
            importingGrades>>itterator;
            while(itterator != ">"){
                if(itterator == "!"){
                    importingGrades>>itterator;
//                    std::cout << "Importing homework grades is started!\n";
                    do{
                        gradesItterator.addHomeWorkGrade(stod(itterator));
                        importingGrades>>itterator;
                    } while(itterator != "?");
//                    std::cout << "Importing homework grades is complete!\n";
                }
                if(itterator == "?"){
                    importingGrades>>itterator;
//                    std::cout << "Importing test grades is started!\n";
                    do{
                        gradesItterator.addTestGrade(stod(itterator));
                        importingGrades>>itterator;
                    } while(itterator != "#");
//                    std::cout << "Importing test grades is complete!\n";
                }
                if(itterator == "#"){
                    importingGrades>>itterator;
//                    std::cout << "Importing semester grades is started!\n";
                    do{
                        gradesItterator.addSemesterGrade(stod(itterator));
                        importingGrades>>itterator;
                    } while(itterator != ">");
//                    std::cout << "Importing semester grades is complete!\n";
                }
            }
            importingGrades>>itterator;
            baseOfGrades.push_back(gradesItterator);
            gradesItterator.clearData();
        }
        return;
    }
    else if(typeid(T) == typeid(Subject)){
        baseOfSubjects.clear();
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
            if(itterator == "'"){
                importingSubjects>>itterator;
                do{
                    newDescription += itterator + " ";
                    importingSubjects>>itterator;
                }while(itterator != "'");
            }
            subjectsitterator.setDescription(newDescription);
//            loadItems(baseOfTeachers);
//            std::cout << "[" << newTeacherName << "]\n";
            newTeacherName.clear();
            newDescription.clear();
            baseOfSubjects.push_back(subjectsitterator);
            importingSubjects>>itterator;
            subjectsitterator.clearData();
        }
        return;
    }
    else if(typeid(T) == typeid(Teacher)){
        baseOfTeachers.clear();
        Teacher temporaryTeacher;
        std::ifstream loadingTeachers("./data/teachers.txt");
        if(!loadingTeachers.is_open()){std::cout << "Not opened" << std::endl;}
        if(loadingTeachers.peek() != std::ifstream::traits_type::eof()){
            do {
                std::string newName, newSurname, newPatronymic, newShortName, newSex, check;
                int newId, newAge;
                loadingTeachers>>newId>>newName>>newSurname>>newPatronymic;
                loadingTeachers>>check;
                if(check == "'"){
                    loadingTeachers>>check;
                    while(check != "'"){
                        newShortName += (check + " ");
                        loadingTeachers>>check;
                    }
                }
                loadingTeachers>>newAge>>newSex>>check;
//                std::cout << "Basic data was successfuly imported!\n";
                temporaryTeacher.updateInfo(newId, newName, newSurname, newPatronymic, newAge, newSex, newShortName);
                baseOfTeachers.push_back(temporaryTeacher);
//                temporaryTeacher.displayInfo();
            } while(!loadingTeachers.eof());
            baseOfTeachers.pop_back();
            loadingTeachers.close();
//            std::cout << "Attention!\n";
//            baseOfTeachers.back().displayInfo();
//            std::cin.get();
        return;
        } else{
            std::cout << "This file is empty!";
        }
    }
    else if(typeid(T) == typeid(Parent)){
        baseOfParents.clear();
//        Parent temporaryParent;
        std::ifstream loadingParents("./data/parents.txt");
        if(!loadingParents.is_open()){std::cout << "Not opened" << std::endl;}
        if(loadingParents.peek() != std::ifstream::traits_type::eof()){
            do {
                std::string newName, newSurname, newPatronymic, newSex, newAddress, newWorkName, check;
                int newId, newAge;
                loadingParents>>newId>>newName>>newSurname>>newPatronymic>>newAge>>newSex;
                loadingParents>>check;
                if(check == "'"){
                    std::string wholeAddress;
                    loadingParents>>check;
                    while(check != "'"){
                        std::cout << check << "\n";
                        newAddress += (check + " ");
                        loadingParents>>check;
                    }
                }
                if(check == "'"){
                    std::string wholeWorkName;
                    loadingParents>>check;
                    while(check != "'"){
                        newWorkName += (check + " ");
                        loadingParents>>check;
                    }
                }
                Parent temporaryParent(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress, newWorkName);
                baseOfParents.push_back(temporaryParent);
                temporaryParent.displayInfo();
                loadingParents>>check;
            } while(!loadingParents.eof());
            baseOfParents.back().displayInfo();
            baseOfParents.pop_back();
        return;
        } else{
            std::cout << "This file is empty!";}
    }
    return;
}

void Interface::createStudent(){
//    baseOfStudents.clear();
//    loadItems(baseOfStudents);
    system("cls");
    std::ofstream creatingStudent("data/students.txt", std::ios::app);
    std::string newName, newSurname, newPatronymic, newSex, newAddress, check;
    int newId, newAge;
    if(creatingStudent.is_open()){
        std::cout << "Pook\n";
        if(!baseOfStudents.empty()){
            newId = (baseOfStudents.back().getId()) + 1;

        }else{newId = 1;}
       std::string uncheckedNewName, uncheckedNewSurname, uncheckedNewPatronymic, uncheckedNewAge, uncheckedNewSex, uncheckedNewAddress;

       system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the first name: ";
       std::getline(std::cin, uncheckedNewName);
       if(uncheckedNewName == "<"){goto cncl;}
       newName = nsp_check(uncheckedNewName);
       if(newName == "<"){return;}
       system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the last name: ";
       std::getline(std::cin, uncheckedNewSurname);
       if(uncheckedNewSurname == "<"){goto cncl;}
       newSurname = nsp_check(uncheckedNewSurname);
       if(newSurname == "<"){return;}
       system("cls");
       std::cout << "(Write '<' to go back to the list)\nEnter the patronymic: ";
       std::getline(std::cin, uncheckedNewPatronymic);
       if(uncheckedNewPatronymic == "<"){goto cncl;}
       newPatronymic = nsp_check(uncheckedNewPatronymic);
       if(newPatronymic == "<"){return;}

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
       if(newAddress == "<"){return;}

       system("cls");
       creatingStudent<<newId<<" "<<newName<<" "<<newSurname<<" "<<newPatronymic<<" "<<newAge<<" "<<newSex<<" ' "<<newAddress<<" ' >"<<std::endl;
       creatingStudent.close();
       createBlankGradesForStudent(newId);
//       std::cout << "Now creating parent...\n";
       createParent(newId);
       std::cout << "The information was successfully recorded!\n";
       Sleep(300);
       std::cout << "Back to students information...";
       std::cin.get();
cncl: shouldLoad = true;
       return;
    }
}

template<typename L>
void Interface::eraseItem(std::vector<L>& baseOfItems, std::string idDoomedItem, std::string typeOfId){
    if(typeid(L) == typeid(Student)){
        baseOfStudents.clear();
        loadItems(baseOfStudents);
        loadItems(baseOfGrades);
        std::cout << "Enter the ID of the student whose data you want to erase (Write '<' to cancel): ";
        std::getline(std::cin, idDoomedItem);
        if(idDoomedItem.empty()){std::cout << "Error! Empty insertion! Back to the list..."; std::cin.get(); return;}
        if(idDoomedItem == "<"){return;}
        if (!containsOnlyDigits(idDoomedItem)) {
            std::cout << "Error! ID consist only from digits!";
            std::cin.get();
            baseOfGrades.clear();
            return;
        }

        int studentIdToErase = std::stoi(idDoomedItem);
        for (auto it = baseOfStudents.begin(); it != baseOfStudents.end(); ++it) {
            if (it->getId() == studentIdToErase) {
                std::cout << "You sure you want to erase data about student " << it->getName() << " " << it->getSurname() << "?\n";
                std::cout << "1.Yes \n2.Back \n>";
                std::string decision;
                std::getline(std::cin, decision);
                if (decision == "1") {
                    eraseItem(baseOfGrades, idDoomedItem, "marks");
                    std::cout << "Grades has been deleted! \n";
                    eraseItem(baseOfParents, idDoomedItem, "");
                    std::cout << "Parent has been deleted(.. \n";
                    baseOfStudents.erase(it);
                    saveBasesOfItems(baseOfStudents);
                    std::cout << "Student info has been deleted successfully! \nBack to the student list...";
                    shouldLoad = true;
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
    else if(typeid(L) == typeid(Grades)){
        int intIdDoomedItem = stoi(idDoomedItem);
        if(typeOfId == "marks"){
    //            std::cout << "Start erasing!\n";
            for (auto it = baseOfGrades.begin(); it != baseOfGrades.end(); ++it){
    //            std::cout << "Checking Grades with ID of: " << it->getId() << std::endl;
                if(it->getId() == intIdDoomedItem){
                    std::cout << "Erasing Grades with ID of: " << it->getId() << std::endl;
                    it = baseOfGrades.erase(it);
                    it = baseOfGrades.begin();
                }
            }
            for (auto it = baseOfGrades.begin(); it != baseOfGrades.end(); ++it){
                if(it->getId() > intIdDoomedItem){
                    it->setIdGrades(it->getId() - 1);
                }
            }
            saveBasesOfItems(baseOfGrades);
        }else if(typeOfId == "subjects"){
            for (size_t i = 0; i < baseOfGrades.size(); ){
    //            std::cout << "Checking Grades with ID of: " << it->getId() << std::endl;
                if(baseOfGrades[i].getIdSubject() == intIdDoomedItem){
                    std::cout << baseOfGrades[i].getIdSubject() << std::endl;
                    std::cin.get();
                    std::cout << "Erasing Grades with ID of: " << baseOfGrades[i].getId() << std::endl;
                    baseOfGrades.erase(baseOfGrades.begin() + i);
                    i = 0;
                }else i++;
            }
//            saveBasesOfItems(baseOfGrades);
        }
    }
    //==============================================================================================
    else if(typeid(L) == typeid(Subject)){
        std::cout << "Enter the ID of the subject whose data you want to erase (Write '<' to cancel): ";
        std::getline(std::cin, idDoomedItem);
        if(idDoomedItem.empty()){std::cout << "Error! Empty insertion! Back to the list..."; std::cin.get(); return;}
        if(idDoomedItem == "<"){return;}
        if (!containsOnlyDigits(idDoomedItem)) {
            std::cout << "Error! ID consist only from digits!";
            std::cin.get();
            baseOfGrades.clear();
            baseOfSubjects.clear();
            return;
        }

        baseOfSubjects.clear();
        baseOfGrades.clear();
        loadItems(baseOfSubjects);
        loadItems(baseOfGrades);
        int subjectIdToErase = std::stoi(idDoomedItem);
        for (auto it = baseOfSubjects.begin(); it != baseOfSubjects.end(); ++it) {
            if (it->getIdSubject() == subjectIdToErase) {
                std::cout << "You sure you want to erase data about subject '" << it->getName() << "'?\n";
                std::cout << "1.Yes \n2.Back \n>";
                std::string decision;
                std::getline(std::cin, decision);
                if (decision == "1") {
                    loadItems(baseOfTeachers);
                    if(baseOfSubjects.size() > 1){
                        std::string shortNameOfTeacher = it->getTeacher();
                        eraseItem(baseOfGrades, idDoomedItem, "subjects");
                        baseOfSubjects.erase(it);
                        int subjectCount = 0;
                        for(Subject thatoneSubject : baseOfSubjects){
                            if(thatoneSubject.getTeacher() == shortNameOfTeacher)
                            {
                                subjectCount++;
                            }
                        }
                        if(subjectCount == 0){
                            if(baseOfTeachers.size() <= 1){baseOfTeachers.clear(); saveBasesOfItems(baseOfTeachers);}
                            else{
                                for (auto it = baseOfTeachers.begin(); it != baseOfTeachers.end(); ++it) {
                                    if(it->getShortName() == shortNameOfTeacher){
                                        eraseItem(baseOfTeachers, std::to_string(it->getId()), "");
                                    }
                                }
                            }
                        }
                    }else{
                        baseOfSubjects.clear();
                        baseOfTeachers.clear();
                        saveBasesOfItems(baseOfTeachers);
                    }
                    saveBasesOfItems(baseOfSubjects);
                    saveBasesOfItems(baseOfGrades);
                    shouldLoad = true;
                    clearAllBases();
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
    else if(typeid(L) == typeid(Teacher)){
        int teacherIdToErase = std::stoi(idDoomedItem);
        for (auto it = baseOfTeachers.begin(); it != baseOfTeachers.end(); ++it) {
            if (it->getId() == teacherIdToErase) {
                if(baseOfTeachers.size() == 1){baseOfTeachers.clear();}
                else{it = baseOfTeachers.erase(it);}
                saveBasesOfItems(baseOfTeachers);
                std::cout << "Teacher info has been deleted successfully! \n";
                std::cin.get();
                return;
            }
        }
    }else if(typeid(L) == typeid(Parent)){
        std::cout << "gonna load tha shi...\n";
        loadItems(baseOfParents);
        std::cout << "Get ready to be deleted!\n"<<baseOfParents.size()<<std::endl;
        if(baseOfParents.size() == 1){baseOfParents.clear();}
        else{
            for(auto it = baseOfParents.begin(); it != baseOfParents.end(); it++){
                if(it->getId() == stoi(idDoomedItem)){
                    it = baseOfParents.erase(it);
                }
            }
        }
        saveBasesOfItems(baseOfParents);
        std::cout << "Parent info has been deleted successfully!\n";
    }
}



template<typename T>
void Interface::sortItems(std::vector<T>& baseOfItems){
    if(typeid(baseOfItems[0]) == typeid(Parent) || typeid(baseOfItems[0]) == typeid(Student) || typeid(baseOfItems[0]) == typeid(Teacher)){
        bool increase = true;
s:      system("cls");
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
            bubbleSortInc(baseOfItems, "i");
            shouldLoad = false;
            return;
        }else if(decition == "1" && !increase){
            bubbleSortDec(baseOfItems, "i");
            shouldLoad = false;
            return;
        }else if(decition == "2" && increase){
            bubbleSortInc(baseOfItems, "n");
            shouldLoad = false;
            return;
        }else if(decition == "2" && !increase){
            bubbleSortDec(baseOfItems, "n");
            shouldLoad = false;
            return;
        }else if(decition == "3" && increase){
            bubbleSortInc(baseOfItems, "sn");
            shouldLoad = false;
            return;
        }else if(decition == "3" && !increase){
            bubbleSortDec(baseOfItems, "sn");
            shouldLoad = false;
            return;
        }else if(decition == "4" && increase){
            bubbleSortInc(baseOfItems, "ag");
            shouldLoad = false;
            return;
        }else if(decition == "4" && !increase){
            bubbleSortDec(baseOfItems, "ag");
            shouldLoad = false;
            return;
        }else if(decition == "5" && increase){
            bubbleSortInc(baseOfItems, "s");
            shouldLoad = false;
            return;
        }else if(decition == "5" && !increase){
            bubbleSortDec(baseOfItems, "s");
            shouldLoad = false;
            return;
        }else if(decition == "6" && increase){
            bubbleSortInc(baseOfItems, "ad");
            shouldLoad = false;
            return;
        }else if(decition == "6" && !increase){
            bubbleSortDec(baseOfItems, "ad");
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
}
void Interface::sortItems(std::vector<Grades>& baseOfItems){
    if(typeid(baseOfItems[0]) == typeid(Grades)){
        for(int i = 0; i < static_cast<int>(baseOfGrades.size()) - 1; i++){
            for(int j = (i + 1); j < static_cast<int>(baseOfGrades.size()); ++j){
                if(baseOfGrades[i].getId() > baseOfGrades[j].getId()){
                    std::swap(baseOfGrades[i], baseOfGrades[j]);
                }
            }
        }
        for(int i = 0; i < static_cast<int>(baseOfGrades.size()) - 1; i++){
            for(int j = i; j < static_cast<int>(baseOfGrades.size()) - 1; j++){
                if(baseOfGrades[j].getIdSubject() > baseOfGrades[j+1].getIdSubject()){
                    std::swap(baseOfGrades[j], baseOfGrades[j+1]);
                }
            }
        }
//        for(Grades grade : baseOfGrades){
//            std::cout << grade.getId() << std::endl;
//        }
        std::cout << "Sorting is completed!\n";
        saveBasesOfItems(baseOfGrades);
    }
}

void Interface::sortItems(std::vector<Subject>& baseOfItems){
    bool increase = true;
s:  system("cls");
    std::cout << "Sort by (";
    if(increase){
        std::cout << rang::style::underline << "Increase" << rang::style::reset;
    }else{ std::cout << rang::style::underline << "Decrease" << rang::style::reset;}
    std::cout << "): \n1.ID \n2.Name \n3.Teacher Id \n4.Teacher \n5.Description \n6.Switch sort direction \n7.Back \n\n>";
    std::string decition;
    std::getline(std::cin, decition);
    system("cls");
    if(decition.empty()) {std::cout << "Error! Empty insertion! Back to the list..."; std::cin.get(); return;}
    if(!containsOnlyDigits(decition)) {std::cout << "Error! Insertion must contain only digits! Back to the list..."; std::cin.get(); return;}
    if(decition == "1" && increase){
        bubbleSortIncS(baseOfItems, "i");
        shouldLoad = false;
        return;
    }else if(decition == "1" && !increase){
        bubbleSortDecS(baseOfItems, "i");
        shouldLoad = false;
        return;
    }else if(decition == "2" && increase){
        bubbleSortIncS(baseOfItems, "n");
        shouldLoad = false;
        return;
    }else if(decition == "2" && !increase){
        bubbleSortDecS(baseOfItems, "n");
        shouldLoad = false;
        return;
    }else if(decition == "3" && increase){
        bubbleSortIncS(baseOfItems, "ti");
        shouldLoad = false;
        return;
    }else if(decition == "3" && !increase){
        bubbleSortDecS(baseOfItems, "ti");
        shouldLoad = false;
        return;
    }else if(decition == "4" && increase){
        bubbleSortIncS(baseOfItems, "t");
        shouldLoad = false;
        return;
    }else if(decition == "4" && !increase){
        bubbleSortDecS(baseOfItems, "t");
        shouldLoad = false;
        return;
    }else if(decition == "5" && increase){
        bubbleSortIncS(baseOfItems, "d");
        shouldLoad = false;
        return;
    }else if(decition == "5" && !increase){
        bubbleSortDecS(baseOfItems, "d");
        shouldLoad = false;
        return;
    }else if(decition == "6" && increase){
        increase = false;
        goto s;
    }else if(decition == "6" && !increase){
        increase = true;
        goto s;
    }else if(decition == "7"){
        return;
    }
    goto s;
}


std::string Interface::nsp_check(std::string item) {
    if(item.empty()){
        std::cout << "Error! Insertion cannot be empty! Try again: ";
        std::getline(std::cin, item);
        return nsp_check(item);
    }
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
        std::getline(std::cin, decition);
        if(decition == "1"){
            system("cls");
        }else if(decition == "2"){
            system("cls");
            std::string newItem;
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter another variant: ";
            std::getline(std::cin, newItem);
            return nsp_check(newItem);
        }else if(decition == "<"){return "<";}

    }
    if(firstItem.size() > 16){
        std::cout << "\nSorry, but this insertion is too large. Sybols limit = 16 \nTry again: ";
        std::string newItem;
        std::getline(std::cin, newItem);
        return nsp_check(newItem);
    }
    return firstItem;
}
int Interface::age_check(std::string uncheckedNewAge){
    if(containsOnlyDigits(uncheckedNewAge)){
        if(uncheckedNewAge.empty()){
            std::cout << "Age value cannot be empty! Try again: ";
            std::string newValue;
            std::getline(std::cin, newValue);
            return age_check(newValue);
        }
        int checkedAge = std::stoi(uncheckedNewAge);
        if(checkedAge < 6){
            std::cout << "Age value is too low! Try again: ";
            std::string newValue;
            std::getline(std::cin, newValue);
            return age_check(newValue);
        }else if(checkedAge > 99){
            std::cout << "Age value is too high! Try again: ";
            std::string newValue;
            std::getline(std::cin, newValue);
            return age_check(newValue);
        }
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
    if(uncheckedNewAddress.empty()){
        std::cout << "Address cannot be empty! Try again \n>";
        std::string newValue;
        std::getline(std::cin, newValue);
        return address_check(newValue);
    }else{
        if(uncheckedNewAddress == "<"){return "<";}
        std::string checkedNewAddress = uncheckedNewAddress;
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
}

void Interface::createBlankGradesForStudent(int idStudent){
    std::cout << "Start to create new blank grades!\n";
    baseOfGrades.clear();
    loadItems(baseOfGrades);
    std::ofstream createNewGrades("./data/grades.txt", std::ios::app);
    if(baseOfGrades.empty()){
        loadItems(baseOfSubjects);
        if(!baseOfSubjects.empty()){
            for(Subject subject : baseOfSubjects){
                createNewGrades<<subject.getIdSubject()<<" "<<idStudent<<" ! ";
                for(int i = 0; i < 10; i++){createNewGrades<<"0"<<" ";}
                createNewGrades<<"? ";
                for(int i = 0; i < 10; i++){createNewGrades<<"0"<<" ";}
                createNewGrades<<"# ";
                for(int i = 0; i < 10; i++){createNewGrades<<"0"<<" ";}
                createNewGrades<<">"<<std::endl;
                std::cout << "Created successfuly!\n";
                std::cin.get();
            }
        }
    }
    else{
        int counter = 0;
        int idSubject = 1;
        do{
            createNewGrades<<idSubject<<" "<<idStudent<<" ! ";
            int amountHomeWorkGrades = baseOfGrades[counter].getHomeWorkGrades().size();
            int amountTestGrades = baseOfGrades[counter].getTestGrades().size();
            int amountSemesterGrades = baseOfGrades[counter].getSemesterGrades().size();
            std::cout << "[" << amountHomeWorkGrades << "|" << amountTestGrades << "|" << amountSemesterGrades << "]\n";
            for(int i = 0; i < amountHomeWorkGrades; i++){createNewGrades<<"0"<<" ";}
            createNewGrades<<"? ";
            for(int i = 0; i < amountTestGrades; i++){createNewGrades<<"0"<<" ";}
            createNewGrades<<"# ";
            for(int i = 0; i < amountSemesterGrades; i++){createNewGrades<<"0"<<" ";}
            createNewGrades<<">"<<std::endl;
            std::cout << "Cycle " << idSubject << std::endl;
            while(counter < baseOfGrades.size() && baseOfGrades[counter].getIdSubject() == idSubject){
                counter++;
            }
            std::cout << "[" << counter << "]\n";
            idSubject++;
        }while(counter < baseOfGrades.size());
    }
    createNewGrades.close();
//    std::cout << "Grades are saved!\n";
    baseOfGrades.clear();
    loadItems(baseOfGrades);
    sortItems(baseOfGrades);
    saveBasesOfItems(baseOfGrades);
    baseOfGrades.clear();
}

std::string info_check(std::string item);
void Interface::createSubject(){
    baseOfSubjects.clear();
    loadItems(baseOfSubjects);
    system("cls");
    std::ofstream creatingSubject("data/subjects.txt", std::ios::app);
    std::string newName, newTeacher, newDescription, check;
    int newIdSubject, newIdTeacher;
    bool newTeacherInfo = true;
    if(creatingSubject.is_open()){
        if(!baseOfSubjects.empty()){
            newIdSubject = (baseOfSubjects.back().getIdSubject()) + 1;
        }
        else{newIdSubject = 1;}
//       std::cout << baseOfSubjects.back().getName() << std::endl;
//       std::cout << newId << std::endl;
        std::string uncheckedNewName, uncheckedNewTeacher, uncheckedNewDescription;

        system("cls");
        std::cout << "(Write '<' to go back to the list)\nEnter the name of the subject: ";
        std::getline(std::cin, uncheckedNewName);
        if(uncheckedNewName == "<"){return;}
        newName = info_check(uncheckedNewName);
        if(newName == "<"){return;}

        system("cls");
        std::cout << "(Write '<' to go back to the list)\nEnter the teacher's short name (Example: Voloshchuk M. V., ): ";
        std::getline(std::cin, uncheckedNewTeacher);
        if(uncheckedNewTeacher == "<"){return;}
        newTeacher = info_check(uncheckedNewTeacher);
        if(newTeacher == "<"){return;}
        for(Subject thatOneSubject : baseOfSubjects){
            if(thatOneSubject.getTeacher() == newTeacher + " "){
                newTeacherInfo = false;
                newIdTeacher = (thatOneSubject.getIdTeacher());
            }
        }

        system("cls");
        std::cout << "(Write '<' to go back to the list)\nEnter the description of the subject: ";
        std::getline(std::cin, uncheckedNewDescription);
        if(uncheckedNewDescription == "<"){return;}
        newDescription = info_check(uncheckedNewDescription);
        if(newDescription == "<"){return;}

        system("cls");
        if(newTeacherInfo){
            if(baseOfSubjects.empty()){
                newIdTeacher = 1;
            }else{
                for(Subject thatOneSubject : baseOfSubjects){
                    if(thatOneSubject.getIdTeacher() >= newIdTeacher){
                        newIdTeacher = thatOneSubject.getIdTeacher() + 1;
                    }
                }
            }
        }


        system("cls");
        std::cout << "IdSubject = " << newIdSubject << std::endl;

        creatingSubject<<newIdSubject<< " ' " << newName << " ' " << newIdTeacher << " ' "
                       << newTeacher <<  " ' " << newDescription << " '"<<std::endl;
        creatingSubject.close();
        baseOfSubjects.clear();
        loadItems(baseOfSubjects);
        createBlankGrades(newIdSubject);
        std::cout << "The information was successfully recorded!\n";
        Sleep(300);

newT:
        if(newTeacherInfo){
            std::cin.get();
            system("cls");
            loadItems(baseOfSubjects);
//            bool coinsidance = false;
//            for(Subject subject : baseOfSubjects){
//                if(subject.getTeacher() == newTeacher + " "){
//                    coinsidance = true;
//                }
//            }if(coinsidance){
//                saveBasesOfItems(baseOfSubjects);
//                clearAllBases();
//                return;
//            }
            std::cout << "We have noticed that " << newTeacher << " is not recorded in the database, so you have to fill the data about this teacher. \nWould you like to continue?\n"
                      << "1.Yes \n2.Rewrite name\n>";
            std::string decition;
            std::getline(std::cin, decition);
            if(!decition.empty()){
                if(decition == "1"){
                    createTeacher(newTeacher);
                    loadItems(baseOfSubjects);
                    for(Subject thatOneSubject : baseOfSubjects){
                        if(thatOneSubject.getTeacher() == newTeacher + " "){
                            loadItems(baseOfTeachers);
                            for(Teacher thatOneTeacher : baseOfTeachers){
                                if(thatOneTeacher.getShortName() == newTeacher + " "){
                                    thatOneSubject.setIdTeacher(thatOneTeacher.getId());
                                    saveBasesOfItems(baseOfSubjects);
                                }
                            }
                            baseOfTeachers.clear();
                        }
                    }
                }else if(decition == "2"){
                    std::cout << "Write new value: ";
                    newTeacher.clear();
                    std::getline(std::cin, newTeacher);
                    baseOfSubjects.back().setTeacher(newTeacher);
                    for(size_t i = 0; i < baseOfSubjects.size() - 1; i++){
                        if(baseOfSubjects[i].getTeacher() == newTeacher + " "){
                            newTeacherInfo = false;
                        }
                    }
                    saveBasesOfItems(baseOfSubjects);
                    goto newT;
                }
                clearAllBases();
                return;
            }else if(decition != "1" && decition != "2"){
                std::cout << "Wrong insertion!\n";
                std::cin.get();
                goto newT;
            }
        }else {
            baseOfSubjects.clear();
            std::cout << "Back to subjects information...";
            std::cin.get();
        }
        return;
    }
}
std::string Interface::info_check(std::string item){
    if(item.empty()){
        std::cout << "Insertion cannot be empty!\n";
        std::cin.get();
        return "<";
    }
    std::cout << "' " << item << " ' is that the right insertion? (write '<' to cancel)\n1.Yes \n2.Rewrite \n>";
    std::string decition;
    std::getline(std::cin, decition);
    if(decition == "1"){
        return item;
    }else if(decition == "2"){
        std::cout << "\nEnter another variant (write '<' to cancel): ";
        std::string anotherNewName;
        std::getline(std::cin, anotherNewName);
        return info_check(anotherNewName);
    }else if(decition == "<"){return "<";}
    return info_check(item);
}

void Interface::createTeacher(std::string shortName){
    baseOfTeachers.clear();
    loadItems(baseOfTeachers);
    system("cls");
    std::ofstream creatingTeacher("data/teachers.txt", std::ios::app);
    std::string newName, newSurname, newPatronymic, newShortName, newSex, check;
    int newId, newAge;
    newShortName = shortName;
    if(creatingTeacher.is_open()){
       if(!baseOfTeachers.empty()){
            newId = (baseOfTeachers.back().getId()) + 1;
       }else{newId = 1;}
       std::string uncheckedNewName, uncheckedNewSurname, uncheckedNewPatronymic, uncheckedNewShortName, uncheckedNewAge, uncheckedNewSex;

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
       creatingTeacher<<newId<<" "<<newName<<" "<<newSurname<<" "<<newPatronymic<<" ' "<<newShortName<<" ' "<<newAge<<" "<<newSex<<" >"<<std::endl;
       creatingTeacher.close();
       std::cout << "The information was successfully recorded!\n";
       Sleep(300);
       std::cout << "Back to subjects information...";
       std::cin.get();
cncl: shouldLoad = true;
       return;
    }
}

void Interface::createBlankGrades(int idSubject){
    loadItems(baseOfGrades);
    loadItems(baseOfStudents);
    int amountOfStudents;
    if(!baseOfStudents.empty()){
        amountOfStudents = baseOfStudents.size();
    }else{
        amountOfStudents = 0;
    }
//    std::cout << "[" << amountOfStudents << "]\n";
//    std::cin.get();
    baseOfStudents.clear();
    std::vector<double> homeWorkGrades;
    std::vector<double> testGrades;
    std::vector<double> semesterGrades;
    for(size_t i = 0; i < 10; i++){
        homeWorkGrades.push_back(0.0);
    }
    for(size_t i = 0; i < 3; i++){
        testGrades.push_back(0.0);
    }
    for(size_t i = 0; i < 1; i++){
        semesterGrades.push_back(0.0);
    }
    for(size_t i = 0; i < amountOfStudents; i++){
        Grades blankGradesVector(i+1, idSubject, homeWorkGrades, testGrades, semesterGrades);
        baseOfGrades.push_back(blankGradesVector);
//        std::cin.get();
        blankGradesVector.clearData();
    }
    saveBasesOfItems(baseOfGrades);
    baseOfGrades.clear();
}

void Interface::createAndAddBlankGrades(int idSubject){
    for(size_t i = 0; i < baseOfGrades.size(); i++){
        if(baseOfGrades[i].getIdSubject() == idSubject){
            std::vector<double> hmGrades = baseOfGrades[i].getHomeWorkGrades();
            std::vector<double> tGrades = baseOfGrades[i].getTestGrades();
            std::vector<double> sGrades = baseOfGrades[i].getSemesterGrades();
            for(int j = 0; j < 10; j++){
                hmGrades.push_back(0);
            }
            for(int j = 0; j < 3; j++){
                tGrades.push_back(0);
            }
            sGrades.push_back(0);
            baseOfGrades[i].setGrades('h', hmGrades);
            baseOfGrades[i].setGrades('t', tGrades);
            baseOfGrades[i].setGrades('s', sGrades);
        }
    }
    saveBasesOfItems(baseOfGrades);
    baseOfGrades.clear();
}
void Interface::removeExistantGradesPage(int idSubject){
    loadItems(baseOfGrades);
    for(size_t i = 0; i < baseOfGrades.size(); i++){
        if(baseOfGrades[i].getIdSubject() == idSubject){
            std::vector<double> hmGrades = baseOfGrades[i].getHomeWorkGrades();
            std::vector<double> tGrades = baseOfGrades[i].getTestGrades();
            std::vector<double> sGrades = baseOfGrades[i].getSemesterGrades();
            if(hmGrades.size() > 10){
                for(int j = 0; j < 10; j++){
                    hmGrades.pop_back();
                }
                for(int j = 0; j < 3; j++){
                    tGrades.pop_back();
                }
                sGrades.pop_back();
                baseOfGrades[i].setGrades('h', hmGrades);
                baseOfGrades[i].setGrades('t', tGrades);
                baseOfGrades[i].setGrades('s', sGrades);
            }
        }
    }
    saveBasesOfItems(baseOfGrades);
    baseOfGrades.clear();
}

void Interface::createParent(int idParent){
    baseOfParents.clear();
    loadItems(baseOfParents);
    Parent newParent(idParent, "None", "None", "None", 0, "None", "None", "None");
    newParent.displayInfo();
    baseOfParents.push_back(newParent);
    std::cout << "Gonna save it!\n";
    saveBasesOfItems(baseOfParents);
    std::cout << "Saved!\n";
    baseOfParents.clear();
}

bool Interface::selectStudent(std::string selectedId){
    loadItems(baseOfStudents);
    for(size_t i = 0; i < baseOfStudents.size(); i++){
        if(baseOfStudents[i].getId() == stoi(selectedId)){
            delete selectedStudent;
            selectedStudent = new Student(baseOfStudents[i]);
            std::cout << "Student has been selected!\n";
            Sleep(1000);
            return true;
        }
    }
    std::cout << "Student wasn't found((((";
    baseOfStudents.clear();
    std::cin.get();
    return false;
}

void viewStudentSubjects();
void Interface::viewStudent(){
    clearAllBases();
    std::string selection;
    std::cout << "Enter ID of the student you want to check: ";
    std::getline(std::cin, selection);
    if(selection.empty()){std::cout << "Error! Entered nothing!\n"; std::cin.get(); return;}
    bool result = selectStudent(selection);
    if(result){
a2:     baseOfGrades.clear();
        baseOfSubjects.clear();
        loadItems(baseOfGrades);
        loadItems(baseOfSubjects);
        int checkConnect = connectGradesToStudent(selectedStudent);
        if(checkConnect == 0){return;}
        system("cls");
        selectedStudent->displayInfo();
        if(!baseOfSubjects.empty()){
            for(Subject thisSubject : baseOfSubjects){
                std::cout << "*" << thisSubject.getName() << std::endl;
            }
            std::cout << "\n";
            std::cout << "Action: \n1.View grades \n2.View parent \n3.Edit student \n0.Back \n\n>";
            std::string decition;
            std::getline(std::cin, decition);
            if(!decition.empty()){
                if(decition == "1"){
                    baseOfGrades.clear();
                    baseOfSubjects.clear();
                    viewStudentSubjects();
                }else if(decition == "2"){
                    viewParent(selectedStudent->getId());
                }else if(decition == "3"){
                    editItem(baseOfStudents);
                }else if(decition == "0"){
                    selectedGrades->clearData();
                    selectedSubject->clearData();
                    clearAllBases();
                    shouldLoad = true;
                    return;
                }
            }else{
                baseOfGrades.clear();
                baseOfSubjects.clear();
                goto a2;
            }
        }else{
            std::cout << "\n";
            std::cout << "Action: \n1.Edit student \n0.Back \n\n>";
            std::string decition;
            std::getline(std::cin, decition);
            if(!decition.empty()){
                if(decition == "1"){
                    goto a2;
                }else if(decition == "0"){
                    selectedGrades->clearData();
                    selectedSubject->clearData();
                    clearAllBases();
                    shouldLoad = true;
                    return;
                }
            }else{
                baseOfGrades.clear();
                baseOfSubjects.clear();
                goto a2;
            }
        }
    }else{return;}
    goto a2;
}
void Interface::viewStudentSubjects(){
a3: baseOfGrades.clear();
    baseOfSubjects.clear();
    loadItems(baseOfGrades);
    loadItems(baseOfSubjects);
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
    std::cout << "Action: \n*View grades \n*View parent \n*Edit student \n0.Back \n\nEnter subject ID: \n>";
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
    loadItems(baseOfGrades);
    system("cls");
    for(Grades thatOneListOfGrades : baseOfGrades){
        if(thatOneListOfGrades.getId() == idGrades && thatOneListOfGrades.getIdSubject() == idSubject){
            std::cout << rang::style::bold << rang::style::underline << "Subject: " << name << rang::style::reset << std::endl;
            thatOneListOfGrades.displayInfo();
            std::cin.get();
            return;
        }
    }
    std::cin.get();
}

void Interface::displayGradesToEdit(std::string nameOfGradesList, std::vector<double> gradesForEdit){
    std::cout <<rang::style::underline << nameOfGradesList << " grades(";
    if(nameOfGradesList == "Home work"){ std::cout << "!";}
    else if(nameOfGradesList == "Test"){ std::cout << "@";}
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
        if(selectGrades.getId() == idStudent){
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


bool Interface::containsOnlyDigits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void Interface::clearAllBases(){
    baseOfGrades.clear();
    baseOfStudents.clear();
    baseOfSubjects.clear();
    baseOfTeachers.clear();
    baseOfParents.clear();
    return;
}


Interface::Interface(){}

Interface::~Interface(){
    baseOfGrades.clear();
    baseOfStudents.clear();
    baseOfSubjects.clear();
    baseOfTeachers.clear();
    baseOfParents.clear();
    if(selectedStudent != nullptr){ delete selectedStudent; }
    if(selectedGrades != nullptr){ delete selectedGrades; }
    if(selectedSubject != nullptr){ delete selectedSubject; }
    if(selectedTeacher != nullptr){ delete selectedTeacher; }
    if(selectedParent != nullptr){ delete selectedParent; }
    std::cout << rang::fg::blue << "Destructor of Interface class was called!" << rang::fg::reset << std::endl;
}


