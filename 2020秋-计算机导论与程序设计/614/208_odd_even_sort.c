#include "stdio.h"

/*
标题
奇偶排序

描述
定义一个一维整形数组num[20]，输入正整数N（N≤20）代表num的实际元素个数，输入N个任意整数到num中，编写函数sort()实现排序处理，完成前面奇数，后面偶数，分别从小到大排序。使用指针完成地址传递，主函数完成N、数组元素的输入和处理后的数组元素输出。
   
时间限制
1	

内存限制
10000	

类别
1

输入说明
输入正整数N（N≤20）和N个任意排列的整形到一维数组num中。

输出说明
格式输出：数据之间空一格，奇数和偶数分界处空三个空格。

输入样例
5
2 3 7 8 4

输出样例
3 7   2 4 8

提示
使用指针作形参，实现地址传递。
前面奇数、后面偶数，分别从小到大排序。
输出数据之间空一格，奇数和偶数分界处空三个空格。
*/

void sort(int *pa,int *pb){
    int temp;
    if((*pa+*pb)%2==0){
        if(*pa>*pb){
            goto swap;
        }
    }
    else{
        if((*pa)%2==0){
            swap:temp=*pa;*pa=*pb;*pb=temp;
        }
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int num[20]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sort(&num[i],&num[j]);
        }
    }
    int done=0;
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
        if(done==0 && num[i+1]%2==0){
            done=1;
            printf("  ");
        }
    }
}