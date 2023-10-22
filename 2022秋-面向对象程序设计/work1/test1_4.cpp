#include <iostream>

using namespace std;

template <typename T>
void sort(T &a, T &b, T &c){
    T tmp;
    if(a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if(a > c) {
        tmp = a;
        a = c;
        c = tmp;
    }
    if(b > c) {
        tmp = b;
        b = c;
        c = tmp;
    }
}

int main(){
    int a1 = 11;
    int b1 = 45;
    int c1 = 14;
    cout << "a1, b1, c1\n>>> " << a1 << ", " << b1 << ", " << c1 << endl;
    sort(a1, b1, c1);
    cout << "sort(a1, b1, c1)\n>>> " << a1 << ", " << b1 << ", " << c1 << endl;

    double a2 = 1.1;
    double b2 = 4.5;
    double c2 = 1.4;
    cout << "a2, b2, c2\n>>> " << a2 << ", " << b2 << ", " << c2 << endl;
    sort(a2, b2, c2);
    cout << "sort(a2, b2, c2)\n>>> " << a2 << ", " << b2 << ", " << c2 << endl;
    return 0;
}