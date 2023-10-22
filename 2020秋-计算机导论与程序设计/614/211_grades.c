#include "stdio.h"

/*
标题
成绩处理

描述
输入5个学生，4门课成绩，二维数组stu[5][4]表示，行标表示学生，列标表示课程成绩，分别编写函数aver()、fals()和well()完成：(1)求第一门课的平均分；(2)统计有2门以上课程不及格的同学人数；(3)平均成绩在90分以上或者全部课程成绩在85分以上的同学视为优秀，统计人数，使用指针完成地址传递，主函数完成数组输入和输出。
   
时间限制
1	

内存限制
10000	

类别
1

输入说明
输入二维浮点型数组stu[5][4]

输出说明
输出第一门课程平均分(保留1位小数)、2门以上不及格人数和成绩优秀人数，数据之间空一格。

输入样例
85 73 59 92
93 95 89 88
86 88 88 87
59 51 52 68
78 32 59 91

输出样例
80.2 2 2

提示
注意行列信息。使用指针完成地址传递，主函数完成数组输入和输出。
*/

/*该学生合格时返回1，不合格返回0*/
int fals(int *p){
    int fail=0,t=0;
    while(t++<4){
        if(*p++<60){//?
            fail++;
        }
    }
    if(fail>=2) return 1;
    else return 0;
}

/*求平均*/
float aver(int *p){
    int res=0,t=0;
    while(t++<4){
        res+=*p++;//?
    }
    return res/t*1.;
}

/*优秀 返回1*/
int well(int *p){
    int is=1,t=0;
    if(aver(p)>=90){
        goto end;
    }
    while(t++<4){
        if(*p++<85){//?
            is=0;
            break;
        }
    }
    end:return is;
}

int main(void){
    int stu[5][4]={0};
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            scanf("%d",&stu[i][j]);
        }
    }
    float aver=0;//平均分(1)
    int fail_guys=0;//两门及以上不及格(2)
    int well_guys=0;//优秀(3)
    for(i=0;i<5;i++){
        aver+=stu[i][0]/5.;//(1)
        if(fals(&stu[i][0])==1){//(2)
            fail_guys++;
        }
        if(well(&stu[i][0])==1){
            well_guys++;
        }
    }
    printf("%.1f %d %d",aver,fail_guys,well_guys);
}