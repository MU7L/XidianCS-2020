#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
????????
????????????????
*/

int chartoint(char c);
int max(int a, int b);

int main() {
	char start[2000] = {0};
	char data1[1000] = {0};
	char data2[1000] = {0}; //??????????
	char end[1000] = {0}; //??????
	char c;  //???????
	printf("????????????§Ö??????????????");
	int i, j;
	scanf("%s",start); //?????›¥?????????

	int flag = 0; //??????????????????
	j = 0;
	for (i = 0; i < strlen(start); i++) {
		if (flag == 0) {
			if (start[i] != '+' && start[i] != '-' && start[i] >= '0' && start[i] <= '9') { //?????????›¥
				data1[j] = start[i]; //?›¥
				j++;
			} else if (start[i] == '+' || start[i] == '-') {
				c = start[i];
				flag++;  //????????
				j = 0; //???j
			}
		} else {
			if (start[i] >= '0' && start[i] <= '9') { //?????????›¥
				data2[j] = start[i];
				j++;
			}
		}
	}

	int temp = 0;
	int add = 0; //?????¦Ë
	int k = 0; //??????¦Ë??
	i = strlen(data1) - 1;
	j = strlen(data2) - 1; //???¦Ë???????
	k = max(strlen(data1), strlen(data2)) - 1;
	switch (c) {
		case '+':
			end[0] = '0';
			k = max(strlen(data1), strlen(data2));
			while (i >= 0 || j >= 0) {
				if (i >= 0 && j >= 0)
					temp = chartoint(data1[i]) + chartoint(data2[j]) + add; //??¦Ë????
				else if (i >= 0 && j < 0)
					temp = chartoint(data1[i]) + add;
				else if (i < 0 && j >= 0)
					temp = chartoint(data2[j]) + add;

				if (temp > 9) { //?§ß?¦Ë
					end[k] = temp % 10 + '0';
					add = temp / 10;
				} else {
					end[k] = temp + '0';
					add = 0;
				}
				i--;
				j--;
				k--;  //???????
			}
			if (add)
				end[0] = '1';
			break;
		case '-':
			while (i >= 0 || j >= 0) {
				int p;
				if (strlen(data1) > strlen(data2)) { //?????????
					if (i >= 0 && j >= 0)
						temp = chartoint(data1[i]) - chartoint(data2[j]);
					else if (i >= 0 && j < 0)
						temp = chartoint(data1[i]);
					if (temp < 0) { //??¦Ë
						for (p = i - 1; p >= 0; p--) {
							if (chartoint(data1[p])) { //??¦Ë????
								data1[p] = (chartoint(data1[p]) - 1) + '0'; //??¦Ë??1
								temp += 10;
								break;
							} else { //??¦Ë????
								data1[p] = '9';
								continue;
							}
						}
					}  //???????
					end[k] = temp + '0';
					i--;
					j--;
					k--;
				} else if (strlen(data1) == strlen(data2) && strcmp(data1, data2) >= 0) { //?????????
					if (i >= 0 && j >= 0)
						temp = chartoint(data1[i]) - chartoint(data2[j]);
					else if (i >= 0 && j < 0)
						temp = chartoint(data1[i]);
					if (temp < 0) { //??¦Ë
						for (p = i - 1; p >= 0; p--) {
							if (chartoint(data1[p])) { //??¦Ë????
								data1[p] = (chartoint(data1[p]) - 1) + '0';
								temp += 10;
								break;
							} else { //??¦Ë????
								data1[p] = '9';
								continue;
							}
						}
					}  //???????
					end[k] = temp + '0';
					i--;
					j--;
					k--;
				} else {
					end[0] = '-' ;//????
					k = max(strlen(data1), strlen(data2));
					char tempstr[1000] = {0};
					int tempint = 0;
					tempint = i;
					i = j;
					j = tempint;
					strcpy(tempstr, data1);
					strcpy(data1, data2);
					strcpy(data2, tempstr);
					if (i >= 0 && j >= 0)
						temp = chartoint(data1[i]) - chartoint(data2[j]);
					else if (i >= 0 && j < 0)
						temp = chartoint(data1[i]);
					if (temp < 0) { //??¦Ë
						for (p = i - 1; p >= 0; p--) {
							if (chartoint(data1[p])) { //??¦Ë????
								data1[p] = (chartoint(data1[p]) - 1) + '0'; //??¦Ë??1
								temp += 10;
								break;
							} else { //??¦Ë????
								data1[p] = '9';
								continue;
							}
						}
					}  //???????
					end[k] = temp + '0';
					i--;
					j--;
					k--;
				}
			}
	}

	int flag2 = 0; //????¦Ë??0??
	for (i = 0; i < strlen(end); i++) {
		if (end[i] == '0' && flag2 == 0)
			continue;
		else if (end[i] != 0) {
			printf("%c", end[i]);
			if (end[i] != '-') {
				flag2 = 1;
			}
		} else if (end[i] == '0' && flag2 != 0)
			printf("%c", end[i]); //??????0??
	}  //???
	return 0;
}

int chartoint(char c) {
	int out;
	out = c - '0';
	return out;
}

int max(int a, int b) {
	int max = a;
	if (b > a)
		max = b;
	return max;
}