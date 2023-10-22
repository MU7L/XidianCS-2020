#include "stdio.h"

int main(void) {
	int n, sum = 0;
	scanf("%d", &n);
	do {
		sum += n % 10;
		n = n / 10;
	} while (n != 0);
	printf("%d\n", sum);
}