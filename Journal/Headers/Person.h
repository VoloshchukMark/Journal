#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    int id;
    std::string name;
    std::string surname;
    std::string patronymic;
    int age;
    std::string sex;
public:
    virtual int getId();
    virtual std::string getName();
    virtual std::string getSurname();
    virtual std::string getPatronymic();
    virtual int getAge();
    virtual std::string getSex();

    virtual void setId(int newId);
    virtual void setName(std::string newName);
    virtual void setSurname(std::string newSurname);
    virtual void setPatronymic(std::string newPatronymic);
    virtual void setAge(int newAge);
    virtual void setSex(std::string newSex);

    virtual void displayId();
    virtual void displayName();
    virtual void isplaySurname();
    virtual void displayPatronymic();
    virtual void displayAge();
    virtual void displaySex();

    Person();
    Person(int newId);
    Person(int newId, std::string newName);
    Person(int newId, std::string newName, std::string newSurname);
    Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic);
    Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge);
    Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex);

    virtual ~Person() {}
};

#endif // PERSON_H
