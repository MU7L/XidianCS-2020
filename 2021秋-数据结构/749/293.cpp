#include <iostream>

using namespace std;

class Node{
public:
    int num;
    Node *prior;
    Node *next;
    Node(int n){
        num = n;
        prior = NULL;
        next = NULL;
    }
    void show(){
        cout << num;
    }
};

class DoubleLinkedList{
public:
    Node *handle; //头节点
    Node *end;
    int length;
    DoubleLinkedList(){
        handle = new Node(0);
        end = handle;
        length = 0;
    }
    void append(Node *node){
        end -> next = node;
        node -> prior = end;
        end = node;
        length++;
    }
    void deleteNode(Node *node){
        if(node == end){ //尾结点
            end = end -> prior;
            end -> next = NULL;
        }
        else{
            node -> prior -> next = node -> next;
            node -> next -> prior = node -> prior;
        }
        delete node;
        length--;
    }
    void show(){
        Node *p = handle -> next;
        while(p != end){
            p -> show();
            cout << ' ';
            p = p -> next;
        }
        end -> show();
    }
};

int main(int argc, char* argv[]){
    int n = 0;
    cin >> n;
    DoubleLinkedList l;
    for(int i = 1; i <= n; i++){
        l.append(new Node(i));
    }
    int flag = 1;
    Node *p = NULL;
    while(l.length > 3){
        //选2
        flag = 1;
        p = l.handle -> next;
        while(p){
            if(flag % 2 == 0){
                Node *del = p;
                p = p -> prior;
                l.deleteNode(del);
                /*
                if(l.length <= 3){
                    goto END;
                }
                */
            }
            flag++;
            p = p -> next;
        }
        if(l.length <= 3){
            goto END;
        }
        //选3
        flag = 1;
        p = l.handle -> next;
        while(p){
            if(flag % 3 == 0){
                Node *del = p;
                p = p -> prior;
                l.deleteNode(del);
                /*
                if(l.length <= 3){
                    goto END;
                }
                */
            }
            flag++;
            p = p -> next;
        }
        if(l.length <= 3){
            goto END;
        }
    }
END:
    l.show();
    return 0;
}

/*
20

1 7 19
*/