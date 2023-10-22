#include <iostream>

using namespace std;

class Node{
public:
    int num;
    Node *next;
    Node(int n){
        num = n;
        next = NULL;
    }
    int value(){
        return num;
    }
};

class LinkedList{
public:
    Node *head; //头节点
    Node *end;
    int length;
    LinkedList(int num[], int len){
        head = new Node(0);
        end = head;
        for(int i = 0; i < len; ++i){
            end -> next = new Node(num[i]);
            end = end -> next;
        }
        length = len;
    }
};

class Stack{
public:
    Node *head;
    Node *end;
    Stack(){
        head = new Node(0);
        end = head;
    }
    void push(Node *n){
        end -> next = n;
        end = n;
    }
    void show(){
        Node *p = head -> next;
        while(p != end -> next){
            cout << p -> value() << ' ';
            p = p -> next;
        }
    }
};

int main(int argc, char* argv[]){
    int n; //长度
    cin >> n;
    int a[100] = {0};
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    LinkedList l(a, n);
    Stack even, odd;
    Node *p = l.head;
    while(true){
        p = p -> next;
        if(!p){
            break;
        }
        odd.push(p);
        p = p -> next;
        if(!p){
            break;
        }
        even.push(p);
    }
    odd.show();
    even.show();
    return 0;
}

/*

7
10 2 30 4 50 60 7

10 30 50 7 2 4 60

*/