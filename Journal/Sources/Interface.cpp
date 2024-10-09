#include <iostream>
#include <windows.h>

#include "Interface.h"


void Interface::startMenu(){
    std::cout << "MyJournal 0.1.1 \n" << std::endl;
    std::cout << "(Type '\help' or '\?' for 'user manual'; type '\quit' to exit.)" << std::endl;

    Sleep(500);

    std::cout << std::endl;
    std::cout << "Welcome!" << std::endl;
    std::cout << "1.Student information. \n2.View grades. \n3.Teacher info. \n" << std::endl;


    std::cout << ">" << std::endl;
    }

Interface::Interface(){}


