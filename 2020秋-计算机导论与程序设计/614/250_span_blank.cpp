#include "stdio.h"

/*
螺旋填数

题目描述：
创建一个m行n列的数组，将1—m*n的数字螺旋填入
方向为右下左上

输入说明：
输入正整数m和n，以空格分隔

输出说明:
输出填好的数组，数组元素之间用空格分隔，数组每行之间以换行分隔

输入示例：
4 5

输出示例：
1 2 3 4 5
14 15 16 17 6
13 20 19 18 7
12 11 10 9 8
*/

int main(void){
    int m,n;//行，列
    int t=1;//填入t
    scanf("%d %d",&m,&n);
    int a[m][n];
    int round=1;//round%4为1时右行，2时下行，3时左行，4时右行
    int i=0,j=0;//定位
    int board=0;//边界
    while(t<=m*n){
        if(round%4==1){
            while(j<n-board){
                a[i][j++]=t++;
            }
            j--;//还原
            i++;//准备下一步
        }
        else if(round%4==2){
            while(i<m-board){
                a[i++][j]=t++;
            }
            i--;
            j--;
        }
        else if(round%4==3){
            while(j>=board){
                a[i][j--]=t++;
            }
            j++;
            i--;
        }
        else{
            while(i>=board){
                a[i--][j]=t++;
            }
            i++;
            j++;
        }
        round++;
        if(round%4==0){
            board++;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}