#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

class Node{
public:
    int order;
    long address;
    int key;
    long next;
    int nextOrder;

    Node(long address, int key, long next){
        order = 0;
        nextOrder = 0;
        this ->address = address;
        this ->key = key;
        this ->next = next;
    }
    void show(){
        cout << setfill('0') << setw(5) << address<< ' '
            << key << ' '
            << next
            << endl;
    }
};

class List{
public:
    Node *list[100];
    int start;
    int end;
    long startAdd;
    int length;

    List(long startAdd){
        memset(list, 0, sizeof(list));
        this ->startAdd = startAdd;
        length = 0;
        start = 0;
        end = 0;
    }
    void append(Node *n){
        list[length] = n;
        if(n ->address == startAdd){
            start = length;
        }
        n ->order = length;
        length++;
    }
    void patch(){
        int p = start;
        do{
            for(int i = 0; i < length; i++){
                if(list[i] ->address == list[p] ->next){
                    list[p] ->nextOrder = i;
                    p = i;
                    break;
                }
            }
        }while(list[p] ->next != -1);
        end = p;
        list[end] ->nextOrder = -1;
    }
    void remove(Node *n){
        for(int i = 0; i < length; i++){
            if(list[i] ->nextOrder == n ->order){ //after list[i]
                if(n ->next == -1){ //last one
                    end = i;
                }
                list[i] ->next = n ->next;
                list[i] ->nextOrder = n ->nextOrder;
                break;
            }
        }
        length--;
    }
    void show(){
        int p = start;
        int i = 0;
        do{
            list[p] ->show();
            p = list[p] ->nextOrder;
            i++;
        }while(i <= length);
    }
};

class Iterator{
public:
    Node *node;

    Iterator(List *l){
        node = l ->list[l ->start];
    }
    bool next(List *l){
        /*
        long nextAdd = node ->next;
        if(nextAdd == -1){
            return false;
        }
        for(int i = 0; i < l.length; i++){
            if(l.list[i] ->address == nextAdd){
                node = l.list[i];
                break;
            }
        }
        return true;
        */
        if(node ->nextOrder == -1){
            return false;
        }
        node = l ->list[node ->nextOrder];
        return true;
    }
};

int main(int argc, char* argv[]){
    long start = 0;
    int n = 0;
    cin >> start >> n;
    List l(start);
    long address = 0;
    int key = 0;
    long next = 0;
    for(int i = 0; i < n; i++){
        cin >> address >> key >> next;
        l.append(new Node(address, key, next));
    }
    l.patch();
    int check[100] = {0};
    int checkLen = 0;
    memset(check, 0, sizeof(check));
    Iterator itr(&l);
    bool exist = false;
    do{
        exist = false;
        for(int i = 0; i < checkLen; i++){
            if(check[i] == abs(itr.node ->key)){
                l.remove(itr.node);
                exist = true;
                break;
            }
        }
        if(!exist){
            check[checkLen++] = abs(itr.node ->key);
        }
    }while(itr.next(&l));
    cout << l.length << endl;
    l.show();
    return 0;
}

/*

00100 5
99999 7 87654
23854 -15 00000
87654 -15 -1
00000 15 99999
00100 21 23854

3
00100 21 23854
23854 -15 99999
99999 7 -1

*/