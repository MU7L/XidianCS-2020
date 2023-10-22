#include "stdio.h"

/*
编写一个函数fun，求一个字符串中的英文字母的个数。
主函数中输入字符串，调用函数，输出英文字母个数

输入说明：共一行，输入字符串

输出说明：输出一个整数，为英文字母个数

输入示例：aBc456

输出示例：3
*/

int fun(char *p){
    int n=0;
    while(*p!='\0'){
        if((*p>='a' && *p<='z')||(*p>='A' && *p<='Z')){
            n++;
        }
        p++;
    }
    return n;
}

int main(void){
    char str[100]={0};
    gets(str);
    printf("%d",fun(str));
}