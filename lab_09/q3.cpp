#include "LectureCourse.h"
#include "LabCourse.h"

int main()
{
    LectureCourse c1("MT1010", 3, 89, 10);
    LabCourse c2("CS1002", 1, 92, 88);

    Course* base;

    base = &c1;
    
    base->displayInfo();
    base->calculateGrade();
    
    base = &c2;
    
    base->displayInfo();
    base->calculateGrade();

    return 0;
}
