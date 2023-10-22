#include <stdio.h>
int main(){
    char letter;
    int row;
    scanf("%c %d",&letter,&row);
    
    //在第i行打印 第i行有i个字符 左边到对称中心是row个字符
    for(int i=1;i<=row;i++){
        
        //打印左边j个空格
        for(int j=1;j<=row-i;j++){
            printf(" ");
        }
        //打印中间i个字符
        for(int k=1;k<=i;k++){
            printf("%c ",letter);
        }
        printf("\n");
    }
    return 0;
}