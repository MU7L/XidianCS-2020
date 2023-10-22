#include"stdio.h"
int main(void){
    //创建数组
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //排序
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];a[i]=a[j];a[j]=temp;
            }
        }
    }
    //计数
    int t=1;
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            t++;
        }
        else{
            printf("%d:%d\n",a[i],t);
            t=1;
        }
    }
}