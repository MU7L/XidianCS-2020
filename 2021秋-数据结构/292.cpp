#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
    int value;
    // used in Htree
    Node *root;
    // used in stack
    Node *prior;

    Node(){
        value = 0;
        root = NULL;
        prior = NULL;
    }
    Node(int num){
        value = num;
        root = NULL;
        prior = NULL;
    }
    void setroot(Node *f){
        root = f;
    }
    // get path length of node
    int path(){
        if(root != NULL){
            return root ->path() + 1;
        }
        else{
            return 0;
        }
    }
    int getWpl(){
        int p = path();
        // cout << value << ":\t" << p << endl;                              //test
        return value * p;
    }
    void show(){
        cout << value << " ";
    }
};

class HaffmanTree{
public:
    Node *node[100]; // the maximun size is 100
    int nodeLen = 0;

    HaffmanTree(){
        memset(node, 0, sizeof(node));
        nodeLen = 0;
    }
    void append(Node *n){
        node[nodeLen++] = n;
    }
    int WPL(){
        int wpl = 0;
        for(int i = 0; i < nodeLen; i++){
            wpl += node[i] ->getWpl();
        }
        return wpl;
    }
};

class Stack{
public:
    Node *handle;
    Node *end;

    Stack(){
        handle = new Node();
        end = handle;
    }
    void add(Node *node){
        if(isEmpty() || end ->value >= node ->value){
            node ->prior = end;
            end = node;
            return;
        }
        Node *insert = end;
        while(insert ->prior != handle){
            if(insert ->prior ->value >= node ->value){
                node ->prior = insert ->prior;
                insert ->prior = node;
                return;
            }
            insert = insert ->prior;
        }
        node ->prior = handle;
        insert ->prior = node;
    }
    Node * pop(){
        if(isEmpty()){
            return NULL;
        }
        Node *popNode = end;
        end = end ->prior;
        return popNode;
    }
    bool isEmpty(){
        return handle == end;
    }
    void show(){
        Node *p = end;
        while(p != handle){
            p ->show();
            p = p ->prior;
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]){
    int n, num;
    cin >> n;
    HaffmanTree t;
    Stack s;
    for(int i = 0; i < n; i++){
        cin >> num;
        Node *node = new Node(num);
        t.append(node);
        s.add(node);
        //s.show();                                                            //test
    }
    Node *a, *b;
    int value = 0;
    while(!s.isEmpty()){
        a = s.pop();
        b = s.pop();
        if(a == NULL || b == NULL){
            break;
        }
        value = a ->value + b ->value;
        Node *node = new Node(value);
        a ->setroot(node);
        b ->setroot(node);
        s.add(node);
        //s.show();                                                            //test
    }
    cout << t.WPL() << endl;
    return 0;
}

/*

8
7  19  2  6  32  3  21  10

261

*/