#include <iostream>
#include <cstring>

using namespace std;

class Stack{
public:
    int st[100];
    int top;
    Stack(){
        memset(st, 0, sizeof(st));
        top = 0;
    }
    void push(int i){
        st[top++] = i;
    }
    int pop(){
        return st[--top];
    }
    int topElem(){
        return st[top - 1];
    }
    bool isEmpty(){
        return top == 0;
    }
};

int main(int argc, char* argv[]){
    char str[100] = {0};
    cin >> str;
    char *p = str;
    Stack s;
    int a, b;
    while(*p != '\0'){
        if(*p >= '0' && *p <= '9'){
            s.push((int)(*p - '0'));
        }
        else{
            b = s.pop();
            a = s.pop();
            switch(*p){
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
        p++;
    }
    cout << s.pop() << endl;
    return 0;
}

/*

45+2*3-

15

*/