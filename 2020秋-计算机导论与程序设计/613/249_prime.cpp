#include "stdio.h"

int is_prime(int x){
    /*判断x是否为质数，是为1，否为0*/
    int is = 1;
    for(int i = 2; i < x; i++){
        if(x % i == 0){
            is = 0;
            break;
        }
    }
    return is;
}

bool is_prime2(int x){
    /*判断x是否为质数，是为true，否为false*/
    bool is = false;
    for(int i = 2; i < x; i++){
        if(x % i == 0){
            is = true;
            break;
        }
    }
    return is;
}

int main(void){
    int n;
    scanf("%d", &n);
    int i = 2;
    while(is_prime(n) == 0){
        if(n%i == 0 && is_prime(i) == 1){
            n /= i;
            printf("%d*", i);
        }
        else if(n % i != 0){
            i++;
        }
    }
    printf("%d", n);
}