#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

/***************************************************************************
 * 给出一个命题公式，列出其真值表
 * 测试样例 !A
 ***************************************************************************/

//非
bool fei(bool p){
    return !p;
}

//条件
bool tiaojian(bool p,bool q){
    if(p && !q){
        return false;
    }
    else{
        return true;
    }
}

//双条件
bool shuangtiaojian(bool p,bool q){
    if(tiaojian(p,q) && tiaojian(q,p)){
        return true;
    }
    else{
        return false;
    }
}

//析取
bool xiqu(bool p,bool q){
    return p||q;
}

//合取
bool hequ(bool p,bool q){
    return p&&q;
}

//简化运算表达式 非:7 合取:6 析取:5 条件:4 双条件:3 左括号:2 右括号:1 优先级越高数字越大
string simplify(string resource){
    string output="";
    for(int i=0;i<resource.length();i++){
        switch(resource.at(i)){
            case '!': resource[i]='7';break;
            case '+': resource[i]='6';break;
            case '*': resource[i]='5';break;
            case '-': resource[i]='4';break;
            case '=': resource[i]='3';break;
            case '(': resource[i]='2';break;
            case ')': resource[i]='1';break;
            default: continue;
        }
    }
    return resource;
}

//栈类
class Stack{
public:
    char s[10];
    int top; //栈顶(空)

    Stack(){
        s[10]={0};
        top=0;
    }
    void push(char p){ //入栈
        s[top]=p;
        top++;
    }
    char pop(){ //出栈
        top--;
        char res=s[top];
        s[top]='\0';
        return res;
    }
    string out(){
        return s;
    }
};

//中缀表达式转换为后缀表达式
string converse(string resource){
    Stack output;
    Stack stack;
    for(int i=0;i<resource.length();i++){
        char p=resource.at(i);
        if(p>='A' && p<='Z'){ //变元直接输出
            output.push(p);
        }
        else if(p=='1'){ //读取到右括号(1) 将栈元素弹出，将弹出的操作符输出直到遇到左括号为止
            while(stack.s[stack.top-1]!='2'){
                output.push(stack.pop());
            }
        }
        else{ //读取到其他可入栈操作
            if(stack.top==0){ //暂存栈为空 直接入栈
                stack.push(p);
            }
            else{
                if(p>stack.s[stack.top-1]){ //读取到优先级比stack.top高，直接压入栈
                    stack.push(p);
                }
                else{ //读取到优先级比stack.top低，弹出并输出栈顶，直到读取到的优先级高，再将读取压入栈
                    while(p<=stack.s[stack.top-1]){
                        output.push(stack.pop());
                    }
                    stack.push(p);
                }
            }
        }
    }
    while(stack.top!=0){ //stack剩余元素弹出
        output.push(stack.pop());
    }
    return output.out();
}

//bool栈 类
class BoolStack{
public:
    bool s[10];
    int top; //栈顶(空)

    BoolStack(){
        s[10]={false};
        top=0;
    }
    void push(bool p){ //入栈
        s[top]=p;
        top++;
    }
    bool pop(){ //出栈
        top--;
        bool res=s[top];
        s[top]='\0';
        return res;
    }
};

//计算 传入运算表达式(只含有'3'到'7'和'T''F')
bool calculate(string str){
    BoolStack stack;
    for(int i=0;i<str.length();i++){
        if(str.at(i)=='T'){ //变元
            stack.push(true);
        }
        else if(str.at(i)=='F'){ //变元
            stack.push(false);
        }
        else{ //联结词 非:7 合取:6 析取:5 条件:4 双条件:3
            switch(str.at(i)){
                case '3': { //双条件
                    stack.push(shuangtiaojian(stack.pop(),stack.pop()));
                    break;
                }
                case '4': { //条件
                    stack.push(tiaojian(stack.pop(),stack.pop()));
                    break;
                }
                case '5': { //析取
                    stack.push(xiqu(stack.pop(),stack.pop()));
                    break;
                }
                case '6': { //合取
                    stack.push(hequ(stack.pop(),stack.pop()));
                    break;
                }
                case '7': { //非
                    stack.push(fei(stack.pop()));
                    break;
                }
            }
        }
    }
    return stack.pop();
}

//整数转二进制
void numToBin(int value,int* value_,int n){
    for(int i=0;i<n;i++){
        value_[i]=0;
    }
    while(value>0 && n>=0){
        value_[n-1]=value%2;
        value/=2;
        n--;
    }
}

//变元 类
class Element{
public:
    char name;
    char value;

    void setValue(int v){
        if(v==1){
            value='T';
        }
        else{
            value='F';
        }
    }
    int getValue(){
        if(value=='T'){
            return 1;
        }
        else{
            return 0;
        }
    }
};

//标准输出1
char outValue(bool flag){
    if(flag){
        return 'T';
    }
    else{
        return 'F';
    }
}

//标准输出2
char outValue(int flag){
    if(flag==1){
        return 'T';
    }
    else{
        return 'F';
    }
}

int main(void){
    //输入
    string test;
    cin >> test;

    //化简
    string conversed=converse(simplify(test));

    //统计变元 排序
    Element elem[10];
    int elem_n=0; //变元个数
    for(int i=0;i<conversed.length();i++){
        if(conversed[i]>='A' && conversed[i]<='Z'){
            elem[elem_n].name=conversed[i];
            elem_n++;
        }
    }
    char temp; //交换介值
    for(int i=0;i<elem_n;i++){
        for(int j=i+1;j<elem_n;j++){
            if(elem[i].name>elem[j].name){
                temp=elem[i].name;
                elem[i].name=elem[j].name;
                elem[j].name=temp;
            }
        }
    }
    //打印抬头
    for(int i=0;i<elem_n;i++){
        cout << elem[i].name << " ";
    }
    cout << test << endl;

    //赋值计算 输出
    bool res; //结果
    //遍历所有赋值
    int value=0; //将所赋值看作二进制数，对应十进制数value_
    int value_[10]={0}; //二进制数组
    while(value<pow(2,elem_n)){
        //以二进制方式赋值
        numToBin(value,value_,elem_n);
        for(int i=0;i<elem_n;i++){
            elem[i].setValue(value_[i]);
        }
        string test2=conversed;
        for(int i=0;i<test2.length();i++){
            if(test2[i]>='A' && test2[i]<='Z'){
                for(int j=0;j<elem_n;j++){
                    if(test2[i]==elem[j].name){ //找到对应变元
                        test2[i]=elem[j].value; //替换为对应的真值
                    }
                }
            }
        }
        //计算
        res=calculate(test2);
        //输出 转换位int[]
        for(int i=0;i<elem_n;i++){
            cout << outValue(elem[i].getValue()) << ' ' ;
        }
        cout << outValue(res) << endl;
        value++;
    }
}