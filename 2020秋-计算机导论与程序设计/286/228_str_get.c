#include "stdio.h"
#include "string.h"

/*
2.编写函数fun，其功能是将字符串s下标为奇数的字符删除，字符串中剩余字符形成的新字符串放在数组t中。
主函数中输入字符串s，调用函数，输出字符数组t。

输入说明：共一行，输入字符串s

输出说明：共一行，输出字符串t

输入示例：abcd1234

输出示例：ac13
*/

int main(void){
    char s[100]={0};
    gets(s);
    for(int i=0;i<strlen(s);i++){
        if(i%2==0){
            printf("%c",s[i]);
        }
    }
}