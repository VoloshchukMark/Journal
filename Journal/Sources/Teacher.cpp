#include "../Headers/Teacher.h"

#include "../Headers/Person.h"

#include <iostream>



Teacher::Teacher()
    :Teacher(0, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId)
    :Teacher(newId, "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName)
    :Teacher(newId, newName, "Unknown", "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname)
    :Teacher(newId, newName, newSurname, "Unknown", 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic)
    :Teacher(newId, newName, newSurname, newPatronymic, 0, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge)
    :Teacher(newId, newName, newSurname, newPatronymic, newAge, "Unknown", "Unknown") {}
Teacher::Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress)
    :Person(newId, newName, newSurname, newPatronymic, newAge, newSex, newAddress) {}
