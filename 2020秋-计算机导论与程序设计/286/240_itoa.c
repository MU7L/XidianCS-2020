#include "stdio.h"
#include "stdlib.h"

/*
用递归法将一个整数n转换成字符串。

输入格式：输入一个整数

输出格式：输出一串字符串

输入样例一：123（整数）

输出样例一：123（字符串）

输入样例二：-456（整数）

输出样例二：-456（字符串）


*/

int main(void){
    int n;
    scanf("%d",&n);
    char s[16]={0};
    itoa(n,s,10);
    puts(s);
}