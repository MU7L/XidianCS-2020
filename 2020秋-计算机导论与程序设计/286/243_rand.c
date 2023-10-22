#include "stdio.h"

/*
试题名称	考试排名
时间限制:	1 秒
内存限制:	256KB

问题描述
某考试有5道题和1道附加题，每题最高得分20分，总分计算为所有题目分数之和。给出一组考生的数据，对其按照总分从高到低进行排名，总分相同时按附加题得分高者优先。

输入说明
第一行为一个整数N，表示考生个数（N小于100），后面N行为考生数据，每行包含考生姓名（长度不超过20个字符）以及6个以空格分隔的整数，分别表示第一题到第五题以及附加题的得分（最后一项）。

输出说明
输出排序结果，每行为一个考生的姓名、总分、附加题得分，以空格分开。

输入样例
3 
Jony 18 20 20 20 20 20 
Kavin 20 20 20 20 20 18 
Kaku 15 15 15 15 15 15

输出样例
Jony 118 20 
Kavin 118 18 
Kaku 90 15
*/

typedef struct{
    char name[20];
    int q_1;
    int q_2;
    int q_3;
    int q_4;
    int q_5;
    int plus;
    int sum;
}Stud;

int main(void){
    int n;
    scanf("%d",&n);
    Stud studs[100];
    for(int i=0;i<n;i++){
        scanf("%s",&studs[i].name);
        scanf("%d",&studs[i].q_1);
        scanf("%d",&studs[i].q_2);
        scanf("%d",&studs[i].q_3);
        scanf("%d",&studs[i].q_4);
        scanf("%d",&studs[i].q_5);
        scanf("%d",&studs[i].plus);
        studs[i].sum=(studs[i].q_1+studs[i].q_2+studs[i].q_3+studs[i].q_4+studs[i].q_5+studs[i].plus);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(studs[i].sum<studs[j].sum){
                Stud temp=studs[i];studs[i]=studs[j];studs[j]=temp;
            }
            if((studs[i].sum==studs[j].sum) && (studs[i].plus<studs[j].plus)){
                Stud temp=studs[i];studs[i]=studs[j];studs[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s %d %d\n",studs[i].name,studs[i].sum,studs[i].plus);
    }
}