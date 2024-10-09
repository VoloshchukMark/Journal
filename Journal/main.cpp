#include <iostream>
#include <string.h>

#include "./Headers/Person.h"
#include "./Headers/Parent.h"
#include "./Headers/Student.h"
#include "./Headers/Teacher.h"
#include "./Headers/Subject.h"
#include "./Headers/Marks.h"
#include "./Headers/Interface.h"


using namespace std;

int main(){

    Student* student = new Student(2, "Mark", "Voloshchuk", "Victrovych", 18, "Male", "Aoaoaoaoa");
    student->displayInfo();

    std::cout << std::endl;

    Parent* parent = new Parent(2, "Mark", "Voloshchuk", "Victrovych", 18, "Male", "Aoaoaoaoa", "Slave");
    parent->displayInfo();

    std::cout << std::endl;

    Teacher* teacher = new Teacher(2, "Mark", "Voloshchuk", "Victrovych", 18, "Male", "Aoaoaoaoa");
    teacher->displayInfo();

    std::cout << std::endl;

//    Interface interface;
//    interface.startMenu();

    delete student;
    std::cout << std::endl;
    delete parent;
    std::cout << std::endl;
    delete teacher;
    std::cout << std::endl;
    }



//    Student * meow = new Student(1, "Mark", "Voloshchuk", "Serhiyovich", 12, "male", "Hauwr");
//    mark->displayInfo();
//    Parent * sergiy = new Parent(2, "Serhiy", "Voloshchuk", "Viktorovych", 32, "male", "Hauwr", "Jobless");
//    sergiy->displayInfo();
//    Subject * math = new Subject("Math", "Mark Voloshchuk", 1);
//    math->displayInfo();
//    Teacher * mark = new Teacher(1, "Mark", "Voloshchuk", "Victorovych", 18, "male", "Chernivtsy city");
//    mark->addSubject("Math");
//    mark->displayInfoOfSubjects();
//    meow->marks.displayGeneralMark();
