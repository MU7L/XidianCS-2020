#include"stdio.h"

int main(void){
    int score0,score=1,t=1;
    scanf("%d",&score0);
    int sum=score0;
    if(score0 == 0)
        sum=0;
    else{
        while(score != 0){
            scanf("%d",&score);
            if(score0==2 && score==2){
                t++;
                sum+=2*t;
            }
            else{
                t=1;
                sum+=score;
            }
            score0=score;
        }
    }
    printf("%d",sum);
}