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
public:

    void setIdMarks(int newIdMarks);

    int getIdMarks();

    void clearData();

    void addHomeWorkMark(double newMark);
    void addTestMark(double newMark);
    void addSemesterMark(double newMark);
    void calculateGeneralMark();

    void displayHomeWorkMark();
    void displayTestMark();
    void displaySemesterMark();
    void displayGeneralMark();

    Marks(const Marks& other);
    Marks& operator=(const Marks& other);

    Marks();
    Marks(int newIdMarks, double newGeneral);

    ~Marks();
};

#endif // MARKS_H
