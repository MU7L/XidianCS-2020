#include"stdio.h"

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=100;i<1000;i++){
        int j=n-i;
        if(i/100==j%10 && i%10==j/100 && (i/10)%10==(j/10)%10){
            printf("%d %d %d\n",i/100,(i/10)%10,i%10);
        }
    }
