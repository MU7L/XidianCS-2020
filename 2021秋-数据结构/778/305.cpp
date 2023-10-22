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
    void pop(){
        top--;
    }
    int topElem(){
        return st[top - 1];
    }
    bool isEmpty(){
        return top == 0;
    }
};

int main(int argc, char* argv[]){
    int n = 0;
    int out[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> out[i];
    }
    int in = 1;
    int p = 0;
    Stack s;
    bool res = true;
    while(p < n){
        if(out[p] == in){
            p++;
            in++;
        }
        else if(out[p] == s.topElem()){
            p++;
            s.pop();
        }
        else{
            s.push(in++);
            if(in > n){
                res = false;
                break;
            }
        }
    }
    if(res){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}

/*

6
3 4 2 1 5 6

yes

*/