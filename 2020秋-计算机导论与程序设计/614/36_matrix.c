#include "stdio.h"
int main(void){
    //创建矩阵
    int m,i=0,j=0;
    scanf("%d",&m);
    int a[m][m];
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    //计算,生成数组res[]
    int res[42]={0};
    int t=0;
        //计算横排
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            res[t]+=a[i][j];
        }
        t++;
    }
        //计算纵列
    for(j=0;j<m;j++){
        for(i=0;i<m;i++){
            res[t]+=a[i][j];
        }
        t++;
    }
        //计算主对角线?
    i=j=0;
    while(i<m){
        res[t]+=a[i][j];
        i++;
        j++;
    }
    t++;
        //计算辅对角线?
    i=0;
    j=m-1;
    while(i<m){
        res[t]+=a[i][j];
        i++;
        j--;
    }
    //检查res[]
    
    /*for(i=0;i<2*m+2;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    */
    //数组res[]排序
    for(i=0;i<2*m+2;i++){
        for(j=i+1;j<2*m+2;j++){
            if(res[i]<res[j]){
                int temp=res[i];res[i]=res[j];res[j]=temp;
            }
        }
    }
    //打印
    for(i=0;i<2*m+2;i++){
        printf("%d ",res[i]);
    }
    
}