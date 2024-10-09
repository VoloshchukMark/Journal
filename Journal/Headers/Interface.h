#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>

#include "Student.h"

class Interface
{
public:

    std::vector<Student> temporaryStudents;


    static void startMenu();


    Interface();
};

#endif // INTERFACE_H
