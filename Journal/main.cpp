#include <iostream>
#include <string.h>

#include "Person.h"
#include "Student.h"

using namespace std;

int main()
{
    Student * mark = new Student(1, "Mark");
    mark->setAge(18);
    mark->displayAge();
    mark->setName("MakaPopka228");
    mark->displayName();
    return 0;
}
