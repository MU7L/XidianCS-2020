#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

int pow(int n1, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= n1;
	}
	return result;
}

void initial(char str[], int &n, int data[]) {
	int tempn;
	int temp = 0;
	int j = 0;
	int k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tempn++;
			for (k = i + 1; k < strlen(str); k++) {
				if (str[k] >= '0' && str[k] <= '9') {
					tempn++;
				} else {
					break;
				}
			}
			for (int p = i; p < k; p++, tempn--) {
				temp += (str[p] - '0') * pow(10, tempn - 1);
			}
			data[j] = temp;
			//printf("%d ", temp);
			j++;
			tempn = 0;
			temp = 0;
			i = k;
		}
	}
	n = j;
	//printf("%d", n);
}

int isR(int a, int b, int data[], int n) {
	for (int i = 0; i < n; i = i + 2) {
		if (i % 2 == 0 && a == data[i]) {
			if (b == data[i + 1]) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	char domstr[1000] = {0};
	char ranstr[1000] = {0};
	char Rstr[1000] = {0}; //定义域、值域、关系暂存在字符串中
	cin.getline(domstr, 100);
	cin.getline(ranstr, 100);
	cin.getline(Rstr, 100);
	/*gets(domstr);
	gets(ranstr);
	gets(Rstr);*/
	int dom[100] = {0};
	int domn = 0;
	int ran[100] = {0};
	int rann = 0;
	int Rdata[100] = {0};
	int Rn = 0;
	initial(domstr, domn, dom);
	initial(ranstr, rann, ran);
	initial(Rstr, Rn, Rdata);
	int R[100][100] = {0};
	int i, j;
	for (i = 0; i < domn; i++) {
		for (j = 0; j < rann; j++) {
			R[i][j] = isR(dom[i], ran[j], Rdata, Rn);
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
	//printf("%d", domn);
}