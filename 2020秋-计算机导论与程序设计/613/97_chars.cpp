#include"stdio.h"
int main(void){
    char a='a';
    for(int i=1;i<=26;i++){
        printf("%c ",a);
        a++;
    }
    printf("\n");
    for(int i=1;i<=26;i++){
        a--;
        printf("%c ",a);
    }
}