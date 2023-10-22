#include <stdio.h>
int main(){
    int a,b;
    float d;
    char c;
    scanf("%d%c%d",&a,&c,&b);
    switch(c){
        case '+':d=a+b;break;
        case '-':d=a-b;break;
        case '*':d=a*b;break;
        case '/':d=a*1./b;break;
        case '%':d=a%b*1.;break;
    }
    printf("%d%c%d=%.0f",a,c,b,d);
    return 0;
}