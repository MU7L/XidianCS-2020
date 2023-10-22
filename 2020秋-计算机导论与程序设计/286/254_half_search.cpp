#include "stdio.h"

/*
试题名称 1-3 二分查找
问题描述：
请写程序，用二分法（折半法，取下整）查找指定元素。
输入说明：
输入数据的第一行有两个正整数 n（n≤100）和 key，分别表示序列长度（即序列中整数的个
数）和待查找的元素，从第二行开始，接下来的 n 个整数构成一个非递减有序的序列。整数
之间以空格或换行符间隔。
输出说明：
输出分两行。在第一行上输出查找过程中参与比较的各整数，用 1 个空格分隔；若查找成功，
则在第二行输出“Eureka!”， 否则在第二行输出“Search failed!”。
测试样例：
输入样例 1
6 23
4 11 15 18 23 35
输出样例 1
15 23
Eureka!
输入样例 2
9 50
4 11 15 18 23 35 41 53 67
输出样例 2
23 41 53
Search failed!
*/

int main(void){
    int n,key;
    scanf("%d %d",&n,&key);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int start=0,end=n-1,middle;
    while(start<=end){
        middle=(start+end)/2;
        printf("%d ",a[middle]);
        if(a[middle]==key){
            printf("\nEureka!");
            break;
        }
        else if(a[middle]<key){
            start=middle+1;
        }
        else{
            end=middle-1;
        }
    }
    if(start>end){
        printf("\nSearch failed!");
    };
}