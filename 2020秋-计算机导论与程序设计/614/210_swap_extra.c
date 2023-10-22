#include "stdio.h"

/*
标题
最值交换

描述
定义一个一维整形数组num[20]，输入整数n(n≤20)和一个整形数列 (n个数)，编写change()函数，查找出数列中的最大值和最小值，并把它们交换位置，主函数完成输入和输出，主函数输出处理后的数列，各元素之间空一个空格。指针进行地址传递，子函数实现查找最值和最值位置交换。
   
时间限制
1	

内存限制
10000	

类别
1

输入说明
输入整数n (n≤20)和一个整形数列 (n个数)。

输出说明
格式输出：输出处理后数列。

输入样例
5
2 3 1 5 8

输出样例
2 3 1 8 5

提示
使用指针作形参，实现地址传递。仅对最值进行交换。输出数据之间空一格。
*/

int main(void){
    int n;
    scanf("%d",&n);
    int num[20]={0};
    int maxid=0,minid=0;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(num[maxid]<num[i]){
            maxid=i;
        }
        if(num[minid]>num[i]){
            minid=i;
        }
    }
    int temp=num[maxid];num[maxid]=num[minid];num[minid]=temp;
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
}