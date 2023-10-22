#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string number;
    int grade;
    Student(string initNumber, int initGrade);
    void show();
};

Student::Student(string initNumber, int initGrade) : number(initNumber), grade(initGrade) {}

void Student::show()
{
    cout << "number:\t" << number << "\tgrade:\t" << grade << endl;
}

Student *max(Student *s, int length)
{
    Student *maxGrade = new Student("00", 0);
    for (int i = 0; i < length; i++)
    {
        maxGrade = (s + i)->grade > maxGrade->grade ? (s + i) : maxGrade;
    }
    return maxGrade;
}

int main()
{
    Student s[5]{
        Student("01", 1),
        Student("02", 2),
        Student("03", 3),
        Student("04", 4),
        Student("05", 5)};
    Student *ps = &s[0];
    cout << "first:" << endl;
    ps->show();
    cout << "third:" << endl;
    (ps + 2)->show();
    cout << "fifth:" << endl;
    (ps + 4)->show();

    cout << "Who gets highest grade?:\t" << max(s, 5)->number << endl;

    return 0;
}