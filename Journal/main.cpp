#include <iostream>
#include <string.h>

#include "./Headers/Person.h"
#include "./Headers/Parent.h"
#include "./Headers/Student.h"

using namespace std;

int main()
{
    Student * mark = new Student(1, "Mark");
    mark->setAge(18);
    mark->displayAge();
    mark->setName("MakaPopka228");
    mark->displayName();
    std::cout << std::endl;
    Parent * sasha = new Parent(1, "Oleksandr", "Golyuk", "Markovych", 81, "Male", "Homeless", "Jobless");
    sasha->displayName();
    sasha->displaySurname();
    sasha->displayPatronymic();
    return 0;
}
