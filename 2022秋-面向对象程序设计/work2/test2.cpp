#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char name[18];
    int num;
    int mathScore;
    int englishScore;
    static int count;
    static int mathTotalScore;
    static int englishTotalScore;

public:
    Student(char nm[18], int nu, int math, int english);
    void showBase();
    static void showStatic();
};

int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;

Student::Student(char *nm, int nu, int math, int english)
{
    strcpy(name, nm);
    num = nu;
    mathScore = math;
    englishScore = english;
    count++;
    mathTotalScore += math;
    englishTotalScore += english;
}

void Student::showBase()
{
    cout << "name\t\t" << name << "\n"
         << "num\t\t" << num << "\n"
         << "math score\t" << mathScore << "\n"
         << "English score\t" << englishScore << "\n"
         << endl;
}

void Student::showStatic()
{
    cout << "count\t\t\t" << count << "\n"
         << "math total score\t" << mathTotalScore << "\n"
         << "English total score\t" << englishTotalScore << "\n"
         << endl;
}

int main()
{
    Student s1("student1", 1, 1, 2);
    Student s2("student2", 2, 3, 4);
    Student s3("student3", 3, 5, 6);
    s1.showBase();
    s2.showBase();
    s3.showBase();
    Student::showStatic();
    return 0;
}