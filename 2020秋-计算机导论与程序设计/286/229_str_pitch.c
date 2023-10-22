#include "stdio.h"
#include "string.h"

/*
编写一个函数fun实现字符串连接功能（不使用strcat函数）。
主函数输入两个字符串，调用函数，输出连接后的字符串

输入说明：共两行，每一行输入一个字符串

输出说明：共一行,输出连接后的字符串

输入示例：abcd
          1234

输出示例：abcd1234
*/

int main(void){
    char s1[100]={0},s2[100]={0};
    gets(s1);
    gets(s2);
    strcat(s1,s2);
    puts(s1);
}