#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
    int counter;
    string name;
    string surname;
    string patronymic;
    string age;
    string sex;
    vector<double> marks;
    string address;
public:

    Student();
};

#endif // STUDENT_H
