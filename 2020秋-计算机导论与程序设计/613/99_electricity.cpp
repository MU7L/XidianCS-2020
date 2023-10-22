#include"stdio.h"
int main(void){
    float e,fee,extra;
    char s;
    scanf("%f",&e);
    if(e<=110){
        extra=0;
        fee=.5*e;
        s='A';
    }
    else if(e<=210){
        extra=e-110;
        fee=.5*110+.55*extra;
        s='B';
    }
    else{
        extra=e-210;
        fee=.5*110+.55*(210-110)+.7*extra;
        s='C';
    }
    printf("%.2f %c %.2f",fee,s,extra);
}