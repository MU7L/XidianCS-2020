#include "stdio.h"

int is_perfect_number(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum == n) return 1;
	else return 0;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
    while(a<=b){
        //printf("%d\n",a);
        if(is_perfect_number(a)==1){
            printf("%d\n",a);
        }
		a++;
    }
    return 0;
}