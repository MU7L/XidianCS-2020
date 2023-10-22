#include "stdio.h"

/*
题目：3*3矩阵对角线求和
时间限制：1S
内存限制：10000Kb
问题描述：
求一个 的整型矩阵对角线元素之和。
输入说明：
输入3*3的整型矩阵。
输出说明：
输出一个整数，即对角线的和。
输入样例：
1 2 3
4 5 6
7 8 9
输出样例：
15
*/

int main(void){
    int a[3][3];
    int i=0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    i=0;
    j=0;
    while(i<3){
        sum+=a[i++][j++];
    }
    printf("%d",sum);
}