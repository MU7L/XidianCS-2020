#include <iostream>
#include <string>

using namespace std;

//
class Teacher
{
protected:
    string name;
    int age;
    string gender;
    string addr;
    string tele;
    string title;

public:
    Teacher(string q, int w, string e, string r, string t, string y);
    void display();
};

Teacher::Teacher(string q, int w, string e, string r, string t, string y) : name(q), age(w), gender(e), addr(r), tele(t), title(y) {}

void Teacher::display()
{
    cout << "name: \t" << name
         << "\nage: \t" << age
         << "\ngender:\t" << gender
         << "\ntitle:\t" << title
         << "\naddress:\t" << addr
         << "\ntelephone:\t" << tele << endl;
}

//
class Cadre
{
protected:
    string name;
    int age;
    string gender;
    string addr;
    string tele;
    string post;

public:
    Cadre(string q, int w, string e, string r, string t, string y);
};

Cadre::Cadre(string q, int w, string e, string r, string t, string y) :
    name(q), age(w), gender(e), addr(r), tele(t), post(y)
    {}

//
class Teacher_Cadre : public Teacher, public Cadre
{
private:
    int wages;

public:
    Teacher_Cadre(string name, int age, string gender, string addr, string tele, string title, string post, int wages);
    void show();
};

Teacher_Cadre::Teacher_Cadre(string name, int age, string gender, string addr, string tele, string title, string post, int wages) :
    Teacher(name, age, gender, addr, tele, title),
    Cadre(name, age, gender, addr, tele, post),
    wages(wages)
    {}

void Teacher_Cadre::show()
{
    Teacher::display();
    cout << "post:\t" << post
         << "\nwages:\t" << wages << endl;
}

//
int main()
{
    Teacher_Cadre a("Name", 1, "male", "Addr", "10086", "Title", "Post", 100);
    a.show();
    return 0;
}