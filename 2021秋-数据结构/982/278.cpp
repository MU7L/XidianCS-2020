#include <iostream>

using namespace std;

class Node{
public:
    int m_order;
    int m_key;
    Node *next;
    Node(){
        m_order = 0;
        m_key = 0;
        next = NULL;
    }
    Node(int order, int key){
        m_order = order;
        m_key = key;
    }
};

class CircleLinkedList{
public:
    Node *handle;
    int length;
    CircleLinkedList(int keys[], int arrLen){
        handle = new Node();
        Node *end = handle;
        for(int i = 0; i < arrLen; i++){
            end -> next = new Node(i + 1, keys[i]);
            end = end -> next;
        }
        end -> next = handle -> next;
        length = arrLen;
    }
    void deleteNextNode(Node *n){
        Node *delNode = n -> next;
        if(delNode == handle -> next){
            handle -> next = delNode -> next;
        }
        n -> next = delNode -> next;
        delete delNode;
        length--;
    }
    void show(){
        Node *p = handle -> next;
        for(int i = 0; i < length; i++){
            cout << p -> m_order << " : " << p -> m_key << endl;
            p = p -> next;
        }
    }
};

int main(int argc,char* argv[]){
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int numArr[10000] = {0};
    for(int i = 0; i < n; i++){
        cin >> numArr[i];
    }
    CircleLinkedList l(numArr, n);
    Node *p = l.handle -> next; //p指向1号位
    while(l.length != 1){
        if(m == 1){ //调整m，使得多循环一轮，最终p指向待删除结点上一位
            m = l.length + 1;
        }
        for(int i = 1; i < m - 1; i++){
            p = p -> next;
        }
        cout << p -> next -> m_order << " ";
        m = p -> next -> m_key;
        l.deleteNextNode(p);
        p = p -> next;
    }
    cout << p -> m_order << endl;
    return 0;
}