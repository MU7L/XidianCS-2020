#include "stdio.h"
int main(void){
    int n,sum,i=1;
    scanf("%d",&n);
    while(i<=n){
        sum+=i;
        i++;
    }
    printf("%d",sum);
}