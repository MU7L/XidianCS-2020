#include "stdio.h"
#include "string.h"

/*
用add存储初始位置
循环：
	用scanf(hd)接收命令头hd
		命令头为pwd时跳出
		命令头为cd时继续
	用scanf(op)接收cd后的命令
	若op第一位
		为 /: add内容变为/，判断op下一位，规则同前
		为 .:
			若add只有/：不作用
			否则：add删除后3位
		为 d:
			若不是根目录：将op加上/接在add后面
			若是根目录：直接接在后面
		（为空：contine）
scanf(hd)到pwd时跳出，打印add
结束
*/

int main(void){
	char add[200]={0},hd[3]={0},op[200]={0};
	gets(add);
	while(1){
		scanf("%s",hd);
		if(strcmp(hd,"pwd")==0){//add[0]出现null?
			add[0]='/';//一个傻逼的解决方案-对应29行
			break;
		}
		else{
			scanf("%s",op);
			switch(op[0]){
				case '/': {
					int len=strlen(add);
					for(int i=1;i<len;i++){
						add[i]='\0';
					}
					if(op[1]=='d'){
						goto plus;
					}
					break;
				}
				case '.': {
					if(strcmp(add,"/")==0){
						continue;
					}
					else{
						for(int i=0;i<3;i++){
							add[strlen(add)-1]='\0';
						}
					}
					break;
				}
				case 'd': {
plus:
					if(strcmp(add,"/")>0){//非根目录
						strcat(add,"/");
						strcat(add,op);
					}
					else{//根目录
						strcpy(add,op);
					}
				}
			}
		}
		//puts(add);调试用
	}
	puts(add);
}