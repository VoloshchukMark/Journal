#ifndef MARKS_H
#define MARKS_H

#include <vector>8


class Marks
{
private:
    std::vector<double> home_work;
    std::vector<double> test;
    std::vector<double> semester;
    double* general;
public:

    void addHomeWorkMark(double newMark);
    void addTestMark(double newMark);
    void addSemesterMark(double newMark);
    void calculateGeneralMark();

    void displayHomeWorkMark();
    void displayTestMark();
    void displaySemesterMark();
    void displayGeneralMark();


    Marks();
    Marks(double newGeneral);

    ~Marks();
};

#endif // MARKS_H
