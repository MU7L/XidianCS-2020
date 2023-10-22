#include "stdio.h"
#include "string.h"

/*
标题
字符删除

描述
主函数中输入一个一维字符数组str[N]（N≤50）和待删除字符ch，调用函数dele()完成内容：1、删除字符数组中的每个待删除字符；2、其它字符依次迁移；3、数组末尾加'\0'结束。
   
时间限制
1	

内存限制
10000	

类别
1

输入说明
输入一个一维字符数组和待删除字符。

输出说明
格式输出：输出处理后字符串。

输入样例
There are three men.
e
输出样例
Thr ar thr mn.

提示
字符串输入函数gets()，头文件string.h。

*/

void dele(char ch,char *p){
    /*删除一个字符，将后面的字符前移 一次操作*/
    while(*(p++)!=ch);//当找到删除对象时，指针指向？
    for(;*p!='\0';p++){
        *(p-1)=*p;
    }
    *(p-1)=*p;
}

int main(void){
    char str[50]={0};
    gets(str);
    char ch=getchar();
    int chs=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]==ch){
            chs++;
        }
    }
    for(int i=0;i<chs;i++){
        dele(ch,str);
    }
    puts(str);
}