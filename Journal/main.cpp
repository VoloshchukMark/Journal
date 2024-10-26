#include <iostream>

#include "./Headers/Interface.h"



using namespace std;

int main(){
    Interface* interfaces = new Interface;
    interfaces->startMenu();

    delete interfaces;
    }
