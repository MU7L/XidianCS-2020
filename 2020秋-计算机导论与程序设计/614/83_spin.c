#include "stdio.h"
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    int N,M;
    for(N=0;N<n;N++){
        for(M=0;M<m;M++){
            scanf("%d",&a[N][M]);
        }
    }
    for(M=0;M<m;M++){
        for(N=n-1;N>=0;N--){
            printf("%d ",a[N][M]);
        }
        printf("\n");
    }
}