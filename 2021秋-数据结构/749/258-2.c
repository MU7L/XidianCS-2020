#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#define N 100010
struct LNode {
    int idex;//该节点的地址
    int data;//该节点的数据
    int nextidex;//下个节点的地址
    struct LNode* next;
};
typedef struct LNode* List;
int main()
{
    int a[N] = { 0 };//记录地址的data
    int b[N] = { 0 };//记录重复
    int c[N] = { 0 };//记录下一个地址
    int n;//做循环
    int m;//表头
    int zb;//给b数组做定位
    int cb;//给a数组做定位
    int sb;//存data的
    scanf("%d %d", &m, &n);
    int i = 0;
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &zb, &sb, &cb);
        a[zb] = sb;
        c[zb] = cb;
        //    b[abs(sb)]++;
    }
    if (n == 1) {
        printf("%05d %d -1", zb, sb);
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    int aim = m;
    List head, tail, p1, tou, wei;
    //head为去重后的链表，tou为有重复的数字链表
    //tail为去重后链表的尾指针，wei为有重复的数字的链表的尾指针
    head = tail = p1 = tou = wei = NULL;
    for (aim = m; aim != -1; aim = c[aim]) {
        p1 = (List)malloc(sizeof(struct LNode));
        p1->idex = aim;
        p1->data = a[aim];
        p1->nextidex = c[aim];//将该节点的内容扣在结构体上
        if (b[abs(p1->data)]) {
            if (tou == NULL) {
                tou = p1;
            }
            else {
                wei->next = p1;
                wei->nextidex=p1->idex;
            }
            wei = p1;
        }
        else {
            b[abs(p1->data)]++;
            if (head == NULL) {
                head = p1;
            }
            else {
                tail->next = p1;
                tail->nextidex=p1->idex;
            }
            tail = p1;
        }
    }
    List L, l;
    L = head;
    l = L->next;
    while (l) {//输出无重复的链表
        printf("%05d %d %05d\n", L->idex, L->data, L->nextidex);
        L = l;
        l = l->next;
    }
    printf("%05d %d -1\n", L->idex, L->data);
    L=tou;
    l=L->next;
    if (tou) {//输出重复的数字链表
        while (l) {
            printf("%05d %d %05d\n", L->idex, L->data, L->nextidex);
            L = l;
            l = l->next;
        }
        printf("%05d %d -1\n", L->idex, L->data);
    }
}