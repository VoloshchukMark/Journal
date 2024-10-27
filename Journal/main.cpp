#include <iostream>

#include "./Headers/Interface.h"

bool showConDesMessages = false;

using namespace std;

int main(){
    Interface* interfaces = new Interface;
    interfaces->startMenu();

    delete interfaces;
    }
