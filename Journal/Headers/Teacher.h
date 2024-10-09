#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "Subject.h"

#include <iostream>
#include <vector>

class Teacher :public Person
{
private:
    std::vector<Subject> subjects;
public:

    void displayInfo() override;

    void addSubject(std::string newName);
    void displayInfoOfSubjects();

    Teacher();
    Teacher(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);

    ~Teacher();
};

#endif // TEACHER_H
