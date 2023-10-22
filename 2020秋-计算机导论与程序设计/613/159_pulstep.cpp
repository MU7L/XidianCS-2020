#include "stdio.h"

int Mul(int n){
    int result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}

float P(int m,int n){
    int result=Mul(m)/Mul(n)/Mul(m-n);
    return result;
}

int main(void){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%.2f",P(m,n));
}