#include <stdio.h>

int main() {
	int a, b, c, C;
	scanf("%d %d %d", &a, &b, &c);
	C = a + b + c;
	if (a + b > c && a + c > b && c + b > a)
		printf("%d", C);
	else
		printf("No");
	return 0;
}