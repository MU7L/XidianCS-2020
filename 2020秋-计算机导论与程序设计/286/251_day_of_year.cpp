#include "stdio.h"
#include "iostream"
using namespace std;
/*
题目：年月日统计 
时间限制：1S
内存限制：10000Kb

问题描述：
定义一个结构体变量（包括年，月，日）。计算该日在本年中是第几天，（注意闰年问题）

输入说明：
输入三个数，分别表示年月日，数字之间用逗号隔开。
输出说明：
输出一个整数，表示该日期是本年中的第几天。
输入样例：
2019,1,30
输出样例：
30
*/

int main(void){
    int year,month,day;
    scanf("%d,%d,%d",&year,&month,&day);
    int days=0;
    int sec=28;
    if((year%400==0)||(year%4==0 && year%100!=0)){
		sec=29;
	}
    int m;
    if(month==1){
        days=day;
    }
    else if(month==2){
        days=31+day;
    }
    else if(month<=7){
        days=31+sec;
        for(m=3;m<month;m++){
            if(m%2!=0){
                days+=31;
            }
            else{
                days+=30;
            }
        }
        days+=day;
    }
    else{
        days=31+sec+31+30+31+30+31;
        for(m=8;m<month;m++){
            if(m%2!=0){
                days+=30;
            }
            else{
                days+=31;
            }
        }
        days+=day;
    }
    cout << days;
}