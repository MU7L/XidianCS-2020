#include "stdio.h"

int main(void){
    char str[7];
    scanf("%s",str);
    for(int i=0;i<7;i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]='A'+'Z'-str[i];
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i]='a'+'z'-str[i];
        }
    }
    printf("%s",str);
}