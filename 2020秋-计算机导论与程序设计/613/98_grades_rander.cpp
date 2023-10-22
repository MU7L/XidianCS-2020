#include"stdio.h"

int main(void){
    float m;
    scanf("%f",&m);
    if(m>=90){
        printf("%.2f A",m);
    }
    else if(m>=80){
        printf("%.2f B",m);
    }
    else if(m>=70){
        printf("%.2f C",m);
    }
    else if(m>=60){
        printf("%.2f D",m);
    }
    else{
        printf("%.2f E",m);
    }
}