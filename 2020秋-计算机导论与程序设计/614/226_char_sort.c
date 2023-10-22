#include "stdio.h"
#include "string.h"

/*
从键盘输入一个字符串，将此字符串按字符的ASCII码值从小到大排序，并显示排序后的字符串。

输入说明：共一行，输入一个字符串

输出说明：共一行，输出排序后的字符串

输入样例：Fdjn4e5

输出样例：45Fdejn
*/

int main(void){
    char str[100];
    gets(str);
    for(int i=0;i<strlen(str);i++){
        for(int j=i+1;j<strlen(str);j++){
            if(str[i]>str[j]){
                char temp=str[i];str[i]=str[j];str[j]=temp;
            }
        }
    }
    puts(str);
}