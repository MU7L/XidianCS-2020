#include "stdio.h"
int main(void){
    int x,sum;
    do{
        scanf("%d",&x);
        if(x%2!=0){
            sum+=x;
        }
    }while(x!=0);
    printf("%d",sum);
}