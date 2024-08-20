#include <iostream>
#include <string.h>

#include "./Headers/Person.h"
#include "./Headers/Parent.h"
#include "./Headers/Student.h"
#include "./Headers/Teacher.h"
#include "./Headers/Subject.h"
#include "./Headers/Marks.h"

using namespace std;

int main()
{
//    Student * mark = new Student(1, "Mark", "Voloshchuk", "Serhiyovich", 12, "male", "Hauwr");
//    mark->displayInfo();
//    Parent * sergiy = new Parent(2, "Serhiy", "Voloshchuk", "Viktorovych", 32, "male", "Hauwr", "Jobless");
//    sergiy->displayInfo();
//    Subject * math = new Subject("Math", "Mark Voloshchuk", 1);
//    math->displayInfo();
    Marks * marm = new Marks();
    marm->addHomeWorkMark(10.0);
    marm->addHomeWorkMark(3.0);
    marm->addSemesterMark(12.0);
    marm->calculateGeneralMark();
    marm->displayHomeWorkMark();
    marm->displayGeneralMark();
}
