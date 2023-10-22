#include "stdio.h"
#include "string.h"

int main(void) {
	char num[9] = {0};
	gets(num);
	int len = strlen(num);
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] < num[j]) {
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%c ", num[i]);
	}
}