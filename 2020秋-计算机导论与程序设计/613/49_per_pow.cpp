#include"stdio.h"
#include"math.h"
int main(void){
    int n;
    float m;
    scanf("%d",&n);
    m=sqrt(n);
    if(m*m==n){
        printf("%.0f",m);
    }
    else{
        printf("no");
    }
}