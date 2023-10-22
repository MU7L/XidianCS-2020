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
};

class LinkedList{
public:
    Node *head; //头节点
    Node *end;
    int length;

    LinkedList(){
        head = new Node(0);
        end = head;
        length = 0;
    }
    LinkedList(int num[], int len){
        head = new Node(0);
        end = head;
        for(int i = 0; i < len; ++i){
            end -> next = new Node(num[i]);
            end = end -> next;
        }
        length = len;
    }
    void append(Node *n){
        end -> next = n;
        end = n;
        length++;
    }
    void show(){
        Node *p = head -> next;
        while(p){
            cout << p -> num << ' ';
            p = p -> next;
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]){
    int len1, len2;
    cin >> len1 >> len2;
    int l1[100], l2[100];
    for(int i = 0; i < len1; i++){
        cin >> l1[i];
    }
    for(int i = 0; i < len2; i++){
        cin >> l2[i];
    }
    LinkedList list1(l1, len1);
    LinkedList list2(l2, len2);
    LinkedList list3;
    Node *p1 = list1.head -> next;
    Node *p2 = list2.head -> next;
    Node *in = NULL;
    // (p1 != NULL) && (p2 != NULL)
    while(p1 && p2){
        if(p1 -> num > p2 -> num){
            in = p2;
            p2 = p2 -> next;
        }
        else if(p1 -> num < p2 -> num){
            in = p1;
            p1 = p1 -> next;
        }
        else{
            in = p2;
            p2 = p2 -> next;
            p1 = p1 -> next;
        }
        if(in -> num != list3.end -> num){
            list3.append(in);
        }
    }
    if(!p1){
        list3.end -> next = p2;
    }
    else{
        list3.end -> next = p1;
    }
    list3.show();
    return 0;
}

/*

6 7
1 2 5 6 10 13
1 3 5 8 19 22 31

1 2 3 5 6 8 10 13 19 22 31

6 6
1 2 5 6 10 13
1 3 5 8 19 22

1 2 3 5 6 8 10 13 19 22

*/