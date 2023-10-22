#include "stdio.h"

int main(void) {
	int m,  i = 1;
	scanf("%d", &m);
	while (i) {
		int n = 2 * i - 1, t = 0, sum = 0;
		for (; t < m; n += 2, t++) {
			sum += n;
		}
		int p = i;
		if (sum == m * m * m) {
			for (t = 0; t < m; t++, p++) {
				printf("%d ", 2 * p - 1);
			}
			printf("\n");
			break;
		}
		else {
			i++;
			continue;
		}
	}
}