#include"stdio.h"
int main(void){
    int n,t=0;
    scanf("%d",&n);
    while(n>1){
        if(n%2==0){
            n/=2;
        }
        else{
            n=3*n+1;
        }
        t++;
    }
    printf("%d",t);
}