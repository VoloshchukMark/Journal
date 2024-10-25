#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    int* id;
    std::string* name;
    std::string* surname;
    std::string* patronymic;
    int* age;
    std::string* sex;
    std::string* address;
public:
    virtual int getId() const;
    virtual std::string getName() const;
    virtual std::string getSurname();
    virtual std::string getPatronymic();
    virtual int getAge();
    virtual std::string getSex();
    virtual std::string getAddress();

    virtual void setId(int& newId);
    virtual void setName(std::string& newName);
    virtual void setSurname(std::string& newSurname);
    virtual void setPatronymic(std::string& newPatronymic);
    virtual void setAge(int newAge);
    virtual void setSex(std::string& newSex);
    virtual void setAddress(std::string& newAddress);
    virtual void updateInfo(int newId, std::string newName,std::string newSurname, std::string newPatromymic, int newAge, std::string newSex, std::string newAddress);

    virtual void displayId();
    virtual void displayName();
    virtual void displaySurname();
    virtual void displayPatronymic();
    virtual void displayAge();
    virtual void displaySex();
    virtual void displayAddress();
    virtual void displayInfo() = 0;

    Person(const Person& other);
    Person& operator=(const Person& other) {
        if (this == &other) return *this;
        *id = *other.id;
        *name = *other.name;
        *surname = *other.surname;
        *patronymic = *other.patronymic;
        *age = *other.age;
        *sex = *other.sex;
        *address = *other.address;
        return *this;
    }
    Person(Person&& other) noexcept;
    Person& operator=(Person&& other) noexcept {
        if (this != &other) {
            delete id;
            delete name;
            delete surname;
            delete patronymic;
            delete age;
            delete sex;
            delete address;

            id = other.id;
            name = other.name;
            surname = other.surname;
            patronymic = other.patronymic;
            age = other.age;
            sex = other.sex;
            address = other.address;

            other.id = nullptr;
            other.name = nullptr;
            other.surname = nullptr;
            other.patronymic = nullptr;
            other.age = nullptr;
            other.sex = nullptr;
            other.address = nullptr;
        }
        return *this;
    }

    Person();
    Person(int newId, std::string newName, std::string newSurname, std::string newPatronymic, int newAge, std::string newSex, std::string newAddress);

    virtual ~Person();
};

#endif // PERSON_H
