#include "stdio.h"
int main(void){
    int a[2][3],b[3][2],c[2][2]={0};
    //创建矩阵
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    //计算 可简化
    for(int i=0;i<3;i++){
        c[0][0]+=a[0][i]*b[i][0];
        c[0][1]+=a[0][i]*b[i][1];
        c[1][0]+=a[1][i]*b[i][0];
        c[1][1]+=a[1][i]*b[i][1];
    }
    //打印
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%5d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("%5d ",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%5d ",c[i][j]);
        }
        printf("\n");
    }
}