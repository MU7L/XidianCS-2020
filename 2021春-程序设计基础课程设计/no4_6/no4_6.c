#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zip(char *file, char *finalfile) {
	FILE *in, *out;
	int len;
	char c, temp;
	if (!(in = fopen(file, "rb"))) {  //�����Ʒ�ʽ��ֻ���ļ�
		printf("�ļ�������");
	} else {
		out = fopen(finalfile, "wb");  //��������ʽ��ֻд�ļ�
		c = fgetc(in);
		temp = c;
		len = 1;
		while (!feof(in)) {
			c = getc(in);
			if (c == temp) {  //������ͬ
				len++;
			} else {
				if (len > 3) {  //������λ���ϲ�ѹ��
					fputc(temp, out);
					fputc(len + '0', out);
					temp = c;
					len = 1;
				} else {
					for (int i = len; i > 0; i--) {  //i>0
						fputc(temp, out);
					}
					len = 1;
					temp = c;
				}
			}
		}
	}
	fclose(in);
	fclose(out);  //�ر��ļ�
}

void unzip(char *file, char *finalfile) {
	//��ѹ���� ��ע�ͻ����������һ�� ������׸��
	FILE *in, *out;
	int len;
	char c;
	if (!(in = fopen(file, "rb")))
		printf("�ļ���ʧ��\n");
	else {
		out = fopen(finalfile, "wb");
		while (!feof(in)) {
			c = fgetc(in);
			if (feof(in))
				break;
			len = fgetc(in) - '0';
			while (len--)
				fputc(c, out);
		}
	}
	fclose(in);
	fclose(out);
}

int main(int argc, char *argv[]) {

	if (argc != 4) {
		printf("�����������");
		return 0;
	}

	if (!strcmp(argv[2], "-d")) {
		unzip(argv[1], argv[3]);
		printf("decompress finished\n");
	} else if (!strcmp(argv[2], "-c")) {
		zip(argv[1], argv[3]);
		printf("compress finished\n");
	}
	return 0;
}