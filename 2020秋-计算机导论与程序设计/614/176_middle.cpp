#include "stdio.h"

/*
标题	
中间数

类别	
时间限制	
1S

内存限制	
256Kb

问题描述	
在一个整数序列A1, A2, …, An中，如果存在某个数，大于它的整数数量等于小于它的整数数量，则称其为中间数。
在一个序列中，可能存在多个下标不相同的中间数，这些中间数的值是相同的。
给定一个整数序列，请找出这个整数序列的中间数的值。

输入说明	
输入的第一行包含了一个整数n，表示整数序列中数的个数，1 ≤ n ≤ 1000。
第二行包含n个正整数，依次表示A1, A2, …,An，1 ≤ Ai ≤ 1000。

输出说明	
如果序列的中间数存在，则输出中间数的值，否则输出-1表示不存在中间数。

输入样例	
输入样例1
6
2 6 5 6 3 5
输入样例2
4
3 4 6 7

输出样例	
输出样例1
5
输出样例2
-1


样例说明	
样例1中比5小的数有2个，比5大的数也有2个。因此中间数是5
样例2中4个数都不满足中间数的定义，因此中间数是-1

*/

void lgr_smlr(int a,int *p,int n,int *pa,int *pb){
    int t=1;
    for(t=1;t<=n;t++){
        if(a<*p){
            (*pa)++;
        }
        else if(a>*p){
            (*pb)++;
        }
        p++;
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int is=0;
    for(int i=0;i<n;i++){
        int larger=0,smaller=0;
        lgr_smlr(a[i],&a[0],n,&larger,&smaller);
        if(larger==smaller){
            printf("%d",a[i]);
            is=1;
            break;
        }
    }
    if(is==0){
        printf("-1");
    }
}