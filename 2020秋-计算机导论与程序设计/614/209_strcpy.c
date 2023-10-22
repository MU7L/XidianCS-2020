#include "stdio.h"
#include "string.h"

/*
标题
字符拷贝

描述
定义一个一维字符数组str[50]，输入一串字符，输入整数位置信息M(M<50)，调用函数char_cp()把指定位置M之后的内容，拷贝到新字符数组ch[50]中，使用指针完成地址传递，主函数完成数组输入和输出。
   
时间限制
1	

内存限制
10000	

类别
1

输入说明
输入一个字符串和整形位置信息，位置M≥0。

输出说明
格式输出：输出处理后字符串ch。

输入样例
There are three men.
6

输出样例
re three men.

提示
使用指针作形参，实现地址传递，位置从0开始。

*/

int main(void){
    char str[50]={0};
    gets(str);
    int m;
    scanf("%d",&m);
    for(int i=m+1;i<strlen(str);i++){
        printf("%c",str[i]);
    }
}