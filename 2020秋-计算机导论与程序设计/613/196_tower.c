#include "stdio.h"
int main(void){
    char letter,a='A';
    scanf("%c",&letter);
    int n=letter-64;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("%c",a);
            a++;
        }
        a--;
        for(int j=1;j<i;j++){
            a--;
            printf("%c",a);
        }
        printf("\n");
        a='A';
    }
}