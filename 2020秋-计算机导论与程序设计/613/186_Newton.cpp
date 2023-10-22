#include "stdio.h"

float f(float x){
    return 2*x*x*x-4*x*x+3*x-6;
}

float f_(float x){
    return 6*x*x-8*x+3;
}

int main(void){
    float x;
    scanf("%f",&x);
    for(int i=0;i<100;i++){
        if(f_(x)==0)
            break;
        else{
            x-=f(x)/f_(x);
        }
    }
    printf("%.2f",x);
}