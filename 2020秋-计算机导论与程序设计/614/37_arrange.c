#include "stdio.h"

void cmp(int *pa,int *pb){
    if((*pa+*pb)%2==0){//同奇偶
        if(*pa<*pb){//从大到小
            goto swap;
        }
    }
    else{//一奇一偶
        if(*pb%2==0){//定义偶数大于奇数
            int temp;
            swap:temp=*pa;*pa=*pb;*pb=temp;
        }
    }
}

int main(void){
    //输入数组
    int n;
    scanf("%d",&n);
    int a[100]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //排序
    int t=n;
    while(t>0){
        for(int i=0;i<n-1;i++){
            cmp(&a[i],&a[i+1]);
        }
        t--;
    }
    //输出
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}