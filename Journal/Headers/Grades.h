#ifndef Grades_H
#define Grades_H

#include <vector>


class Grades
{
private:
    int* idGrades;
    std::vector<double> home_work;
    std::vector<double> test;
    std::vector<double> semester;
    int* idSubject;
public:

    void setIdGrades(int newIdGrades);
    void setIdSubject(int newIdSubject);

    int getId();
    int getIdSubject();
    std::vector<double> getHomeWorkGrades() const;
    std::vector<double> getTestGrades() const;
    std::vector<double> getSemesterGrades() const;


//    void editTestGrades(std::vector<double> insertedGrades, int coordinate);
//    void editSemesterGrades(std::vector<double> insertedGrades, int coordinate);

    void clearData();


    void addHomeWorkGrade(double newGrade);
    void addTestGrade(double newGrade);
    void addSemesterGrade(double newGrade);

    void setGrades(char type, std::vector<double> newHomeWorkGrades);

    void displayIdGrades();
    void displayIdSubject();
    void displayHomeWorkGrades();
    void displayTestGrades();
    void displaySemesterGrades();    void displayInfo();


    Grades(const Grades& other);
    Grades& operator=(const Grades& other);

    // Конструктор переміщення
    Grades(Grades&& other) noexcept;

    // Оператор присвоєння переміщення
    Grades& operator=(Grades&& other) noexcept;

//    Grades(Grades&& other) noexcept;
//        : idGrades(other.idGrades), home_work(std::move(other.home_work)), test(std::move(other.test)), semester(std::move(other.semester)), general(other.general), idSubject(other.idSubject) {
//        other.idGrades = nullptr;
//        other.general = nullptr;
//        other.idSubject = nullptr;
//    }

    Grades();
    Grades(int newIdGrades, int newIdSubject);
    Grades(int newIdGrades, int newIdSubject, std::vector<double> newHomeworkGrades, std::vector<double> newTestGrades, std::vector<double> newSemesterGrades);

    ~Grades();
};

#endif // Grades_H
