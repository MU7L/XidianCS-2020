#include"stdio.h"

int sumi(int x){
    int sum=0;
    for(int i=0;i<9;i++){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int maxid=0;
    for(int i=1;i<n;i++){
        if(sumi(a[maxid])<sumi(a[i])){
            maxid=i;
        }
        else if(sumi(a[maxid])==sumi(a[i])){
            if(a[maxid]<a[i]){
                maxid=i;
            }
        }
    }
    printf("%d",a[maxid]);
}