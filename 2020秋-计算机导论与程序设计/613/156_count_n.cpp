#include "stdio.h"
int main(void){
    int n=0;
    for(int i=100;i<=500;i++){
        if(i%7==0 || i%11==0){
            if(i%77!=0)
                n++;
        }
    }
    printf("%d",n);
}