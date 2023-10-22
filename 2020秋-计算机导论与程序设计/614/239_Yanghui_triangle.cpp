#include "stdio.h"

/*

给出正整数n（2<=n<=10）,输出杨辉三角前n行
杨辉三角性质：三角形中的每个数字等于它两肩上的数字相加


输入格式：输入一个正整数n
输出格式：输出杨辉三角的前n行，元素中间用一个空格分隔，每行用换行分隔

输入样例：
4

输出样例
1
1 1
1 2 1
1 3 3 1
*/

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

int main(void){
    //初始化
    int a[10][10]={0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        a[i][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}