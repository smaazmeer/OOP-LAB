#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>
using namespace std;

class LabCourse : public Course
{
private:
    float labWorkMarks;
    float projectMarks;

public:
    LabCourse(string code, int creds, float labWork, float project)
        : Course(code, creds)
    {
        labWorkMarks = labWork;
        projectMarks = project;
    }

    void calculateGrade()
    {
        float finalGrade = (0.6 * labWorkMarks) + (0.4 * projectMarks);
        cout << "Final Grade (LabCourse): " << finalGrade << endl;
    }

    void displayInfo()
    {
        cout << "Lab Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }
};

#endif
