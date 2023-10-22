#include "stdio.h"
#include "string.h"

/*
标题
单词排序

描述
定义一个二维字符数组str[10][20]，行号表示单词序号，列号表示单词最大长度，输入一个正整数N（N≤10），表示单词数，使用函数wd_sort()完成单词的排序，按字母顺序从小到大排列单词，使用指针完成地址传递，主函数完成数组输入和输出。

时间限制
1	

内存限制
10000	

类别
1

输入说明
输入一个二维字符数组str和一个正整数N，行号表示单词序号，列号表示单词最大长度。

输出说明
格式输出：单词之间空一行。

输入样例
3
word fish egg
输出样例
egg
fish
word

提示
使用指针作形参，实现地址传递。
数组定义后初始化。
使用strcmp()、strcpy()和strlen()函数，头文件string.h。
*/



int main(void){
    int n;
    scanf("%d",&n);
    char str[10][20]={0};
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(str[i],str[j])>0){
                char temp[20]={0};
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%s\n",str[i]);
    }
}