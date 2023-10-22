#include "stdio.h"
#define MAXSIZE 100

typedef struct{
    char ch[MAXSIZE+1];
    int length;
}hstring;

void hstring_assgin(hstring *s,char *chs){
    int i = 0;
    while(chs[i]!='\0') {
        s->ch[i]=chs[i];
        i++;
    }
    s->length=i;
}

void get_next(hstring s,int next[]){
    int i=0;
    next[0]=-1;
    int j=-1;
    while (i<s.length){
        if(j==-1||s.ch[i]==s.ch[j]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

int main(){
    int i = 0, j = 0, n;
    char temp[MAXSIZE+1], chs[MAXSIZE+1];
    int next[MAXSIZE];
    scanf("%d\n", &n);
    gets(temp);
    //去除字符串中的空格
    for(i=0; i<2*n-1; i++){
        if(temp[i] != ' '){
            chs[j] = temp[i];
            j++;
        }
    }
    hstring s;
    hstring_assgin(&s,chs);
    get_next(s,next);
    for (i = 0; i <n ;i ++) {
        printf("%d ",next[i]);
    }
    return 0;
}

/*#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

int main(){
    int i = 0, j = 0, n;
    char a[MAXSIZE], p[MAXSIZE];
    int next[MAXSIZE];
    scanf("%d\n", &n);
    gets(a);
    //去除字符串中的空格
    for(i=0; i<2*n-1; i++){
        if(a[i] != ' '){
            p[j] = a[i];
            j++;
        }
    }
    //求next表
    next[0] = -1;
    i = 0;
    j = -1;
    while(i<n){
        if(j==-1 || p[i] == p[j]){
            i++; j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    //输出next表
    for(i=0; i<n; i++){
        printf("%d ", next[i]);
    }
    return 0;
}*/