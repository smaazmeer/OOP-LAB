#include <iostream>
using namespace std;

class Student{
    private:
        const int id;
        string name;
        int* examScores;

    public:
        Student(int id) : id(id)
        {
            examScores = new int[3]{0,0,0};
        }

        Student(int id, string name) : id(id),name(name)
        {
            examScores = new int[3]{0,0,0};
        }

        Student(Student &obj) : id(obj.id)
        {
            name = obj.name;
            examScores = new int[3];
            for (int i = 0; i < 3; i++)
            {
                examScores[i] = obj.examScores[i];
            }
            
        }

        ~Student(){delete[] examScores;}

        void displayDetails()
        {
            cout << "Name: " << name << endl;
            cout << "Exam Scores----" << endl;
            cout << "English Score: " << examScores[0] << endl;
            cout << "Math Score: " << examScores[1] << endl;
            cout << "Physics Score: " << examScores[2] << endl;
        }

        void setExamScores(int s1, int s2, int s3)
        {
            examScores[0] = s1;
            examScores[1] = s2;
            examScores[2] = s3;
        }
};

int main()
{
    Student s1(1001, "Aazmeer");
    s1.setExamScores(9,8,7);
    Student s2 = s1;

    s2.displayDetails();
    return 0;
}