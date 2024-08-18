#include <iostream>
#include <string.h>

#include "./Headers/Person.h"
#include "./Headers/Parent.h"
#include "./Headers/Student.h"
#include "./Headers/Teacher.h"

using namespace std;

int main()
{
    Student * mark = new Student(1, "Mark", "Voloshchuk", "Serhiyovich", 12, "male", "Hauwr");
    mark->displayInfo();
    Parent * sergiy = new Parent(2, "Serhiy", "Voloshchuk", "Viktorovych", 32, "male", "Hauwr", "Jobless");
    sergiy->displayInfo();
}
