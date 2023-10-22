#include "stdio.h"

/*
标题
数值求和

描述
输入整数N（N≤20），输入二维矩阵A[N] [N]各元素值，计算所有对角线元素的和，每一元素只加一次，输出结算结果。

时间限制
1	
内存限制
10000	
类别
1

输入说明
输入整形数据N和N×N矩阵各元素值，如2和矩阵元素A={1,2,3,4}。

输出说明
格式输出：输出计算结果。

输入样例
2
1 2
3 4

输出样例
10

提示
采用重循环结构实现计算过程，所有对角线元素只加一次。

*/

int main(void){
    int n;
    scanf("%d",&n);
    int a[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    i=0;
    j=0;
    while(i<n){
        sum+=a[i++][j++];
    }
    i=0;
    j=n-1;
    while(i<n){
        sum+=a[i++][j--];
    }
    if(n%2!=0){
        sum-=a[n/2][n/2];
    }
    printf("%d",sum);
}