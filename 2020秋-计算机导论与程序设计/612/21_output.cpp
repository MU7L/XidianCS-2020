#include <stdio.h>

int main() {
	int q, w, e, r, t, num;
	scanf("%d", &num);
	q = (num / 10000) % 10;
	w = (num / 1000) % 10;
	e = (num / 100) % 10;
	r = (num / 10) % 10;
	t = num % 10;
	printf("%d %d %d %d %d", q, w, e, r, t);
	return 0;
}