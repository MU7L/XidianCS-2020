#include"stdio.h"
#include"string.h"

/*
标题	
密码强度

类别
字符串处理

时间限制	
1S

内存限制	
256Kb

问题描述	
每个人都有很多密码，你知道你的密码强度吗？假定密码由大写字母、小写字母、数字和非字母数字的符号这四类字符构成，密码强度计算规则如下：
1.	基础分：空密码(密码长度为零)0分，非空密码1分
2.	加分项1：密码长度超过8位，+1分
3.	加分项2：密码包含两类不同字符+1分，包含三类不同字符+2分，包含四类不同字符+3分
按照此规则计算的密码强度为0~5。请你设计一个程序计算给出的密码的强度。

输入说明	
输入为一个密码字符串，字符串长度不超过50个字符。

输出说明	
输出一个整数表示该密码的强度。

输入样例	
输入样例1
abcd
输入样例2
ab123

输出样例	
样例1输出：
1
样例2输出
2

*/

int main(void){
    char password[50]={0};
    gets(password);
    int score=0;
    int len=strlen(password);
    if(len>0){
        score++;//basic
        if(len>8){
            score++;//plus1
        }
        int v[4]={0};//v0-LETTER v1-letter v2-num v3-'
        int i=0;
        for(i=0;i<len;i++){
            if(password[i]>='A' && password[i]<='Z'){
                v[0]++;
            }
            else if(password[i]>='a' && password[i]<='z'){
                v[1]++;
            }
            else if(password[i]>='0' && password[i]<='9'){
                v[2]++;
            }
            else{
                v[3]++;
            }
        }
        for(i=0;i<4;i++){
            if(v[i]!=0){
                score++;//plus2
            }
        }
        printf("%d",score-1);
    }
    else if(len==0){
        printf("0");
    }
    
}