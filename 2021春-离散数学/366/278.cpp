#include <stdio.h>

int main() {
	int n;
	int a[100][100];
	int flag = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		flag = flag;
		if (a[i][i] == 1) {
			flag = flag + 1;
		} else if (a[i][i] == 0) {
			flag = flag;
		}
	}
	if (flag == n ) {
		printf("The matrix is reflexive.");
	} else if (flag == 0) {
		printf("The matrix is irreflexive.");
	} else if (flag != 0 && flag != n ) {
		printf("The matrix is not irreflexive or reflexive.");
	}

	return 0;
}