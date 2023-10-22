#include <stdio.h>

int main() {
	int m, n, q, r, Q, R;
	scanf("%d %d %d %d", &m, &n, &q, &r);
	Q = m / n;
	R = m % n;
	if (q == Q && r == R)
		printf("yes");
	else
		printf("%d %d", Q, R);
	return 0;
}