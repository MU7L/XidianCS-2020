#include <stdio.h>
int main(){
    float a,x_1=2.,x_2;
    scanf("%f",&a);
    do{
        x_2=(x_1+a/x_1)/2.;
        if((x_2-x_1>=0.00001||x_1-x_2>=0.00001)){
            x_1=x_2;
        }
        else break;
    }while(x_2-x_1<0.00001||x_1-x_2<0.00001);
    printf("%.5f",x_2);
    return 0;
}