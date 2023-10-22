#include <stdio.h>

int main() {
	char a, b, c, d, e, A, B, C, D, E;
	scanf("%c|%c|%c|%c|%c", &a, &b, &c, &d, &e);
	A = a + 32;
	B = b + 32;
	C = c + 32;
	D = d + 32;
	E = e + 32;
	printf("%c%c%c%c%c!", A, B, C, D, E);
	return 0;//这是注释
}