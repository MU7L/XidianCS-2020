#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

/***************************************************************************
 * 给出任意变元（不超过4个变元，如：P,Q,S,R）的合式公式。构造该合式公式的真值表。
 * 测试样例 ~P\/Q/\R
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
char * simplify(char *str){
    char *test; //记录初始指针
    test=str;
    //删减
    while(*str){
        char *p; //辅助删除指针
        if(*str=='/' || *str=='\\' || *str=='-'){ //析取 合取 条件占两个字节
            p=str+1;
            while(*(p+1)){
                *p=*(p+1);
                p++;
            }
            *p='\0';
        }
        else if(*str=='<'){ //双条件占三个字节
            p=str+1;
            while(*(p+2)){
                *p=*(p+2);
                p++;
            }
            *p='\0';
            *(p+1)='\0';
        }
        str++;
    }
    //替换
    str=test; //指针复位
    while(*str){
        switch(*str){
            case '~': *str='7';break;
            case '/': *str='6';break;
            case '\\': *str='5';break;
            case '-': *str='4';break;
            case '<': *str='3';break;
            case '(': *str='2';break;
            case ')': *str='1';break;
        }
        str++;
    }
    return test;
}

//栈类
class Stack{
public:
    char *s;
    int top=0; //栈顶(空)

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
    void finish(){ //末尾加上结束符
        s[top]='\0';
    }
};

//中缀表达式转换为后缀表达式
char * converse(char *p){
    Stack output;
    Stack stack;
    while(*p){
        if(*p>='A' && *p<='Z'){ //变元直接输出
            output.push(*p);
        }
        else if(*p=='1'){ //读取到右括号(1) 将栈元素弹出，将弹出的操作符输出直到遇到左括号为止
            while(stack.s[stack.top-1]!='2'){
                output.push(stack.pop());
            }
        }
        else{ //读取到其他可入栈操作
            if(stack.top==0){ //暂存栈为空 直接入栈
                stack.push(*p);
            }
            else{
                if(*p>stack.s[stack.top-1]){ //读取到优先级比stack.top高，直接压入栈
                    stack.push(*p);
                }
                else{ //读取到优先级比stack.top低，弹出并输出栈顶，直到读取到的优先级高，再将读取压入栈
                    while(*p<=stack.s[stack.top-1]){
                        output.push(stack.pop());
                    }
                    stack.push(*p);
                }
            }
        }
        p++;
    }
    while(stack.top!=0){ //stack剩余元素弹出
        output.push(stack.pop());
    }
    output.finish();
    return output.s;
}

//bool栈 类
class BoolStack{
public:
    bool *s;
    int top=0; //栈顶(空)

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
bool calculate(const char *str){
    BoolStack stack;
    while(*str){
        if(*str=='T'){ //变元
            stack.push(true);
        }
        else if(*str=='F'){ //变元
            stack.push(false);
        }
        else{ //联结词 非:7 合取:6 析取:5 条件:4 双条件:3
            switch(*str){
                case '3': { //双条件                                               TODO
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
        str++;
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

int main(void){
    //输入
    char test[10]={0};
    cin >> test;
    char final_output[10]={0}; //存储初始值
    strcpy(final_output,test);

    //简化 转换
    char *test2;
    test2=converse(simplify(test)); //有终止符

    //统计变元 排序
    Element elem[10];
    int elem_n=0; //变元个数
    for(int i=0;i<strlen(test2);i++){
        if(test2[i]>='A' && test2[i]<='Z'){
            elem[elem_n].name=test2[i];
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
    cout << final_output << endl;

    //赋值计算 输出
    bool res; //结果
    //遍历所有赋值
    char test3[10]={0};
    int value=0; //将所赋值看作二进制数，对应十进制数value_
    int value_[10]={0}; //二进制数
    char *p; //指向test3
    while(value<pow(2,elem_n)){
        //以二进制方式赋值
        numToBin(value,value_,elem_n);
        for(int i=0;i<elem_n;i++){
            elem[i].setValue(value_[i]);
        }
        strcpy(test3,test2); //保护原数据,赋值给test3
        p=test3;
        while(*p){
            if(*p>='A' && *p<='Z'){
                for(int j=0;j<elem_n;j++){
                    if(*p==elem[j].name){ //找到对应变元
                        *p=elem[j].value; //替换为对应的真值
                    }
                }
            }
            p++;
        }
        //计算
        res=calculate(test3);
        //输出 转换位int[]
        for(int i=0;i<elem_n;i++){
            cout << elem[i].getValue() << ' ' ;
        }
        cout << res << endl;
        value++;
    }
}