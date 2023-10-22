#include <iostream>
#include <string>

using namespace std;

//单项式
class Term{
public:
    int coef; //系数
    int expn; //指数
    Term *next;

    Term(){
        coef = 0;
        expn = 0;
        next = NULL;
    }

    Term(int inCoef, int inExpn){
        coef = inCoef;
        expn = inExpn;
    }

    string toString(){
        if(coef == 0){
            return "";
        }
        else{
            string coefStr;
            string xStr = "x^";
            string expnStr;
            if(coef == 1){
                coefStr = "";
            }
            else if(coef == -1){
                coefStr = "-";
            }
            else{
                coefStr = to_string(coef);
            }
            if(expn == 0){
                coefStr = to_string(coef);
                xStr = "";
                expnStr = "";
            }
            else if(expn == 1){
                xStr = "x";
                expnStr = "";
            }
            else{
                expnStr = to_string(expn);
            }
            return coefStr + xStr + expnStr;
        }
    }
};

//多项式
class Polynomial{
public:
    Term *handle; //句柄
    Term *end;    //式尾

    Polynomial(){
        handle = new Term();
        end = handle;
    };

    //加单项式
    void addTerm(Term *t){
        end -> next = t;
        end = end -> next;
    }

    //与多项式p进行t运算
    void withPoly(Polynomial *p, int op){
        Term *p1 = handle -> next;      //原式第1项
        Term *p2 = p -> handle -> next; //p式第1项
        while(p1 != end -> next && p2 != end -> next){
            if(p1 -> expn > p2 -> expn){
                p2 = p2 -> next;
            }
            else if(p1 -> expn < p2 -> expn){
                p1 = p1 -> next;
            }
            else{
                switch(op){
                    case 0: p1 -> coef += p2 -> coef; break; //结果合并到原式
                    case 1: p1 -> coef -= p2 -> coef; break;
                    default: break;
                }
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
        }
        //当p式有剩余时接入原式
        while(p2 != end -> next){
            addTerm(p2);
            p2 = p2 -> next;
        }
    }

    //打印
    void print(){
        Term *p = handle -> next;
        cout << p -> toString(); //第一个单独处理
        while(p != end){
            p = p -> next;
            if(p -> coef > 0){
                cout << "+"; //正系数补+
            }
            cout << p -> toString();
        }

    }
};

int main(int argc, char* argv[]){
    int n, m, t;
    cin >> n >> m >> t;
    int coef, expn;
    Polynomial a;
    for(int i = 0; i < n; i++){
        cin >> coef >> expn;
        a.addTerm(new Term(coef, expn));
    }
    Polynomial b;
    for(int i = 0; i < m; i++){
        cin >> coef >> expn;
        b.addTerm(new Term(coef, expn));
    }
    a.withPoly(&b, t);
    a.print();
    return 0;
}

/*
6 3 0
1 0 1 1 -3 2 1 3 1 4 1 5
-1 3 -2 4 1 5

1 0 1 1 -3 2 0 3 -1 4 2 5

6 3 1
1 0 1 1 -3 2 1 3 1 4 1 5
-1 3 -2 4 1 5

1 0 1 1 -3 2 2 3 3 4 0 5

7 4 0
1 0 1 1 -3 2 1 3 1 4 1 5 1 6
-1 3 -2 4 1 5 1 7
*/