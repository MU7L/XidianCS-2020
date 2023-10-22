#include <stdio.h>

int main() {
	int q, w, e, num;
	scanf("%d", &num);
	q = (num / 100) % 10;
	w = (num / 10) % 10;
	e = num % 10;
	printf("%d %d %d", q, w, e);
	return 0;
}