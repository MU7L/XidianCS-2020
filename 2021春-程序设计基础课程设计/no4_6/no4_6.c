#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zip(char *file, char *finalfile) {
	FILE *in, *out;
	int len;
	char c, temp;
	if (!(in = fopen(file, "rb"))) {  //二进制方式打开只读文件
		printf("文件不存在");
	} else {
		out = fopen(finalfile, "wb");  //二进制形式打开只写文件
		c = fgetc(in);
		temp = c;
		len = 1;
		while (!feof(in)) {
			c = getc(in);
			if (c == temp) {  //连续相同
				len++;
			} else {
				if (len > 3) {  //连续三位以上才压缩
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
	fclose(out);  //关闭文件
}

void unzip(char *file, char *finalfile) {
	//解压函数 ，注释会基本和上面一样 ，不再赘述
	FILE *in, *out;
	int len;
	char c;
	if (!(in = fopen(file, "rb")))
		printf("文件打开失败\n");
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
		printf("输入参数有误");
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