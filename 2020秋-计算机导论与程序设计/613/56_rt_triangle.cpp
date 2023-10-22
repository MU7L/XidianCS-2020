#include"stdio.h"

int main(void){
    int a,b,c,s;
    scanf("%d %d %d",&a,&b,&c);
    if(a*a+b*b==c*c){
        printf("%d",a*b);
    }
    else if(a*a+c*c==b*b){
        printf("%d",a*c);
    }
    else if(b*b+c*c==a*a){
        printf("%d",c*b);
    }
    else{
        printf("no");
    }
}