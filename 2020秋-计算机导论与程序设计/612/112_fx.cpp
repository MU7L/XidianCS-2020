#include <stdio.h>
#include <math.h>

int main() {
	float x, f;
	scanf("%f", &x);
	if (x >= 0) {
		f = pow(x, 0.5);
	} else {
		f = pow((x + 1), 2) + 2 * x + 1 / x;
	}
	printf("%.2f", f);
	return 0;
}