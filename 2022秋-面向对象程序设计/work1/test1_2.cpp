#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void sort(int &a, int &b, int &c){
    if(a > b) {swap(a, b);}
    if(a > c) {swap(a, c);}
    if(b > c) {swap(b, c);}
}

int main(){
    int a = 11;
    int b = 45;
    int c = 14;
    cout << "a, b, c\n>>> " << a << ", " << b << ", " << c << endl;
    sort(a, b, c);
    cout << "sort(a, b, c)\n>>> " << a << ", " << b << ", " << c << endl;
    return 0;
}