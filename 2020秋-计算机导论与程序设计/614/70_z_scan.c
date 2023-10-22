#include"stdio.h"
int main(void){
    //creat a[n][n]
    int n;
    scanf("%d",&n);
    int a[n][n];
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    //scan
    int t=1,k=0;
    i=j=0;
    int b[100]={0};
    b[k]=a[i][j];
    while(t<=2*(n-1)){
        if(t%2!=0){
            if(t+1<=n){
                b[++k]=a[i][++j];
            }
            else{
                b[++k]=a[++i][j];
            }
            while(i+1<n && j-1>=0){
                b[++k]=a[++i][--j];
            }
        }
        else{
            if(t+1>n){
                b[++k]=a[i][++j];
            }
            else{
                b[++k]=a[++i][j];
            }
            while(i-1>=0 && j+1<n){
                b[++k]=a[--i][++j];
            }
        }
        t++;
    }
    //print
    for(i=0;i<n*n;i++){
        printf("%d ",b[i]);
    }
}