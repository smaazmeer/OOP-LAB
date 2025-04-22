#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"
#include <iostream>
using namespace std;

class LectureCourse : public Course
{
private:
    float examMarks;
    float assignmentMarks;

public:
    LectureCourse(string code, int cred, float exam, float assign)
        : Course(code, cred)
    {
        examMarks = exam;
        assignmentMarks = assign;
    }

    void calculateGrade()
    {
        float finalGrade = (0.7 * examMarks) + (0.3 * assignmentMarks);
        cout << "Final Grade (LectureCourse): " << finalGrade << endl;
    }

    void displayInfo()
    {
        cout << "Lecture Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }
};

#endif
