#include <iostream>
#include <string.h>

#include "./Headers/Person.h"
#include "./Headers/Parent.h"
#include "./Headers/Student.h"
#include "./Headers/Teacher.h"
#include "./Headers/Subject.h"
#include "./Headers/Grades.h"
#include "./Headers/Interface.h"



using namespace std;

int main(){
    Student * meow = new Student(1, "Mark", "Voloshchuk", "Serhiyovich", 12, "male", "Hauwr");
    Student * woof = new Student(2, "Sergey", "Voloshchuk", "Serhiyovich", 12, "male", "Hauwr");

    Interface* interfaces = new Interface;
//    interfaces->importMarks();
//    interfaces->eraseMarks(2);
//    interfaces->saveMarks();
//    interfaces->connectMarksToStudent(meow);
//    interfaces->connectMarksToStudent(woof);
//    interfaces->loadStudents();
//    interfaces->createStudent();
    interfaces->startMenu();

    delete interfaces;
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
