#include"stdio.h"

int main(void){
    int n,Pi,sum=0,ssr=0,sr=0,a=0,b=0,c=0,d=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&Pi);
        sum+=Pi;
        if(Pi<=50) ssr++;
        else if(Pi<=100) sr++;
        else if(Pi<=150) a++;
        else if(Pi<=200) b++;
        else if(Pi<=300) c++;
        else d++;
    }
    printf("%.2f\n",sum*1./n);
    printf("%d %d %d %d %d %d",ssr,sr,a,b,c,d);
}