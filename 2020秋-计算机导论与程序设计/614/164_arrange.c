#include "stdio.h"
#include "string.h"

/*
标题
转换排序

描述
输入一维字符数组str[N]（N≤80），查找出其中小写字母并转换成大写字母，按下面方式排序：1、只对大写字母进行排序；2、其他字符原位保持不动；3、转换后的各大写字母由小到大排序。输出排序后的结果。

时间限制
1	
内存限制
10000	
类别
1

输入说明
输入一行字符数据str[N]（N≤80）。

输出说明
格式输出：输出仅对转换后的大写字母排序结果，其他字符原位不动输出。

输入样例
xA3T7p

输出样例
AP3T7X

提示
注意转换方式和排序要求。

*/

int is_char(char a){
    if( (a>='A' && a<='Z') || (a>='a' && a<='z') ){
        return 1;
    }
    else return 0;
}

void iswap(char *pa,char *pb){
    if(*pa>*pb){
        char temp=*pa;*pa=*pb;*pb=temp;
    }
}

int main(void){
    char str[80]={0};
    scanf("%s",str);
    strupr(str);
    int i,j;
    for(i=0;i<strlen(str);i++){
        if(is_char(str[i])==1){
            for(j=i+1;j<strlen(str);j++){
                if(is_char(str[j])==1){
                    iswap(&str[i],&str[j]);
                }
            }
        }
    }
    printf("%s",str);
}