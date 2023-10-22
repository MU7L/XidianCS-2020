#include"stdio.h"
int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b){
        int temp=a;a=b;b=temp;
    }
    printf("%d %d",b%10,a*a);
}