#include"stdio.h"

int main(void){
    int n,max;
    scanf("%d",&max);
    for(int i=0;i<3;i++){
        scanf("%d",&n);
        if(max<n){
            max=n;
        }
    }
    printf("%d",max);
}