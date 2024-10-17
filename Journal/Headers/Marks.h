#ifndef MARKS_H
#define MARKS_H

#include <vector>


class Marks
{
private:
    int* idMarks;
    std::vector<double> home_work;
    std::vector<double> test;
    std::vector<double> semester;
    double* general;
    int* idSubject;
public:

    void setIdMarks(int newIdMarks);
    void setIdSubject(int newIdSubject);

    int getIdMarks();
    int getIdSubject();

    void clearData();

    void addHomeWorkMark(double newMark);
    void addTestMark(double newMark);
    void addSemesterMark(double newMark);
    void calculateGeneralMark();

    void displayIdMarks();
    void displayIdSubject();
    void displayHomeWorkMark();
    void displayTestMark();
    void displaySemesterMark();
    void displayGeneralMark();
    void displayAllMarks();

    void setGeneralMark(double newGeneralMark);

    Marks(const Marks& other);
    Marks& operator=(const Marks& other);

    Marks();
    Marks(int newIdMarks, double newGeneral, int newIdSubject);

    ~Marks();
};

#endif // MARKS_H
