#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <list>

#include "./Student.h"

class Subject
{
private:
    std::string name;
    std::string teacher;
    int idOfTeacher;
    std::string description;
public:

    std::list<Subject> listOfStudents;

    std::string getName();
    std::string getTeacher();
    int getIdOfTeacher();
    std::string getDescription();

    void setName(std::string newName);
    void setTeacher(std::string newTeacher);
    void setIdOfTeacher(int newIdOfTeacher);
    void setDescription(std::string newDescription);

    void displayName();
    void displayTeacher();
    void displayIdOfTeacher();
    void displayDescription();
    void displayInfo();

    Subject();
    Subject(std::string newName);
    Subject(std::string newName, std::string newTeacher);
    Subject(std::string newName, std::string newTeacher, int newIdOfTeacher);
};

#endif // SUBJECT_H
