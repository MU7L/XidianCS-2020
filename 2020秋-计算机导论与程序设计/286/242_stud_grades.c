#include "stdio.h"

/*试题名称	成绩统计
时间限制:	1 秒
内存限制:	256KB

问题描述
有N（0<N<=100）个学生，每个学生有3门课的成绩，输入每个学生数据（包括学号，姓名，三门课成绩），计算每个学生的平均成绩，并按照平均成绩从高到低的顺序输出学生信息，平均成绩相同时，则按照学号从小到大顺序输出。

输入说明
第一行输入学生个数N，然后逐行输入N个学生信息，包括学号，姓名，三门课成绩，学号为正整数，姓名不超过10个字符，各门课程成绩为整数,用空格分隔。

输出说明
按照平均成绩由高到低输出学生信息，平均成绩相同时，则按照学号从小到大顺序输出，输出信息包括学号、姓名、平均成绩（保留1位小数），用空格分隔，每个学生信息占一行。

输入样例
6
18001 LiMing 88 45 90
18003 WangWei 66 60 68
18004 ZhangSan 77 90 83
18110 HanMeiMei 88 77 97
18122 SuSan 66 23 87
18008 YangYang 88 76 95

输出样例
18110 HanMeiMei 87.3
18008 YangYang 86.3
18004 ZhangSan 83.3
18001 LiMing 74.3
18003 WangWei 64.7
18122 SuSan 58.7

*/

typedef struct{
    long number;
    char name[10];
    int grade_1;
    int grade_2;
    int grade_3;
    float aver;
}Stud;

int main(void){
    int n;
    scanf("%d",&n);
    Stud studs[100];
    for(int i=0;i<n;i++){
        scanf("%d",&studs[i].number);
        scanf("%s",&studs[i].name);
        scanf("%d",&studs[i].grade_1);
        scanf("%d",&studs[i].grade_2);
        scanf("%d",&studs[i].grade_3);
        studs[i].aver=(studs[i].grade_1+studs[i].grade_2+studs[i].grade_3)/3.;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(studs[i].aver<studs[j].aver){
                Stud temp=studs[i];studs[i]=studs[j];studs[j]=temp;
            }
            if((studs[i].aver==studs[j].aver)&&(studs[i].number>studs[j].number)){
                Stud temp=studs[i];studs[i]=studs[j];studs[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d %s %.1f\n",studs[i].number,studs[i].name,studs[i].aver);
    }
}