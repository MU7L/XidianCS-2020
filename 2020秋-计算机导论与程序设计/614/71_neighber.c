#include"stdio.h"

/*
遍历所有，从k开始十字扫描
十字中有非k数时，记录该数，边界+1
跳到下一位进行十字扫描，扫描到记录过的数时不计

矩阵周边套一圈0，在十字扫描时遇0不计
*/

int is_in(int a,int *p){
    int i=0;
    for(i=0;i<50;i++){
        if(*p==a){
            return 1;
        }
        else{
            *p++;
        }
    }
    if(i==50){
        return 0;
    }
}

int main(void){
    //创建矩阵 套0圈
    int n,m,t,k;
    scanf("%d %d %d %d",&n,&m,&t,&k);
    int a[21][21]={0};
    int N=1,M=1;
    for(N=1;N<=n;N++){
        for(M=1;M<=m;M++){
            scanf("%d",&a[N][M]);
        }
    }
    //遍历
    int have_scan[50]={0};
    int board=0;
    for(N=1;N<=n;N++){
        for(M=1;M<=m;M++){
            if(a[N][M]==k){//十字扫描
                if(a[N-1][M]!=k){
                    if(is_in(a[N-1][M],have_scan)==0){
                        have_scan[board++]=a[N-1][M];
                    }
                }
                if(a[N+1][M]!=k){
                    if(is_in(a[N+1][M],have_scan)==0){
                        have_scan[board++]=a[N+1][M];
                    }
                }
                if(a[N][M-1]!=k){
                    if(is_in(a[N][M-1],have_scan)==0){
                        have_scan[board++]=a[N][M-1];
                    }
                }
                if(a[N][M+1]!=k){
                    if(is_in(a[N][M+1],have_scan)==0){
                        have_scan[board++]=a[N][M+1];
                    }
                }
            }
        }
    }
    printf("%d",board);
}