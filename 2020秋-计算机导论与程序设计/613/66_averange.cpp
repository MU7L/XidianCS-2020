#include"stdio.h"
int main(void){
    int n,x,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        sum+=x;
    }
    printf("%.2f",sum*1./n);
}