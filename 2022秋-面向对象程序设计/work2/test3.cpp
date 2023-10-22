#include <iostream>
#include <cstring>

using namespace std;

class Dog
{
private:
    char *name;
    int age;
    char *sex;
    int weight;

public:
    Dog();
    void setName(char *name);
    void setAge(int age);
    void setSex(char *sex);
    void setWeight(int weight);
    char *getName();
    int getAge();
    char *getSex();
    int getWeight();
};

Dog::Dog()
{
    name = new char[8]{"dafault"};
    age = 0;
    sex = new char[7]{"male"};
    weight = 0;
}

void Dog::setName(char *name) { strcpy(this->name, name); }

void Dog::setAge(int age) { this->age = age; }

void Dog::setSex(char *sex) { strcpy(this->sex, sex); }

void Dog::setWeight(int weight) { this->weight = weight; }

char *Dog::getName() { return name; }

int Dog::getAge() { return age; }

char *Dog::getSex() { return sex; }

int Dog::getWeight() { return weight; }

int main()
{
    Dog *dog = new Dog();
    dog->setName("dog");
    dog->setAge(1);
    dog->setSex("female");
    dog->setWeight(2);
    cout << "getName():\t" << dog->getName() << "\n"
         << "getAge():\t" << dog->getAge() << "\n"
         << "getSex():\t" << dog->getSex() << "\n"
         << "getWeight():\t" << dog->getWeight() << endl;
    return 0;
}