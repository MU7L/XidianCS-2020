#include "stdio.h"
int main(void){
    int n,a[4]={0};
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        a[i]=n%10;//个位为a[0]
        n/=10;
    }
    printf("%d %d %d %d %d",a[3],a[2],a[1],a[0],a[3]+a[2]+a[1]+a[0]);
}