#include "stdio.h"
#include"math.h"
int main(void){
    float n;
    scanf("%f",&n);
    float s=100,h=50;
    for(int i=1;i<n;i++){
        s+=h*2;
        h/=2;
    }
    printf("s=%.3f h=%.3f",s,h);
}