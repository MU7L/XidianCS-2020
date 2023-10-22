#include <stdio.h>

int main() {
	int a, b, add, sub, mul, div,mod;
	scanf("%d %d", &a, &b);
	add = a + b;
	sub = a - b;
	mul = a * b;
	div = a / b;
    mod=a%b;
	printf("%d ", add);
	printf("%d ", sub);
	printf("%d ", mul);
	printf("%d ", div);
    printf("%d ", mod);
	return 0;
}