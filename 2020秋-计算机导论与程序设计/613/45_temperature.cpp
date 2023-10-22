#include"stdio.h"
#include"math.h"
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int minus_max=abs(a[0]-a[1]),minus;
    for(int i=1;i<n;i++){
        minus=a[i+1]-a[i];
        if(minus_max<minus){
            minus_max=minus;
        }
    }
    printf("%d",minus_max);
}