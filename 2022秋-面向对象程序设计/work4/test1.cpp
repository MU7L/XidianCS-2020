#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string no;
    string name;

public:
    void setPerson(string no, string name);
    void showPerson(string p);
};

void Person::setPerson(string no, string name)
{
    this->no = no;
    this->name = name;
}

void Person::showPerson(string p)
{
    cout << p << "'s no:\t" << no
         << "\n" << p << "'s name:\t" << name << endl;
}


class Student : public Person
{
private:
    string classNumber;
    int grade;
public:
    void setStudent(string no, string name, string classNumber, int grade);
    void showStudent();
};

void Student::setStudent(string no, string name, string classNumber, int grade)
{
    setPerson(no, name);
    this->classNumber = classNumber;
    this->grade = grade;
}

void Student::showStudent()
{
    showPerson("student");
    cout << "student's class number:\t" << classNumber
            << "\nstudent's grade:\t" << grade << endl;
}


class Teacher : public Person
{
private:
    string title;
    string department;
public:
    void setTeacher(string no, string name, string title, string department);
    void showTeacher();
};

void Teacher::setTeacher(string no, string name, string title, string department)
{
    setPerson(no, name);
    this->title = title;
    this->department = department;
}

void Teacher::showTeacher()
{
    showPerson("teacher");
    cout << "teacher's job title:\t" << title
            << "\nteacher's :\t" << department << endl;
}


int main()
{
    Student s;
    s.setStudent("001", "Student name", "Class1", 100);
    s.showStudent();
    cout << endl;
    Teacher t;
    t.setTeacher("002", "Teacher Name", "senior", "Computer Science");
    t.showTeacher();
    return 0;
}