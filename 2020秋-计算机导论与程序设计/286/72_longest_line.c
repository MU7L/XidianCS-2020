#include "stdio.h"
#include "string.h"

/*
标题	
寻找最长的行

类别
字符串
	
时间限制	
1S

内存限制	
1000Kb

问题描述	
寻找若干行文本中最长的一行

输入说明	
输入为多个字符串(每个字符串长度不超过100个字符)，每个字符串占一行，输入的行为“***end***”时表示输入结束

输出说明	
输出其中最长的一行长度后换行再输出最长行的内容，如果最长行不止一个，则输出其中的第一行。

输入样例	
abce
abdf dlfd
***end***

输出样例	
9
abdf dlfd 
*/

int main(void){
    char txt[100]={0},str_max[100]={0};
    int len_max=0;
    while(1){
        gets(txt);
        if(strcmp(txt,"***end***")!=0){
            if(strlen(txt)>len_max){
                len_max=strlen(txt);
                strcpy(str_max,txt);
            }
        }
        else{
            break;
        }
    }
    printf("%d\n%s",len_max,str_max);
}