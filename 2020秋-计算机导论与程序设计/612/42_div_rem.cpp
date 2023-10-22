#include <stdio.h>

int main() {
	int a, b, div, rem;
	scanf("%d %d", &a, &b);
	div = a / b;
	rem = a % b;
	if (rem == 0)
		printf("yes");
	if (rem != 0)
		printf("%d %d", div, rem);
	return 0;
}