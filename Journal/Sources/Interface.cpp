#include <iostream>
#include <iomanip>
#include <windows.h>

#include "Interface.h"


int Interface::startMenu(){
    std::cout << "MyJournal 0.1.3 \n" << std::endl;
    std::cout << "(Type '/?' for 'user manual'; type '/quit' to exit)" << std::endl;

    Sleep(500);

    std::string decition;
    std::cout << std::endl;
    std::cout << "Welcome!" << std::endl;
    std::cout << "1.Student information. \n2.View grades. \n3.Teacher info. \n" << std::endl;
    std::cout << ">";
    std::getline(std::cin, decition);

    if(decition == "/quit"){
        return 0;
    }else if(decition == "1"){
        studentInfo();
        }
     else {
        system("cls");
        startMenu();
    }

    }

void Interface::studentInfo() {
    system("cls");
    std::cout << "======================================================================================" << std::endl;
    std::cout << " ID " << std::setw(5) << "|| Full name " << std::setw(40) << " || Age " << std::setw(10) << " || Sex " << std::setw(10) << " || Adress " << std::endl;
    std::cin.get();
    return;
}

Interface::Interface(){}


