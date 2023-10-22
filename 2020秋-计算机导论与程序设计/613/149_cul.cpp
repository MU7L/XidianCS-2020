#include "stdio.h"
#include "math.h"
int main(void){
    int n;
    float sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum-=pow(-1,i)*i/(2*i-1);
    }
    printf("%.3f",sum);
}