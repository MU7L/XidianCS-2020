#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int* argc, char** argv)
{
	FILE* fp = fopen(argv[1], "rb");
	if (fp == 0)
		return 0;
	BITMAPFILEHEADER fileHead;
	fread(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);

	BITMAPINFOHEADER infoHead;
	fread(&infoHead, sizeof(BITMAPINFOHEADER), 1, fp);
	int width = infoHead.biWidth;  //以像素为单位的图像长度
	int height = infoHead.biHeight;  //以像素为单位的图像宽度
	int biCount = infoHead.biBitCount;  //每个像素的位数用以确定灰度级数

	int lineByte = (biCount*width / 8 + 3)/4*4;  //计算行字节数，详细请看结尾补充注释
	RGBQUAD* pColorTable;  //结构体指针
	pColorTable = new RGBQUAD[256];  //把RGBQUAD数组第一个的地址赋给pColorTable
	fread(pColorTable, sizeof(RGBQUAD), 256, fp);

	unsigned char* pBmpBuf;  //位图数据，整形
	pBmpBuf = new unsigned char[lineByte*height];  //申请位图数据所需要的空间，读位图数据进内存
	fread(pBmpBuf, lineByte*height, 1, fp);
	fclose(fp);

	// 统计概率
	double st[256] = { 0 };  //初始灰度值
	int st1[256] = { 0 };
	int t;
	for (int i = 0; i < height; ++i){  //行
		for (int j = 0; j < width; ++j){  //列
			t = *(pBmpBuf + i*lineByte + j);  //第i行第j列的像素指针（所在的存储空间的位置）
			st[t]++;  //统计
		}
	}
	// 计算
	st[0] = st[0] / (width*height);
	st1[0] = round(double((256 - 1)*st[0]));  //防止越界
	for (int i = 1; i < 256; ++i){
		st[i] = st[i] / (width*height);  //计算概率
		st[i] = st[i] + st[i - 1];  //累加
		st1[i] = int(round(double((256 - 1)*st[i])));  //通过公式计算均衡化后的灰度值
	}

	// 新图像的像素填充
	unsigned char* pBmpBuf1;
	pBmpBuf1 = new unsigned char[lineByte*height];
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			t = *(pBmpBuf + i*lineByte + j);
			*(pBmpBuf1 + i*lineByte + j) = st1[t];
		}
	}

	FILE* fop = fopen(argv[2], "wb");
	if (fop == 0)
		return 0;
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fop);
	fwrite(&infoHead, sizeof(BITMAPINFOHEADER), 1, fop);
	fwrite(pColorTable, sizeof(RGBQUAD), 256, fop);
	fwrite(pBmpBuf1, lineByte*height, 1, fop);
	fclose(fop);

	system("pause");
	return 0;
}

/*
#对行字节数求法的注释（int lineByte = (biCount*width / 8 + 3)/4*4）
这是计算位图每行占多少个字节
width是位图的宽度，也就是每行有多少个像素块，bicount是像素位数两者相乘是bit数
biCount*width / 8是求字节数
存储图像数据每行字节数为4的倍数，所以+3是怕出现不满足4的倍数这种情况
如果是4的倍数则结果和不+3的结果是一样的，如果不是4的倍数则结果进1位 
/4*4除以四在乘以四是把数据归为4的倍数，不够4的倍数就把余数约掉。只留商。
举个例子整形的话17/4=4（正常是4又1/4）而计算机直接算出来等于4
再乘以四就等于16
也就是说把17归为4的倍数=16；
*/