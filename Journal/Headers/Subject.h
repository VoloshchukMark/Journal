#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <list>

#include "./Marks.h"

class Subject
{
private:
    int* idSubject;
    std::string* name;
    int* idTeacher;
    std::string* teacher;
    std::string* description;
public:



    int getIdSubject();
    std::string getName();
    std::string getTeacher();
    int getIdTeacher();
    std::string getDescription();

    void setIdSubject(int newIdSubject);
    void setName(std::string newName);
    void setTeacher(std::string newTeacher);
    void setIdTeacher(int newIdTeacher);
    void setDescription(std::string newDescription);

    void displayIdSubject();
    void displayName();
    void displayTeacher();
    void displayIdTeacher();
    void displayDescription();
    void displayInfo();

    void clearData();

    Subject(const Subject& other);


    Subject();
    Subject(int newidSubject, std::string newName, int newIdTeacher, std::string newTeacher, std::string newDescription);

    ~Subject();
};

#endif // SUBJECT_H
