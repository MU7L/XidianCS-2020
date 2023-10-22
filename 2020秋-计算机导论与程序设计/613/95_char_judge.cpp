#include"stdio.h"
int main(void){
    char a=getchar();
    if(a>=65 && a<=90){
        a+=32;
    }
    if(a>=97 && a<=122){
        a-=32;
    }
    putchar(a);
}