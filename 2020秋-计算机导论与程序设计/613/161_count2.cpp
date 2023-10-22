#include "stdio.h"
int main(void){
    int n,odd=0,even=0,div3=0,div5=0,div7=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2!=0)
            odd++;
        if(i%2==0)
            even++;
        if(i%3==0)
            div3++;
        if(i%5==0)
            div5++;
        if(i%7==0)
            div7++;
    }
    printf("%d %d %d %d %d",odd,even,div3,div5,div7);
}