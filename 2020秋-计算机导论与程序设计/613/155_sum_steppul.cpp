#include "stdio.h"
int main(void){
    int n,pul=1,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        pul*=i;
        sum+=pul;
    }
    printf("%d %d %d",n,pul,sum);
}