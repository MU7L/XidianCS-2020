#include <iostream>

using namespace std;

class People {
protected:
    int age;
    int height;
    int weight;
    static int num;
public:
    People(int a, int h, int w);
    void eating();
    void sporting();
    void sleeping();
    void show();
    static void showNum();
};

int People::num = 0;

People::People(int a, int h, int w): age(a), height(h), weight(w) {
    num++;
}

void People::eating() {
    weight++;
}

void People::sporting() {
    height++;
}

void People::sleeping() {
    age++;
    height++;
    weight++;
}

void People::show() {
    cout << "年龄:\t" << age << "岁\n"
         << "身高:\t" << height << "厘米\n"
         << "体重:\t" << weight << "斤" << endl;
}

void People::showNum() {
    cout << "数量:\t" << num << endl;
}

int main(){
    People p(20, 174, 160);
    p.eating();
    p.sporting();
    p.sleeping();
    p.show();
    p.showNum();
    return 0;
}