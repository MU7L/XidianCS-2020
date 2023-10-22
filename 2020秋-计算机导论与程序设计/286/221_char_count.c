#include "stdio.h"

/*
题目：字符串元素统计
时间限制：1S
内存限制：10000Kb
问题描述：

编写一个函数，由实参传来一个字符串，统计字符串中字母，数字的个数，在主函数中输入字符及输出上述结果。
输入说明：
随机输入一个字符串。
输出说明：
依次输出该字符串中字母，数字的个数。
输入样例
abc123
输出样例：
3,3
*/

void count(char *p,int *ltr,int *num){
    while(*p!='\0'){
        if(*p>='0' && *p<='9'){
            (*num)++;
        }
        else if((*p>='a' && *p<='z')||(*p>='A' && *p<='Z')){
            (*ltr)++;
        }
        p++;
    }
}

int main(void){
    char str[100]={0};
    gets(str);
    int ltr=0,num=0;
    count(str,&ltr,&num);
    printf("%d,%d",ltr,num);
}