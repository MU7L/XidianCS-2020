#include "stdio.h"
#include "stdlib.h"

/*
标题	
字符串压缩

类别
字符串处理
	
时间限制	
1S

内存限制	
1000Kb

问题描述	
有一种简单的字符串压缩算法，对于字符串中连续出现的同一个英文字符，用该字符加上连续出现的次数来表示（连续出现次数小于3时不压缩）。
例如，字符串aaaaabbbabaaaaaaaaaaaaabbbb可压缩为a5b3aba13b4。
请设计一个程序，将采用该压缩方法得到的字符串解压缩，还原出原字符串并输出。

输入说明	
输入数据为一个字符串（长度不大于50，只包含字母和数字），表示压缩后的字符串

输出说明	
在一行上输出解压缩后的英文字符串（长度不超过100），最后换行。

输入样例	
a5b3aba13b4

输出样例	
aaaaabbbabaaaaaaaaaaaaabbbb
*/

int main(void){
    char zip[50]={0};
    gets(zip);
    char *p=zip;
    while(*p!='\0'){
        char t[50]={0};//重复次数
        int i=0;//t的指针
        if(*(p+1)>='0' && *(p+1)<='9'){//重复输出
            char ltr=*p;//重复字母
            do{
                t[i++]=*(++p);
            }while(*(p+1)>='0' && *(p+1)<='9');
            for(i=0;i<atoi(t);i++){
                printf("%c",ltr);
            }
        }
        else{//单个输出
            printf("%c",*p);
        }
        p++;
    }
}