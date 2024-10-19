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
    double* general;
    int* idSubject;
public:

    void setIdGrades(int newIdGrades);
    void setIdSubject(int newIdSubject);

    int getIdGrades();
    int getIdSubject();
    std::vector<double> getHomeWorkGrades() const;
    std::vector<double> getTestGrades() const;
    std::vector<double> getSemesterGrades() const;

    void clearData();


    void addHomeWorkGrade(double newGrade);
    void addTestGrade(double newGrade);
    void addSemesterGrade(double newGrade);
    void calculateGeneralGrade();

    void displayIdGrades();
    void displayIdSubject();
    void displayHomeWorkGrades();
    void displayTestGrades();
    void displaySemesterGrades();
    void displayGeneralGrades();
    void displayAllGrades();

    void setGeneralGrade(double newGeneralMark);

    Grades(const Grades& other);
    Grades& operator=(const Grades& other);

    Grades(Grades&& other) noexcept
        : idGrades(other.idGrades), home_work(std::move(other.home_work)), test(std::move(other.test)), semester(std::move(other.semester)), general(other.general), idSubject(other.idSubject) {
        other.idGrades = nullptr;
        other.general = nullptr;
        other.idSubject = nullptr;
    }

    Grades();
    Grades(int newIdGrades, double newGeneral, int newIdSubject);

    ~Grades();
};

#endif // Grades_H